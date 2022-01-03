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
    ASSERT_EQ("[[{\"components\":[{\"event\":false,\"id\":949333985,\"name\":\"stub\",\"props\":null}],\"containers\":[{\"components\":null,\"containers\":null,\"id\":2715962298,\"name\":\"v-col\"}],\"id\":545404204,\"name\":\"v-row\"}]]", j.dump());
}
