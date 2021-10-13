#pragma once

#include <type_traits>
#include <string>
#include <variant>
#include <memory>

namespace ESPVuetify {

class Dashboard;
class Tab;

template<typename T>
class Component {
public:
    explicit Component(std::variant<std::weak_ptr<Dashboard>, std::weak_ptr<Tab>>) {

    }
};


}
