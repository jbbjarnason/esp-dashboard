#pragma once
#include <random>

#include "json.hpp"

namespace ESPVuetify {

// Using mersenne twister random engine
static std::mt19937 gen32;
using UUID = unsigned long;

class GenID {
public:
    [[nodiscard]] virtual UUID getID() const noexcept {
        return id_;
    }
private:
    UUID id_{ gen32() };
};

static void to_json(nlohmann::json& j, const GenID& genId) {
    j["id"] = genId.getID();
}

}
