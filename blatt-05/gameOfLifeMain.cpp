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
    gameOfLife game;
    game.initializeGame();
    game.play();
    return 0;
}
