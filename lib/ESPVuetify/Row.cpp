#include "Row.hpp"

#include <utility>
#include "Tab.hpp"

using namespace ESPVuetify;

Row::Row(std::weak_ptr<Tab> tab):
_tab(std::move(tab))
{
}

template<class Component>
std::shared_ptr<Component> Row::create() {
    return std::make_shared<Component>(shared_from_this());
}
