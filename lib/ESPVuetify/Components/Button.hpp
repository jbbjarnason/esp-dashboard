#pragma once

#include "Types.hpp"
#include "Component.hpp"
#include "GenID.hpp"

namespace ESPVuetify {

class Button {
public:
    Button() = default;
    virtual ~Button() = default;
    void addProp(const std::string& key, const SupportedTypes& value);
    void addEvent(const Callback& cb);
    [[nodiscard]] UUID getID() const noexcept;
private:
    Component base_;
};

}
