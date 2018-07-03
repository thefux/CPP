/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_


// #define MAX_GRID_SIZE   100
const int MAX_GRID_SIZE = 100;
#define SCHAR           115
#define ESC             27

#include <gtest/gtest.h>

class gameOfLife {
 public:
     /*
      * constructor
      * */
     gameOfLife();
     //
     /* 
      * destructor
      * */
     ~gameOfLife();

     /* 
      * used to initialize the Window
      * */
     void initializeGame(void);

     /* 
      * used to show the actual state of the game
      * */
     void showState(void);

     /* 
      * used to update the State
      * */
     void updateState(void);

     /*
      * update the state of the cell
      * */
     void updateCell(int x, int y);

     /* 
      * gives the number of liven neighbors
      * */
     int aliveNeighbors(int x, int y);

     /* 
      * read user input to choose the right action
      * */
     int processUnderInput(int key);

     /* 
      * play game
      * */
     void play(void);

     /* 
      * clear grid
      * */
     void cleanGrid(void);

     FRIEND_TEST(gameOfLife, aliveNeighbors);
     FRIEND_TEST(gameOfLife, updateState);

 private:
     bool _actualState[MAX_GRID_SIZE][MAX_GRID_SIZE];
     bool _previousState[MAX_GRID_SIZE][MAX_GRID_SIZE];
     bool (*actual)[MAX_GRID_SIZE] = _actualState;
     bool (*previous)[MAX_GRID_SIZE] = _previousState;

     bool _stop_start;
     bool _quit;
     int  _processUserInputVariable;
     int _steps;
};

#endif  // GAMEOFLIFE_H_
