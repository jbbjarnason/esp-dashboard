#include <gtest/gtest.h>

#define protected public
#include "ESPVuetify/Component.hpp"
#undef protected

using namespace ESPVuetify;

class Component_test: public ::testing::Test {
protected:
    void SetUp() override {
        _component = Component::create();
    }
    void TearDown() override {

    }
    std::shared_ptr<Component> _component;
};

TEST_F(Component_test, created) {

}
