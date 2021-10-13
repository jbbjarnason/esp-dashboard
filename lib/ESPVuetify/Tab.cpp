#include "Tab.hpp"
#include "Dashboard.hpp"

using namespace ESPVuetify;

Tab::Tab(std::weak_ptr<Dashboard> dashboard):
_dashboard(std::move(dashboard))
{
}

std::shared_ptr<Tab> Tab::create() {
    auto dashboard = Dashboard::create();
    auto tab = std::shared_ptr<Tab>(new Tab(dashboard));
    return tab;
}

template<class Component>
std::shared_ptr<Component> Tab::create() {
    return std::make_shared<Component>(shared_from_this());
}
