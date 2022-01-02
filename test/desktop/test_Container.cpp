#include <gtest/gtest.h>

#include "Container.hpp"
#include "ComponentI.hpp"
#include "mocks/ComponentStub.hpp"

using namespace ESPVuetify;

class Container_test : public ::testing::Test {
public:
    virtual ~Container_test() = default;
    void SetUp() override {
//        gen32 = std::mt19937{ 42 }; // reset random generator, make predictable outcome
    }
    void TearDown() override {
    }
    Container<ComponentI> container_;
};

TEST_F(Container_test, createButton) {
    auto button{ container_.create<ComponentStub>() };
    ASSERT_EQ(1, container_.size());
    button.reset();
    container_.cleanup();
    ASSERT_EQ(true, container_.empty());
}

TEST_F(Container_test, toJson) {
    const auto button{ container_.create<ComponentStub>() };
    const auto j{ nlohmann::json(container_) };
    ASSERT_EQ("[{\"container\":[{\"event\":false,\"id\":4264392720,\"name\":\"stub\",\"props\":null}]}]", j.dump());
}