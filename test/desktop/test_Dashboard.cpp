#include <gtest/gtest.h>

#include "Dashboard.hpp"
#include "mocks/ComponentStub.hpp"

using namespace ESPVuetify;

class Dashboard_test : public ::testing::Test {
public:
    virtual ~Dashboard_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Dashboard dashboard_;
};

TEST_F(Dashboard_test, create) {
    auto tab{ dashboard_.create() };
    auto stub{ tab->create<ComponentStub>() };
    stub->setValue("foo");
    const auto j{ nlohmann::json(dashboard_) };
    ASSERT_EQ("foo", j.dump());
}
