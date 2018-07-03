/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include "./gameOfLifeFigures.h"
#include <ncurses.h>

gameOfLifeFigures::gameOfLifeFigures(int x, int y) :
                                      _x(x), _y(y) {
    acornShape[0][2] = 1;
    acornShape[1][0] = 1;
    acornShape[1][2] = 1;
    acornShape[3][1] = 1;
    acornShape[4][2] = 1;
    acornShape[5][2] = 1;
    acornShape[6][2] = 1;

    theRPentomino[0][1] = 1;
    theRPentomino[1][0] = 1;
    theRPentomino[1][1] = 1;
    theRPentomino[1][2] = 1;
    theRPentomino[2][0] = 1;

    lightWeightSpaceship[0][0] = 1;
    lightWeightSpaceship[0][1] = 1;
    lightWeightSpaceship[0][2] = 1;
    lightWeightSpaceship[1][0] = 1;
    lightWeightSpaceship[2][0] = 1;
    lightWeightSpaceship[3][0] = 1;
    lightWeightSpaceship[4][1] = 1;
    lightWeightSpaceship[4][3] = 1;
    lightWeightSpaceship[1][3] = 1;
}
