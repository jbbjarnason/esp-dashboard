#include "Button.hpp"
#include "Component.hpp"

using namespace ESPVuetify;

Button::Button(std::shared_ptr<Component> base): base_(base) { }
void Button::addProp(const std::string& key, const SupportedTypes& value) {
    base_->addProp(key, value);
}
void Button::addEvent(const Callback& cb) {
    base_->addEvent(cb);
}