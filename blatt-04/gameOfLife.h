/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#define MAX_GRID_SIZE 100
#define SCHAR         115
#define ESC           27

extern bool actualState[MAX_GRID_SIZE][MAX_GRID_SIZE];
extern bool previousState[MAX_GRID_SIZE][MAX_GRID_SIZE];

extern bool stop_start;
extern bool quit;
extern int processUserInputVariable;


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

#endif  // GAMEOFLIFE_H_
