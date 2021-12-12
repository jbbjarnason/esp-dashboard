#include <gtest/gtest.h>

#define protected public
#include "ESPVuetify/Dashboard.hpp"
#undef protected

using namespace ESPVuetify;

class Dashboard_test: public ::testing::Test {
protected:
    void SetUp() override {
        _dash = Dashboard::instance();
    }
    void TearDown() override {

    }
    std::shared_ptr<Dashboard> _dash;
};

TEST_F(Dashboard_test, singleton) {
    ASSERT_TRUE(Dashboard::_instance.lock());
    _dash.reset();
    ASSERT_TRUE(Dashboard::_instance.expired());
}
