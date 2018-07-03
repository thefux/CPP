/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include "gameOfLife.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main(void) {
    initializeGame();

    actualState[20][8]  = 1;
    actualState[20][9]  = 1;
    actualState[20][10] = 1;
    actualState[20][11] = 1;
    actualState[20][12] = 1;

    actualState[20][15] = 1;
    actualState[20][16] = 1;
    actualState[20][17] = 1;
    actualState[20][18] = 1;
    actualState[20][19] = 1;

    while (!quit) {
        int key = getch();
        processUserInputVariable = processUnderInput(key);
        // check
        // mvprintw(0, 20, "processUserInputVariable: %d"
        //         , key);

        // play non stop as the condition is true
        while (!stop_start) {
            key = getch();
            processUserInputVariable = processUnderInput(key);
            usleep(1000 * 150);
            updateState();
            showState();
            // pause game
            if (processUserInputVariable == 2) {
                stop_start = !stop_start;
                break;
            }
            if (processUserInputVariable == 4) {
                quit = !quit;
                break;
            }
        }

        // quit game
        if (processUserInputVariable == 4) {
            quit = !quit;
            break;
        }

        switch (processUserInputVariable) {
            case 2:
                // go back after pause
                stop_start = !stop_start;
                break;
            case 3:
                // one step update
                updateState();
                showState();
                break;
        }
    }
    /* clean up */
    endwin();
    return 0;
}
