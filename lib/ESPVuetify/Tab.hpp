#pragma once
#include <memory>

namespace ESPVuetify {

class Dashboard;

class Tab: public std::enable_shared_from_this<Tab> {
public:
    static std::shared_ptr<Tab> create();

    template<class Component>
    std::shared_ptr<Component> create();

protected:
    Tab(std::weak_ptr<Dashboard>);
    std::weak_ptr<Dashboard> _dashboard;
};

}

int main () {
    std::shared_ptr<ESPVuetify::Dashboard> dash = ESPVuetify::Dashboard::create();
    auto new_tab = dash->create<ESPVuetify::Tab>();
    auto col = new_tab->create<int>();

}