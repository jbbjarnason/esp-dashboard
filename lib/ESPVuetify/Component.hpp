#pragma once

#include <type_traits>
#include <string>
#include <utility>
#include <variant>
#include <memory>
#include <map>

namespace ESPVuetify {

class Prop {
public:
    using T = std::variant<bool, int, double, std::string>;
    Prop() = default;
    explicit Prop(T value): value_(std::move(value)) {}
    inline Prop& operator=(const T& value) {
        value_ = value;
        return *this;
    }
    inline Prop& operator=(T&& value) {
        value_ = value;
        return *this;
    }
    [[nodiscard]] inline const T& get() const {
        return value_;
    }
private:
    T value_;
};

class Props {
public:
    Props() = default;
    /// \throws std::out_of_range
    inline Prop& operator[](std::string&& key) {
        return propMap_.at(key);
    }
private:
    std::map<std::string, Prop> propMap_;
};

class Event {
public:
    Event() = default;

};



class Dashboard;
class Tab;

template<typename T>
class Component {
public:
    explicit Component(std::variant<std::weak_ptr<Dashboard>, std::weak_ptr<Tab>>) {

    }
};


}
