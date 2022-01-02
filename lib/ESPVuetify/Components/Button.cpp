#include "Button.hpp"
#include "Component.hpp"

using namespace ESPVuetify;

void Button::addProp(const std::string& key, const SupportedTypes& value) {
    base_.addProp(key, value);
}
void Button::addEvent(const Callback& cb) {
    base_.addEvent(cb);
}
UUID Button::getID() const noexcept {
    return base_.getID();
}
