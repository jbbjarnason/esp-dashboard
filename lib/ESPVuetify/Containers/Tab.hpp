#pragma once
#include <memory>

#include "ContainerI.hpp"

namespace ESPVuetify {

class Tab : public ContainerI {
public:
    static constexpr auto name{ "v-tab" };
    [[nodiscard]] std::string_view getName() const noexcept override {
        return name;
    }

};

}
