#pragma once
#include <memory>
#include <map>

#include "json.hpp"
#include "GenID.hpp"

namespace ESPVuetify {

/// \brief allowed typenames are ComponentI and ContainerI
template<typename T>
class Container : public GenID {
public:
    /// \brief create a derived type of T and keep weak reference to it
    template<typename Derived> // Todo: use enable_if
    std::shared_ptr<Derived> create() {
        auto child{ std::make_shared<Derived>() };
        child->setOnDestruct([this]() {
            cleanup();
        });
        items_.push_back(child);
        return child;
    }

    void cleanup() {
        // Make sure we won't end up with dangling references in our map
        items_.erase(std::remove_if(items_.begin(), items_.end(), [](const auto& ptr) { return ptr.expired(); }), items_.end());
    }

    [[nodiscard]] bool empty() const noexcept {
        return items_.empty();
    }

    [[nodiscard]] size_t size() const noexcept {
        return items_.size();
    }

    [[nodiscard]] auto begin() const noexcept {
        return items_.begin();
    }

    [[nodiscard]] auto end() const noexcept {
        return items_.end();
    }

private:
    std::vector<std::weak_ptr<T>> items_;
};

template<typename T>
static void to_json(nlohmann::json& j, const Container<T>& c) {
    for (const auto& ptr : c) {
        if (auto component{ ptr.lock() }) {
            to_json(j, *component);
        }
    }
}

}