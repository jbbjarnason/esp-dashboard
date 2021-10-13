#include <gtest/gtest.h>

#define protected public
#include <ESPVuetify/Row.hpp>
#undef protected

using namespace ESPVuetify;

class Row_test: public ::testing::Test {
protected:
    void SetUp() override {
        _row = Row::create();
    }
    void TearDown() override {

    }
    std::shared_ptr<Row> _row;
};

TEST_F(Row_test, createTestObj) {
    ASSERT_TRUE(_row);
}
//TEST_F(Row_test, doesNotKeepDashboardRef) {
//    ASSERT_TRUE(_row->_dashboard.expired());
//}
