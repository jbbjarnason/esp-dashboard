#include <gtest/gtest.h>

#include "Tab.hpp"
#include "mocks/ComponentStub.hpp"

using namespace ESPVuetify;

class Tab_test : public ::testing::Test {
public:
    virtual ~Tab_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Tab tab_;
};

TEST_F(Tab_test, createButton) {
    auto button{ tab_.create<ComponentStub>() };

}
