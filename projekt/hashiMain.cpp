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
  Hashi field;
  // field.getStarted();
  field.parseCommandLineArguments(argc, argv);
  field.getLevel();
  field.initilizeGame();
  field.drawLevel();
  while (true) {
    field.play();
  }
}
