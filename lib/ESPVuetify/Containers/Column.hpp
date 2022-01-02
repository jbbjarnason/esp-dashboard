#pragma once
#include <memory>

#include "ContainerI.hpp"

namespace ESPVuetify {

class Column : public ContainerI {
public:
    static constexpr auto name{ "v-col" };
    [[nodiscard]] std::string_view getName() const noexcept override {
        return name;
    }
};

static void to_json(nlohmann::json& j, const Column& column) {
    nlohmann::json obj;

}

}
