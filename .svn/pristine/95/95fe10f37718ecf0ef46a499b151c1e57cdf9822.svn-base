/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <ncurses.h>
#include <math.h>
#include "./gameOfLifeFigures.h"
#include "./gameOfLife.h"
// #include <cstring>

/* constructor [[*/
// __________________________________________________________
gameOfLife::gameOfLife() {
    for (int i = 0; i < MAX_GRID_SIZE; ++i) {
        for (int j = 0; j < MAX_GRID_SIZE; ++j) {
            _actualState[i][j] = 0;
            _previousState[i][j] = 0;
        }
    }
    // _actualState[20][8]  = 1;
    // _actualState[20][9]  = 1;
    // _actualState[20][10] = 1;
    // _actualState[20][11] = 1;
    // _actualState[20][12] = 1;

    // _actualState[20][15] = 1;
    // _actualState[20][16] = 1;
    // _actualState[20][17] = 1;
    // _actualState[20][18] = 1;
    // _actualState[20][19] = 1;

    _stop_start = false;
    _quit = false;
    _processUserInputVariable = 0;
    _steps = 0;
}

/*]]*/

/* destructor [[*/
// __________________________________________________________
gameOfLife::~gameOfLife() {
    // clean up
    endwin();
}
/*]]*/

/*[[ initalizeGame */
// __________________________________________________________
void gameOfLife::initializeGame() {
    initscr();
    cbreak();
    noecho();
    curs_set(false);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
}
/*]]*/

// showState [[
// __________________________________________________________
void gameOfLife::showState(void) {
    /* update the grid on the screen */
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j <  MAX_GRID_SIZE; j++) {
            if (_actualState[i][j] == true) {
                attron(A_REVERSE);
            }
            mvprintw(j, i, " ");
            attroff(A_REVERSE);
        }
    }
    mvprintw(0, 0, "steps: %d", _steps);
    /* debug */
    // gameOfLifeFigures game(30, 30);
    // mvprintw(1, 0, "coordination %d, %d", sizeof(game.acornShape) /
    // sizeof(game.acornShape[0]), sizeof(game.acornShape[0]) /
    // sizeof(game.acornShape[0][0]));
    // mvprintw(2, 0, "coordination %d, %d", sizeof(game.theRPentomino) /
    // sizeof(game.theRPentomino[0]), sizeof(game.theRPentomino[0]) /
    // sizeof(game.theRPentomino[0][0]));
    // mvprintw(3, 0, "coordination %d, %d", sizeof(game.lightWeightSpaceship)
    // / sizeof(game.lightWeightSpaceship[0]), sizeof
    // (game.lightWeightSpaceship[0])
    // / sizeof(game.lightWeightSpaceship[0][0]));
    refresh();
}
/*]]*/

/*[[ updateState */
// __________________________________________________________
void gameOfLife::updateState(void) {
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
    // memcpy(previous, actual, MAX_GRID_SIZE);
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            actual[i][j] = previous[i][j];
        }
    }
}
/*]]*/

/* aliveNeighbors [[*/
// __________________________________________________________
int gameOfLife::aliveNeighbors(int x, int y) {
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
int gameOfLife::processUnderInput(int key) {
    gameOfLifeFigures game(50, 20);
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
            _stop_start = !_stop_start;
            return 2;
            break;
        case 'c':
            /* clear screen */
            cleanGrid();
            return 3;
            break;
        case 's':
            return 5;
            break;
        case 27:
            // quit = !quit;
            return 4;
            break;
        case 'a':
            /* clear screen */
            cleanGrid();

            actual[game._x][game._y + 2] = game.acornShape[0][2];
            actual[game._x + 1][game._y + 0] = game.acornShape[1][0];
            actual[game._x + 1][game._y + 2] = game.acornShape[1][2];
            actual[game._x + 3][game._y + 1] = game.acornShape[3][1];
            actual[game._x + 4][game._y + 2] = game.acornShape[4][2];
            actual[game._x + 5][game._y + 2] = game.acornShape[5][2];
            actual[game._x + 6][game._y + 2] = game.acornShape[6][2];
            return 0;
            break;

        case 'p':
            cleanGrid();
            actual[game._x][game._y + 1] = game.theRPentomino[0][1];
            actual[game._x + 1][game._y] = game.theRPentomino[1][0];
            actual[game._x + 1][game._y + 1] = game.theRPentomino[1][1];
            actual[game._x + 1][game._y + 2] = game.theRPentomino[1][2];
            actual[game._x + 2][game._y] = game.theRPentomino[2][0];
            return 0;
            break;

       case 'l':
            cleanGrid();
            actual[game._x][game._y] = game.lightWeightSpaceship[0][0];
            actual[game._x][game._y + 1] = game.lightWeightSpaceship[0][1];
            actual[game._x][game._y + 2] = game.lightWeightSpaceship[0][2];
            actual[game._x + 1][game._y] = game.lightWeightSpaceship[1][0];
            actual[game._x + 2][game._y] = game.lightWeightSpaceship[2][0];
            actual[game._x + 3][game._y] = game.lightWeightSpaceship[3][0];
            actual[game._x + 4][game._y + 1] = game.lightWeightSpaceship[4][1];
            actual[game._x + 4][game._y + 3] = game.lightWeightSpaceship[4][3];
            actual[game._x + 1][game._y + 3] = game.lightWeightSpaceship[1][3];
            return 0;
            break;
    }
    return 0;
}
/*]]*/

/* play [[*/
// __________________________________________________________
void gameOfLife::play(void) {
    while (!_quit) {
        int key = getch();
        _processUserInputVariable = processUnderInput(key);
        // check
        // mvprintw(0, 20, "processUserInputVariable: %d"
        //         , key);

        // play non stop as the condition is true
        while (!_stop_start) {
            key = getch();
            _processUserInputVariable = processUnderInput(key);
            usleep(1000 * 100);
            _steps++;
            updateState();
            showState();
            // pause game
            if (_processUserInputVariable == 2) {
                _stop_start = !_stop_start;
                break;
            }
            if (_processUserInputVariable == 4) {
                _quit = !_quit;
                break;
            }
        }

        // quit game
        if (_processUserInputVariable == 4) {
            _quit = !_quit;
            break;
        }

        switch (_processUserInputVariable) {
            case 2:
                // go back after pause
                _stop_start = !_stop_start;
                break;
            case 5:
                // one step update
                _steps++;
                updateState();
                showState();
                break;
        }
    }
}
/*]]*/

/* cleanGrid[[*/
// __________________________________________________________
void gameOfLife::cleanGrid(void) {
    for (int i = 0; i < MAX_GRID_SIZE; ++i) {
        for (int j = 0; j < MAX_GRID_SIZE; ++j) {
            actual[i][j] = 0;
        }
    }
}/*]]*/
