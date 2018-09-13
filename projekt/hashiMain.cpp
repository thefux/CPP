// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "./hashi.h"

int main(int argc, char** argv) {
  // bool _plain;
  // bool _xy;
  Hashi field;
  field.parseCommandLineArguments(argc, argv);
  field.getLevel();
  field.initilizeGame();
  field.drawLevel();
  while (true) {
    int key = getch();
    field.processUserInput(key);
    field.buildBridge();
  }
}
