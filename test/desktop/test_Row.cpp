#include <gtest/gtest.h>

#include "Row.hpp"
#include "Column.hpp"
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

TEST_F(Row_test, createStub) {
    auto stub{ row_.create<ComponentStub>() };
    auto column{ row_.create<Column>() };
    const auto j{ nlohmann::json(row_) };
    ASSERT_EQ("foo", j.dump());
}
