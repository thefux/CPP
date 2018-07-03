/*
 * copyright Abderrahmen Rakez 
 * 
 * the user hast the hole control
 * by pressing one of the arrow keys (for 1s long) 
 * the direction and the speed will change
 *
 * */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "./Ncurses.h"

int main(void) {
    /**/
    initTerminal();

    WINDOW* win = newwin(LINES - 0, COLS - boxsize, 0, 0);
    box(win, 0, 0);
    drawBall(win, true);
    WINDOW* winSpeed = newwin(10, 20 , 0, COLS - boxsize);
    box(winSpeed, 0, 0);
    refresh();
    wrefresh(win);
    wrefresh(winSpeed);
    int o = 0;
    while (true) {
        /* for better looking a window is been created */
        win = newwin(LINES, COLS - boxsize, 0, 0);
        box(win, 0, 0);
        WINDOW* winSpeed = newwin(10, 20 , 0, COLS - 20);
        box(winSpeed, 0, 0);

        /* check for user input: 
         *
         * for this reason the user have to press a key at least for a second
         * the arrow keys are used to change the direction of the ball 
         *
         * */
        if (getch()) {
            o = getch();
            moveBall(o);
        }

        /* draw the ball each time it changes it's position */
        drawBall(win, false);
        y += speedy;
        x += speedx;
        int proportional = (1/abs(speedy)) * 15;
        usleep(proportional * 10000);
        drawBall(win, true);
        wprintw(win, "%d, %d", x, y);

        /* to ensure the reflection of the Ball */
        if (y <= 3) {
            speedy = abs(speedy);
        }
        if ((y + 4) >= LINES) {
            speedy = -abs(speedy);
        }
        if (x  <= 6) {
            speedx = 1;
        }

        if (x >= COLS- boxsize -7) {
            speedx = -1;
        }
        /* 
         * after some time the ball stops moving
         * in the y direction and carry moving in the x axis and
         * stops moving after some time
         * (10% is too much)
         * */
        speedy -= speedy*0.01;
        mvwprintw(winSpeed, 1, 1, "speed: \n\r");
        mvwprintw(winSpeed, 2, 1, "%f", speedy);

        /* refresh the Window and the box */
        refresh();
        wrefresh(win);
        wrefresh(winSpeed);
    }

    return 0;
}
