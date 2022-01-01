#include <gtest/gtest.h>

#include "Container.hpp"
#include "Button.hpp"

using namespace ESPVuetify;

class Container_test : public ::testing::Test {
public:
    virtual ~Container_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Container container_;
};

TEST_F(Container_test, createButton) {
    auto button{ container_.create<Button>() };
    button.reset();
    container_.cleanup();
}
