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
    ASSERT_EQ(1, container_.size());
    button.reset();
    container_.cleanup();
    ASSERT_EQ(true, container_.empty());
}

TEST_F(Container_test, toJson) {
    const auto button{ container_.create<Button>() };
    const auto j{ nlohmann::json(container_) };
    ASSERT_EQ("[{\"container\":[{\"event\":false,\"id\":581869302,\"name\":\"v-btn\",\"props\":null}]}]", j.dump());
}