#include <gtest/gtest.h>

#include "GenID.hpp"

using namespace ESPVuetify;

TEST(GenID, newID) {
    GenID id1, id2;
    ASSERT_EQ(4161255391, id1.getID());
    ASSERT_EQ(3922919429, id2.getID());
}
