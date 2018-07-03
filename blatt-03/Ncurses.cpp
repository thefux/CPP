/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include "./Ncurses.h"
#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

int x;
int y;
/* 
 * in my case the radius is the same 
 * */
int radius;
int boxsize;
float speed;
float speedx;
float speedy;

// ___________________________________________________________________________
void initTerminal(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(false);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    radius = 6;
    boxsize = 20;
    x = (COLS - boxsize)/2;
    y = 2;
    speedx = 1;
    speedy = 1.5;
}

// ___________________________________________________________________________
void drawBall(WINDOW *win, bool check) {
    float console_ratio = 3.05/3.0;
    float a = console_ratio*radius - 4.10;
    float b = radius - 1.21;
    wattron(win, A_REVERSE);

    if (check) {
        for (int dx = -radius; dx <= radius; dx++) {
            for (int dy = -console_ratio*radius;
                    dy <= console_ratio*radius; dy++) {
                float d = (dy/a)*(dy/a) + (dx/b)*(dx/b);
                if (d < 1.2) {
                    mvwprintw(win, y + dy, x + dx, " ");
                }
            }
        }
    } else {
        clear();
    }
    wattroff(win, A_REVERSE);
}
// ___________________________________________________________________________
float moveBall(int direction) {
    // right 261, left 260, up 259, down 258
    switch (direction) {
        case KEY_DOWN:
            speedy = 2.5;
            // speedy = static_cast <float> (rand()) /
            //     (static_cast <float> (RAND_MAX/3)) + 1;
            break;
        case KEY_UP:
            speedy = -1.8;
            // speedy = - static_cast <float> (rand()) /
            //     (static_cast <float> (RAND_MAX/3)) - 1;
            break;
        case KEY_RIGHT:
            speedx = 1;
            speedy = static_cast <float> (std::rand()) /
                (static_cast <float> (RAND_MAX/3)) + 1;
            break;
        case KEY_LEFT:
            speedx = -1;
            speedy = static_cast <float> (std::rand()) /
                (static_cast <float> (RAND_MAX/3)) + 1;
            break;
        case 27:
            speedy = -0.75;
            break;
    }
    return speedy;
}
