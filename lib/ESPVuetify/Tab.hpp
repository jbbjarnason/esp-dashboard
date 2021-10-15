#pragma once
#include <memory>

namespace ESPVuetify {

class Dashboard;

class Tab: public std::enable_shared_from_this<Tab> {
public:
    explicit Tab();

    template<class Component>
    std::shared_ptr<Component> create();

protected:
    std::weak_ptr<Dashboard> _dashboard;
};

}
