#include "Dashboard.hpp"
#include "Tab.hpp"

using namespace ESPVuetify;

Dashboard::Dashboard() {

}

std::shared_ptr<Dashboard> Dashboard::instance() {
    auto instance = _instance.lock();
    if (instance) return instance;
    auto sharedPtr = std::shared_ptr<Dashboard>(new Dashboard());
    _instance = sharedPtr;
    return sharedPtr;
}

std::shared_ptr<Tab> Dashboard::create() const {
    return std::make_shared<Tab>(shared_from_this());
}


