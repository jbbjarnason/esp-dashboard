#include "Tab.hpp"
#include "Dashboard.hpp"

using namespace ESPVuetify;

Tab::Tab():
_dashboard(Dashboard::instance())
{
}

template<class Component>
std::shared_ptr<Component> Tab::create() {
    return std::make_shared<Component>(shared_from_this());
}
