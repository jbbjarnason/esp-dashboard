#include <gtest/gtest.h>

#include "Row.hpp"
#include "mocks/ComponentStub.hpp"

using namespace ESPVuetify;

class Column_test : public ::testing::Test {
public:
    virtual ~Column_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Row row_;
};

TEST_F(Column_test, createButton) {
    auto button{ row_.create<ComponentStub>() };
}
