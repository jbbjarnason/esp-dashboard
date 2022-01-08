#pragma once

#include "ComponentI.hpp"

namespace ESPVuetify {

class ComponentStub : public ComponentI {
    static constexpr auto name{ "stub" };
    [[nodiscard]] std::string_view getTagName() const noexcept override {
        return name;
    }
};

}
