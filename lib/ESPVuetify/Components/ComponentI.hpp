#pragma once
#include <string>
#include <string_view>

#include "json.hpp"

#include "GenericI.hpp"
#include "Types.hpp"
#include "GenID.hpp"
#include "Component.hpp"

namespace ESPVuetify {

class ComponentI : public GenericI {
public:
    void setValue(const ValueType& value) {
        base_.setValue(value);
    }
    void addProp(const std::string& key, const PropType& value) {
        base_.addProp(key, value);
    }
    void addEvent(const Callback& cb) {
        base_.addEvent(cb);
    }
//    [[nodiscard]] virtual UUID getID() const noexcept {
//        return base_.getID();
//    }
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
