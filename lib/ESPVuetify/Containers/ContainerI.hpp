#pragma once

#include <type_traits>

#include "GenericI.hpp"
#include "Container.hpp"
#include "ComponentI.hpp" // todo: really, there is some flaw with this pattern
#include "GenID.hpp"

namespace ESPVuetify {

class ContainerI : public GenID, public GenericI {
public:
    /// \brief can create any kind of component or any kind of container other than tab
    template<typename T> // Todo: use concept for explicit typename declaration
    std::shared_ptr<T> create() {
        if constexpr (std::is_base_of_v<ContainerI, T>) {
            return containers_.create<T>();
        }
        else if constexpr (std::is_base_of_v<ComponentI, T>) {
            return components_.create<T>();
        }
        else {
            static_assert((false, "invalid typename T"));
        }
    }
    [[nodiscard]] const Container<ContainerI>& getContainers() const noexcept {
        return containers_;
    }
    [[nodiscard]] const Container<ComponentI>& getComponents() const noexcept {
        return components_;
    }

protected:
    Container<ContainerI> containers_;
    Container<ComponentI> components_;
};

static void to_json(nlohmann::json& j, const ContainerI& containerI) {
    nlohmann::json obj;
    to_json(obj["containers"], containerI.getContainers());
    to_json(obj["components"], containerI.getComponents());
    to_json(obj, (const GenericI&) containerI);
    to_json(obj, (const GenID&) containerI);
    j.push_back(obj);
}

}
