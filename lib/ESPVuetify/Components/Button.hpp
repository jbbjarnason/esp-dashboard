#pragma once
#include <memory>
#include "../Types.hpp" // Todo correctly handle private headers

namespace ESPVuetify {

class Component;

class Button {
public:
    explicit Button(std::shared_ptr<Component> base);
    void addProp(const std::string& key, const SupportedTypes& value);
    void addEvent(const Callback& cb);
private:
    std::shared_ptr<Component> base_{ nullptr };
};

}
