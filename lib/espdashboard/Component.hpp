#pragma once

#include <type_traits>
#include <string>
#include <utility>
#include <memory>
#include <map>
#include <optional>

#include "json.hpp" // todo handle external dependency differently
#include "Types.hpp"
#include "GenID.hpp"

namespace ESPVuetify {

static void to_json(nlohmann::json& j, const ValueType& v) {
    std::visit([&](auto&& value) {
        j = std::forward<decltype(value)>(value);
    }, v);
}

static void to_json(nlohmann::json& j, const PropType& v) {
    std::visit([&](auto&& value) {
        j = std::forward<decltype(value)>(value);
    }, v);
}

static void from_json(const nlohmann::json& j, PropType& v) {
    v = j.at("value"); // this could callback double as int but does it really matter
}

class Prop {
public:
    Prop() = default;
    explicit Prop(PropType value): value_(std::move(value)) {}
    inline Prop& operator=(const PropType& value) {
        value_ = value;
        return *this;
    }
    inline Prop& operator=(PropType&& value) {
        value_ = value;
        return *this;
    }
    [[nodiscard]] inline const PropType& get() const noexcept {
        return value_;
    }
private:
    PropType value_{};
};

static void to_json(nlohmann::json& j, const Prop& p) {
    to_json(j, p.get());
}

using PropMap = std::map<std::string, Prop>;

static void to_json(nlohmann::json& j, const PropMap& p) {
    nlohmann::json jsonProps;
    for (const auto& prop : p) {
        jsonProps[prop.first] = prop.second;
    }
    j["props"] = jsonProps;
}

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
    inline void propagate(const ValueType& value) const {
        cb_(value);
    }
private:
    Callback cb_{ [](const auto&){} };
};

class Component : public GenID {
public:
    explicit Component() = default;
    void setValue(const ValueType& value) {
        value_ = value;
    }
    void addProp(const std::string& key, const PropType& value) {
        propMap_[key] = value;
    }
    void addEvent(const Callback& cb) {
        event_ = cb;
    }
    [[nodiscard]] const ValueType& getValue() const noexcept {
        return value_;
    }
    [[nodiscard]] const PropType& getProp(const std::string& key) const {
        try {
            return propMap_.at(key).get();
        } catch (const std::out_of_range&) {
            throw std::invalid_argument("Property: \"" + key + "\" not found");
        }
    }
    [[nodiscard]] const PropMap& getPropMap() const noexcept {
        return propMap_;
    }
    [[nodiscard]] const std::optional<Event>& getEvent() const noexcept {
        return event_;
    }
private:
    PropMap propMap_;
    std::optional<Event> event_{ std::nullopt };
    ValueType value_;
};

static void to_json(nlohmann::json& j, const Component& c) {
    to_json(j, c.getPropMap());
    j["event"] = c.getEvent().has_value();
    to_json(j["value"], c.getValue());
    j["id"] = c.getID();
}

}
