#pragma once
#include <memory>

namespace ESPVuetify {

class Tab;

class Row: public std::enable_shared_from_this<Row> {
public:
    friend class Tab; // Use Tab class to create a Row

    template<class Component>
    std::shared_ptr<Component> create();

protected:
    Row(std::weak_ptr<Tab>);
    std::weak_ptr<Tab> _tab;

};

}
