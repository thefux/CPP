/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <stdlib.h>
#include <stdio.h>
#include "./MarketSimulator.h"
#include "./Trader.h"

// main program
int main(int argc, char** argv) {
    // create market and trade objects
    MarketSimulator mark;
    Trader trader;
    // call parseCommand function
    mark.parseCommandLineArguments(argc, argv);
    // simulate
    mark.simulate(&trader);
    return 0;
}
