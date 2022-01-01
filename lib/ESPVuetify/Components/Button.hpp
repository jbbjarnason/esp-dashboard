#pragma once

#include "Types.hpp"
#include "Component.hpp"
#include "GenID.hpp"

namespace ESPVuetify {

class Button : public GenID {
public:
    Button() = default;
    virtual ~Button() = default;
    void addProp(const std::string& key, const SupportedTypes& value);
    void addEvent(const Callback& cb);
private:
    Component base_;
};

}
