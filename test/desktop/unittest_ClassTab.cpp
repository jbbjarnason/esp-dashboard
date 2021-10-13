#include <gtest/gtest.h>

#define protected public
#include <ESPVuetify/Tab.hpp>
#undef protected

using namespace ESPVuetify;

class Tab_test: public ::testing::Test {
protected:
    void SetUp() override {
        _tab = Tab::create();
    }
    void TearDown() override {

    }
    std::shared_ptr<Tab> _tab;
};

TEST_F(Tab_test, createTestObj) {
    ASSERT_TRUE(_tab);
}
TEST_F(Tab_test, doesNotKeepDashboardRef) {
    ASSERT_TRUE(_tab->_dashboard.expired());
}
