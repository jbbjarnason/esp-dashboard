#pragma once

#include <type_traits>

#include "Container.hpp"
#include "ComponentI.hpp" // todo: really, there is some flaw with this pattern

namespace ESPVuetify {

class ContainerI {
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

protected:
    Container<ContainerI> containers_;
    Container<ComponentI> components_;
};

}
