/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include "./gameOfLife.h"
#include <ncurses.h>
// #include <cstring>
#include <math.h>

/* global variable */
bool actualState[MAX_GRID_SIZE][MAX_GRID_SIZE];
bool previousState[MAX_GRID_SIZE][MAX_GRID_SIZE];
bool (*actual)[MAX_GRID_SIZE] = actualState;
bool (*previous)[MAX_GRID_SIZE] = previousState;

bool stop_start;
bool quit;
int processUserInputVariable;

/*[[ initalizeGame */
// __________________________________________________________
void initializeGame(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(false);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    /* initialization of the matrix */
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            actualState[i][j] = 0;
            previousState[i][j] = 0;
        }
    }
    stop_start = false;
    quit = false;
}
/*]]*/

// showState [[
// __________________________________________________________
void showState(void) {
    /* update the grid on the screen */
    for (int i = 0; i <= MAX_GRID_SIZE; i++) {
        for (int j = 0; j <=  MAX_GRID_SIZE; j++) {
            if (actualState[i][j] == true) {
                attron(A_REVERSE);
            }
            mvprintw(j, i, " ");
            attroff(A_REVERSE);
            refresh();
        }
    }
}
/*]]*/

/*[[ updateState */
// __________________________________________________________
void updateState(void) {
/*[[*/
    for (int i = 1; i < MAX_GRID_SIZE - 1; i++) {
        for (int j = 1; j < MAX_GRID_SIZE - 1; j++) {
            // Update cell
            bool cellNextState = actual[i][j];
            if (cellNextState) {
                if (aliveNeighbors(i, j) < 2) {
                    cellNextState = false;
                } else if (aliveNeighbors(i, j) == 2 ||
                        aliveNeighbors(i, j) == 3) {
                    cellNextState = true;
                } else {
                    cellNextState = false;
                }
            } else if (!cellNextState) {
                if (aliveNeighbors(i, j) == 3) {
                    cellNextState = true;
                }
            } else {
                mvprintw(0, 0, "error State");
            }
            previous[i][j] = cellNextState;
        }
    }
/*]]*/
    // copy the actual-state to the previous one
    /* this one way to do it */
    /* 
       i'm not sure if i could use this as solution 
     */
    // ****** memcpy(previous, actual, MAX_GRID_SIZE); *****
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            actual[i][j] = previous[i][j];
        }
    }
}
/*]]*/

/* aliveNeighbors [[*/
// __________________________________________________________
int aliveNeighbors(int x, int y) {
    /* store the number of neighbors */
    int neighbors = 0;

    for (int i = x - 1; i <= x + 1; i += 1) {
        for (int j = y - 1; j <= y + 1; j += 1) {
            // neighbors += actual[i][j];
            if (actual[i][j]) {
                neighbors += 1;
            }
        }
    }
    // delete current cell from neighbors
    neighbors -= actual[x][y];
    return neighbors;
}
/*]]*/

/* processUnderInput [[*/
// __________________________________________________________
int processUnderInput(int key) {
    /* space key to pause the game
       s key just one step takes place
       ESC key finish the game
    */
    MEVENT event;
    /* check mouse-key */
    switch (key) {
        case KEY_MOUSE:
        /* get the action from mouse-click */
        if (getmouse(&event) == OK && (event.bstate & BUTTON1_CLICKED)) {
            /* get the position of the click */
            int x = event.x;
            int y = event.y;
            /* not important: but to check that just coordination 
               inside the grid gone be taken */
            if (x < MAX_GRID_SIZE && y < MAX_GRID_SIZE) {
                /* used to generate the squared shape of the cells */
                actual[x][y] = !actual[x][y];
                showState();

                /* for the case of squared shape */
                // /* just to check */
                // checkX = floor(x / 4);
                // checkY = floor(y / 2);
                // mvprintw(0, 0, "mouse clicked at
                // %ld, %ld\n", checkX, checkY);
                // /* generate the squared shape */
                // for (int i = checkX * 4; i < checkX * 4 +  4; ++i) {
                //    for (int j = checkY * 2; j < checkY * 2 + 2; ++j) {
                //        actual[i][j] = !actual[i][j];
                //    }
                //}
            }
        }
        return 1;
        case 32:
            stop_start = !stop_start;
            return 2;
            break;
        case SCHAR:
            return 3;
            break;
        case ESC:
            // quit = !quit;
            return 4;
            break;
    }
    return 0;
}
/*]]*/
