/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <gtest/gtest.h>
#include "Ncurses.h"
#include <ncurses.h>

// _______________________________________________
TEST(Ncurses, moveBall) {
    EXPECT_NEAR(-1.8, moveBall(KEY_UP), 0.01);
    ASSERT_EQ(2.5, moveBall(KEY_DOWN));
    ASSERT_EQ(speedy, moveBall(KEY_LEFT));
    ASSERT_EQ(speedy, moveBall(KEY_RIGHT));
}

// _______________________________________________
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
