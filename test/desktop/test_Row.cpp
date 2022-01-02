#include <gtest/gtest.h>

#include "Row.hpp"
#include "mocks/ComponentStub.hpp"

using namespace ESPVuetify;

class Row_test : public ::testing::Test {
public:
    virtual ~Row_test() = default;
    void SetUp() override {
    }
    void TearDown() override {
    }
    Row row_;
};

TEST_F(Row_test, createButton) {
    auto button{ row_.create<ComponentStub>() };
}
