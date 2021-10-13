#pragma once
#include <memory>

namespace ESPVuetify {

class Tab;

class Dashboard: std::enable_shared_from_this<Dashboard> {
public:
    static std::shared_ptr<Dashboard> create();

    std::shared_ptr<Tab> create();

protected:
    Dashboard();

    inline static std::weak_ptr<Dashboard> _instance;
};

}
