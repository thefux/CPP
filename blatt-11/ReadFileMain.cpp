/*
 * copyright Abderrahmen Rakez
 *
 * */

#include <iostream>
#include "./ReadFile.h"

int main(int argc, char *argv[]) {
    ReadFile r;
    r.processCommandLineArguments(argc, argv);
    return 0;
}
