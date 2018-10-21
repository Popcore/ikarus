//
// Created by Marco on 14/10/2018.
//

#include "gtest/gtest.h"

TEST(test_1, assert_equality) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}