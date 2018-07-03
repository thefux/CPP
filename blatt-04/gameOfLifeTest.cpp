/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <stdio.h>
#include <gtest/gtest.h>
#include "gameOfLife.h"

TEST(gameOfLife, aliveNeighbors) {
    actualState[2][2] = 1;                              //    .
    actualState[2][3] = 1;                              //    .
    actualState[2][4] = 1;                              // 0 0 1 0 0
    actualState[3][3] = 1;                              // 0 0 1 1 0
                                                        // 0 0 1 0 0 . .
                                                        // 0 0 0 0 0
                                                        // 0 0 0 0 0
    actualState[20][20] = 1;                            //    .            0
    ASSERT_EQ(3, aliveNeighbors(2, 3));                 //    .          . 0
    ASSERT_EQ(1, aliveNeighbors(2, 1));                 //           0 0 0 1 0 0
    ASSERT_EQ(0, aliveNeighbors(20, 20));               //                 0 .
}

TEST(gameOfLife, updateState) {
    actualState[2][2] = 1;
    actualState[2][3] = 1;
    actualState[2][4] = 1;
    actualState[3][3] = 1;
    actualState[20][20] = 1;
    updateState();
    ASSERT_EQ(1, actualState[2][2]);
    ASSERT_EQ(1, actualState[2][3]);
    ASSERT_EQ(1, actualState[2][4]);
    ASSERT_EQ(0, actualState[20][20]);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
