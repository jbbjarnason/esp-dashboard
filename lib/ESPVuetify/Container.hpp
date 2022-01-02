#pragma once
#include <memory>
#include <map>

#include "json.hpp"
#include "GenID.hpp"
#include "ComponentI.hpp"

namespace ESPVuetify {

class Container : public GenID {
public:
    /// \brief create a Tab/Column/Row/Component
    template<typename T>
    std::shared_ptr<T> create() {
        auto child{ std::make_shared<T>() };
        childrens_.push_back(child);
        return child;
    }

    void cleanup() {
        // Make sure we won't end up with dangling references in our map
        childrens_.erase(std::remove_if(childrens_.begin(), childrens_.end(), [](const auto& ptr) { return ptr.expired(); }), childrens_.end());
    }

    [[nodiscard]] bool empty() const noexcept {
        return childrens_.empty();
    }

    [[nodiscard]] size_t size() const noexcept {
        return childrens_.size();
    }

    [[nodiscard]] auto begin() const noexcept {
        return childrens_.begin();
    }

    [[nodiscard]] auto end() const noexcept {
        return childrens_.end();
    }

private:
    std::vector<std::weak_ptr<ComponentI>> childrens_;
};

static void to_json(nlohmann::json& j, const Container& c) {
    nlohmann::json arr;
    for (const std::weak_ptr<ComponentI>& ptr : c) {
        if (auto component{ ptr.lock() }) {
            to_json(arr, *component);
        }
    }
    j["container"] = arr;
}

}