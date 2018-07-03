/*
 * copyright Abderrahmen Rakez
 *              
 * */

#include <iostream>
#include "gtest/gtest.h"
#include "./approximationEulersNumber.h"

TEST(approximationEulersNumber, approximationEulersumber) {
    approximationEulersNumber approx;
    EXPECT_NEAR(2.66666667, approx.approximationEulerNumber(3), 1e-8);
    EXPECT_NEAR(2.7182818284589949, approx.approximationEulerNumber(15), 1e-16);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
