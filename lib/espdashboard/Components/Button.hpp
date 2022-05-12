#pragma once

#include "ComponentI.hpp"

namespace ESPVuetify {

class Button : public ComponentI {
public:
    static constexpr auto name{ "v-btn" };
    [[nodiscard]] std::string_view getTagName() const noexcept override {
        return name;
    }
};

}
