#pragma once

#include <type_traits>
#include <string>
#include <utility>
#include <memory>
#include <map>
#include <optional>

#include "json.hpp" // todo handle external dependency differently
#include "Types.hpp"


namespace ESPVuetify {

class Prop {
public:
    Prop() = default;
    explicit Prop(SupportedTypes value): value_(std::move(value)) {}
    inline Prop& operator=(const SupportedTypes& value) {
        value_ = value;
        return *this;
    }
    inline Prop& operator=(SupportedTypes&& value) {
        value_ = value;
        return *this;
    }
    [[nodiscard]] inline const SupportedTypes& get() const {
        return value_;
    }
    template<typename T>
    const T& get() const {
        // Todo: refactor using fold expressions
        if (std::holds_alternative<bool>(value_)) {
            return std::get<bool>(value_);
        }
        if (std::holds_alternative<int>(value_)) {
            return std::get<int>(value_);
        }
        if (std::holds_alternative<double>(value_)) {
            return std::get<double>(value_);
        }
        if (std::holds_alternative<std::string>(value_)) {
            return std::get<std::string>(value_);
        }
    }
private:
    SupportedTypes value_{};
};

class Props {
public:
    Props() = default;
    /// \throws std::out_of_range
    inline Prop& operator[](std::string&& key) {
        return propMap_.at(key);
    }
    /// \throws std::out_of_range
    inline Prop& operator[](const std::string& key) {
        return propMap_.at(key);
    }
private:
    std::map<std::string, Prop> propMap_;
};

class Event {
public:
    Event() = default;
    explicit Event(Callback cb): cb_(std::move(cb)) {}
    inline Event& operator=(const Callback& cb) {
        cb_ = cb;
        return *this;
    }
    inline Event& operator=(Callback&& cb) {
        cb_ = cb;
        return *this;
    }
    inline void propagate(const SupportedTypes& value) {
        cb_(value);
    }
private:
    Callback cb_{ [](const auto&){} };
};

void to_json(nlohmann::json& j, const SupportedTypes& value) {
    if (std::holds_alternative<int>(value))
    j = nlohmann::json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
}

void from_json(const json& j, person& p) {
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("age").get_to(p.age);
}

class Tab;

class Component {
public:
    explicit Component(std::weak_ptr<Tab> tab): tab_(std::move(tab)) { }
    void addProp(const std::string& key, const SupportedTypes& value) {
        propMap_[key] = value;
    }
    void addEvent(const Callback& cb) {
        event_ = cb;
    }
    nlohmann::json render(const std::string& componentName) {
        nlohmann::json j = propMap_;
        return {
            { "name", componentName },
            { "props", propMap_ }
        };
    }
private:
    std::weak_ptr<Tab> tab_;
    std::map<std::string, SupportedTypes> propMap_;
//    Props props_{};
    std::optional<Event> event_{ std::nullopt };
};

}
