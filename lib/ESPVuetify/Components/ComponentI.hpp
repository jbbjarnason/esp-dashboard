#pragma once
#include <string_view>

#include "Types.hpp"
#include "GenID.hpp"
#include "Component.hpp"

namespace ESPVuetify {

class ComponentI {
public:
    void addProp(const std::string& key, const SupportedTypes& value) {
        base_.addProp(key, value);
    }
    void addEvent(const Callback& cb) {
        base_.addEvent(cb);
    }
    [[nodiscard]] UUID getID() const noexcept  {
        return base_.getID();
    }
    [[nodiscard]] virtual std::string_view getName() const noexcept = 0;

    [[nodiscard]] const Component& getBase() const noexcept {
        return base_;
    }
private:
    Component base_;
};

static void to_json(nlohmann::json& j, const ComponentI& componentI) {
    nlohmann::json obj;
    to_json(obj, componentI.getBase());
    obj["name"] = componentI.getName();
    j.push_back(obj);
}

}
