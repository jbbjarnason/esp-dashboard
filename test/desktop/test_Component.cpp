#include <gtest/gtest.h>

#include "Component.hpp"

using namespace ESPVuetify;

class Component_test: public ::testing::Test {
public:
    virtual ~Component_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Component component_;
};

TEST_F(Component_test, addProperty) {
    component_.addProp("foo", "bar");
    ASSERT_EQ(SupportedTypes ("bar"),component_.getProp("foo"));
}
TEST_F(Component_test, throwOnNotFoundProperty) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    EXPECT_THROW(component_.getProp("foo"), std::invalid_argument);
#pragma GCC diagnostic pop
}
TEST_F(Component_test, toJson) {
    component_.addProp("foo", "bar");
    component_.addProp("bar", 42);
    component_.addProp("hello", 4.2);
    component_.addProp("world", true);
    auto j{ nlohmann::json(component_) };
    ASSERT_EQ("[{\"event\":false,\"id\":3890346734,\"props\":{\"bar\":{\"value\":42},\"foo\":{\"value\":\"bar\"},\"hello\":{\"value\":4.2},\"world\":{\"value\":true}}}]", j.dump());
}