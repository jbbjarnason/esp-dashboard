#include "Dashboard.hpp"

using namespace ESPVuetify;

Dashboard::Dashboard() {

}

std::shared_ptr<Dashboard> Dashboard::create() {
    auto instance = _instance.lock();
    if (instance) return instance;
    auto sharedPtr = std::shared_ptr<Dashboard>(new Dashboard());
    _instance = sharedPtr;
    return sharedPtr;
}

template<class Component>
std::shared_ptr<Component> Dashboard::create() {
    return std::make_shared<Component>(shared_from_this());
}


