#pragma once
#include <memory>
#include "Container.hpp"
#include "Tab.hpp"

namespace ESPVuetify {

/**
*  @brief Dashboard main class, parent of all containers and widgets.
*/
class Dashboard {
public:
    std::shared_ptr<Tab> create() {
        return tabs_.create<Tab>();
    }
    const Container<Tab>& getTabs() const noexcept {
        return tabs_;
    }
private:
    Container<Tab> tabs_;
};

static void to_json(nlohmann::json& j, const Dashboard& dashboard) {
    to_json(j, dashboard.getTabs());
}

}
