#pragma once
#include <vector>
#include <any>
#include <memory>
#include <algorithm>
#include <variant>
#include <type_traits>



namespace ESPVuetify {

class Button;

class Container {
public:
    /// \brief create a Tab/Column/Row/Component
    template<typename T>
    std::shared_ptr<T> create() {
        auto children{ std::make_shared<T> };
        childrens_.push_back(children);
        return children;
    }

    /// \brief get the Tab/Column/Row/Component from given unique id
    template<typename T>
    const std::shared_ptr<T>& get(uint32_t id) {
        // Make sure we won't end up with dangling references in our vector
        childrens_.erase(std::remove_if(childrens_.begin(), childrens_.end(),
                                        [](const std::weak_ptr<std::any> &children) { return children.expired(); }),
                         childrens_.end());

        for (const auto& children : childrens_) {
            if (const auto childrenLocked{ children.lock() }) {
                std::visit([](auto&& arg) {
                    using Type = std::decay_t<decltype(arg)>;
                    if constexpr (std::is_same_v<Type, Button>) {

                    }
                    else {
                        static_assert((false, "non-exhaustive visitor!"));
                    }
                }, *childrenLocked);
            }
        }
    }

    private:
    std::vector<std::weak_ptr<std::any>> childrens_;
};

}