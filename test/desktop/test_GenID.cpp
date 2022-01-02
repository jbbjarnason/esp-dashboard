#include <gtest/gtest.h>

#include "GenID.hpp"

using namespace ESPVuetify;

TEST(GenID, newID) {
    gen32 = std::mt19937{ 42 }; // reset random generator, make predictable outcome

    GenID id1, id2;
    ASSERT_EQ(4112460519, id1.getID());
    ASSERT_EQ(4279768804, id2.getID());
}
