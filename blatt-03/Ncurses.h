/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <ncurses.h>
#ifndef NCURSES_H_
#define NCURSES_H_

extern int x;
extern int y;
extern int radius;
extern int boxsize;
extern float speedy;
extern float speedx;

/* initialize the terminal */
void initTerminal(void);

/* draw ball */
void drawBall(WINDOW *win, bool check);

/* move ball around */
float moveBall(int direction);

#endif /* NCURSES_H_ */
