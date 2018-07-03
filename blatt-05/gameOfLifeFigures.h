/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#ifndef GAMEOFLIFEFIGURES_H_
#define GAMEOFLIFEFIGURES_H_

#include "./gameOfLife.h"

class gameOfLifeFigures {
 public:
     friend class gameOfLife;
     gameOfLifeFigures(int x, int y);
     // void mixSchapeWithinTheGrid(bool *grid[MAX_GRID_SIZE]);
     // bool* getShape(int whichShape);
     // bool** getShape(int whichShape);

 private:
     /* x and y coordination for the new shape */
     int _x;
     int _y;

     bool acornShape[7][3];
     bool theRPentomino[3][3];
     bool lightWeightSpaceship[5][4];
};
#endif  // GAMEOFLIFEFIGURES_H_
