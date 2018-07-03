/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <stdio.h>
#include <gtest/gtest.h>
#include "gameOfLife.h"

TEST(gameOfLife, aliveNeighbors) {
    gameOfLife life;
    life._actualState[2][2] = 1;                    //    .
    life._actualState[2][3] = 1;                    //    .
    life._actualState[2][4] = 1;                    // 0 0 1 0 0
    life._actualState[3][3] = 1;                    // 0 0 1 1 0
                                                    // 0 0 1 0 0 . .
                                                    // 0 0 0 0 0
                                                    // 0 0 0 0 0
    life._actualState[20][20] = 1;                  //    .            0
    ASSERT_EQ(3, life.aliveNeighbors(2, 3));        //    .          . 0
    ASSERT_EQ(1, life.aliveNeighbors(2, 1));        //           0 0 0 1 0 0
    ASSERT_EQ(0, life.aliveNeighbors(20, 20));      //                 0 .
}

TEST(gameOfLife, updateState) {
    gameOfLife life;
    life._actualState[2][2] = 1;
    life._actualState[2][3] = 1;
    life._actualState[2][4] = 1;
    life._actualState[3][3] = 1;
    life._actualState[20][20] = 1;
    life.updateState();
    ASSERT_EQ(1, life._actualState[2][2]);
    ASSERT_EQ(1, life._actualState[2][4]);
    ASSERT_EQ(0, life._actualState[20][20]);
}

TEST(gameOfLife, processUnderInput) {
    gameOfLife life;
    ASSERT_EQ(2, life.processUnderInput(32));
    ASSERT_EQ(3, life.processUnderInput('c'));
    ASSERT_EQ(4, life.processUnderInput(27));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
