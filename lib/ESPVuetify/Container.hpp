#pragma once
#include <vector>
#include <any>
#include <memory>
#include <algorithm>
#include <variant>
#include <type_traits>

#include "GenID.hpp"

namespace ESPVuetify {

class Container : public GenID {
public:
    /// \brief create a Tab/Column/Row/Component
    template<typename T>
    std::shared_ptr<T> create() {
        auto child{ std::make_shared<T>() };
        childrens_[child->getID()] = child;
        return child;
    }

    void cleanup() {
        // Make sure we won't end up with dangling references in our map
        for(auto iter{ childrens_.begin() }; iter != childrens_.end(); ) {
            if (iter->second.expired()) {
                iter = childrens_.erase(iter);
            } else {
                ++iter;
            }
        }
    }

private:
    std::map<UUID, std::weak_ptr<void>> childrens_;
};

}