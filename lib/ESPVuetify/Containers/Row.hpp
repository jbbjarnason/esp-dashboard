#pragma once
#include <memory>

#include "ContainerI.hpp"

namespace ESPVuetify {

class Row : public ContainerI {
public:
    static constexpr auto name{ "v-row" };
    [[nodiscard]] std::string_view getTagName() const noexcept override {
        return name;
    }

protected:

};

}
