#pragma once
#include <memory>
#include "Container.hpp"

namespace ESPVuetify {

class Tab;

/**
*  @brief Dashboard main class, parent of all containers and widgets.
*/
class Dashboard: std::enable_shared_from_this<Dashboard> {
public:
    inline static std::shared_ptr<Dashboard> instance();

    std::shared_ptr<Tab> create() const;

protected:
    Dashboard();
    Container container_;
    inline static std::weak_ptr<Dashboard> _instance;
};

}
