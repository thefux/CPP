// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
// #include "./hashiIsland.h"
// #include "./hashiGame.h"
#include "./hashiField.h"

// _____________________________________________________________________________
HashiField::HashiField() {
  // Scaling
  _xGridSize = 10;
  _yGridSize = 10;

  _xSize = 3;
  _ySize = 3;

  // _lastClickedX = -1;
  // _lastClickedY = -1;
}

// _____________________________________________________________________________
HashiField::~HashiField() {
  delete[] _currentField;
  delete[] _nextField;
  endwin();
}

// _____________________________________________________________________________
void HashiField::initilizeGame() {
  // Init terminal
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);  // Island
  init_pair(2, COLOR_BLACK, COLOR_BLUE);  // Bridge
  // Usage of predefined colors
  attron(COLOR_PAIR(1));
  printw("This is green with a yellow background!\n");
  attron(COLOR_PAIR(2));
  printw("This is red with a blue background!\n");
  attroff(COLOR_PAIR(2));

  getch();

  // Determine drawing bounds. Show only around the center of the grid with
  // respect to the scaling of one cell.
  // _drawMinX = (_xGridSize / 2) - ((COLS / _xSize) / 2);
  // _drawMaxX = _drawMinX + (COLS / _xSize);
  // _drawMinY = (_yGridSize / 2) - ((LINES / _ySize) / 2);
  // _drawMaxY = _drawMinY + (LINES / _ySize);
}
/*
// _____________________________________________________________________________
void HashiField::getLevelPlain(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  std::string line;
  // std::vector<std::string> temp;
  bool firstLine = true;
  int x = 0;
  int y = 0;

  while (true) {
    std::getline(file, line);
    // reached end of file.
    if (file.eof()) {break;}

    // get the map size
    if (firstLine) {
      size_t divider = line.find(':');
      size_t stopper = line.find('(');
      _xGridSize = std::stoi(line.substr(2, divider));
      _yGridSize = std::stoi(line.substr(divider + 1, stopper - 1));
      // set the map size
      _currentField = new char*[_xGridSize];
      _nextField = new char*[_xGridSize];
      for (int i = 0; i < _xGridSize; i++) {
        _currentField[i] = new char[_yGridSize];
        _nextField[i] = new char[_yGridSize];
      }
      *_currentField = 0;
      *_nextField = 0;
      // x = 0;
      // y = 0;
      firstLine = false;
    }
    for (int i = 0; i < _yGridSize; i++) {
      std::string content = line.substr(i, 1);
      strcpy(&_currentField[x][y], content.c_str());
      // *_currentField[x][y] = line.substr(i, 1);
      y++;
    }
    y = 0;
    x++;
  }
}

// _____________________________________________________________________________
void HashiField::getLevelXY(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  std::string line;
  // std::vector<std::string> temp;
  bool firstLine = true;
  int x;
  int y;

  while (true) {
    std::getline(file, line);
    // reached end of file.
    if (file.eof()) {break;}

    // get the map size
    if (firstLine) {
      size_t divider = line.find(':');
      size_t stopper = line.find('(');
      _xGridSize = std::stoi(line.substr(2, divider));
      _yGridSize = std::stoi(line.substr(divider + 1, stopper - 1));
      // set the map size
      _currentField = new char*[_xGridSize];
      _nextField = new char*[_xGridSize];
      for (int i = 0; i < _xGridSize; i++) {
        _currentField[i] = new char[_yGridSize];
        _nextField[i] = new char[_yGridSize];
      }
      *_currentField = 0;
      *_nextField = 0;
      // x = 0;
      // y = 0;
      firstLine = false;
    }

    size_t pos1 = line.find(',');
    if (pos1 == std::string::npos) { continue; }
    size_t pos2 = line.find(',', pos1 + 1);
    if (pos2 == std::string::npos) { continue; }
    x = stoi(line.substr(0, pos1));
    y = stoi(line.substr(pos1 + 1, pos2 - (pos1 +1)));
    std::string bridges = line.substr(pos2 + 1, std::string::npos);
    _numBridges = std::stoi(line.substr(pos2 + 1, std::string::npos));

    strcpy(&_currentField[x][y], bridges.c_str());
  }
}

// _____________________________________________________________________________
void HashiField::drawLevel() const  {
  for (int x = 0; x < _drawMaxX - _drawMinX; ++x) {
    for (int y = 0; y < _drawMaxY - _drawMinY; y++) {
      attroff(COLOR_PAIR(1));
      if (_currentField[_drawMinX + x][_drawMinY + y] == '#') {break;}
      if (('1' <= _currentField[_drawMinX + x][_drawMinY + y]) && \
          (_currentField[_drawMinX + x][_drawMinY + y] <= '8')) {
        attron(COLOR_PAIR(1));
        // numberBridges = stoi(_currentField[_drawMinX + x][_drawMinY + y])
      }
      // scale each visible cell.
      for (int dx = 0; dx < _xSize; ++dx) {
        for (int dy = 0; dy < _ySize; ++dy) {
          mvprintw(y * _ySize + dy, x * _xSize + dx,
                   &_currentField[_drawMinX + x][_drawMinY + y]);
        }
      }
    }
  }
  attroff(COLOR_PAIR(1));
}

// _____________________________________________________________________________
// void HashiField::drawLevelXY() const {}
// _____________________________________________________________________________
void HashiField::showState() {
  // Draw islands
  for (int x = 0; x < _drawMaxX - _drawMinX; ++x) {
    for (int y = 0; y < _drawMaxY - _drawMinY; ++y) {
      attron(COLOR_PAIR(1));
      // if ((*newGrid)[_drawMinX + x][_drawMinY + y]) {
      // attron(COLOR_PAIR(2));
      // }
      // Scale each visible cell.
      for (int dx = 0; dx < _xSize; ++dx) {
        for (int dy = 0; dy < _ySize; ++dy) {
          mvprintw(y * _ySize + dy, x * _xSize + dx, " ");
        }
      }
    }
  }
  attroff(COLOR_PAIR(1));
}

// _____________________________________________________________________________
void HashiField::printUsage() const {
  std::string usage = "Usage: ./hashiMain <filename>";
  std::string option1 = "-Undo <int> (optional, default: 5)";
  std::cout << usage << std::endl;
  std::cout << option1 << std::endl;
  exit(1);
}
// _____________________________________________________________________________
// int* HashiField::getNeighbors(HashiIsland* island) {
//   return 1;
// }

// _____________________________________________________________________________
// void HashiField::drawBridge(HashiIsland& island1, HashiIsland& island2) {
  // // allowed = bridgePossible(island1, island2);
  // _allowed = true;
  // // if (!_allowed) { break;}
  // if (_allowed) {
  //   // same x coordinate and island 1 over island 2.
  //   if (island1._xPos == island2._xPos && island1._yPos < island2._yPos) {
  //     int x = island1._xPos;
  //     for (int y = island1._yPos; y <= island2._yPos; y++) {
  //       if (_currentField[x][y] = ' ') {
  //         _nextField[x][y] = '_';
  //       } else if (_currentField[x][y] = '_') {
  //         _nextField[x][y] = '=';
  //       } else if (_currentField[x][y] = '=') {
  //         _nextField[x][y] = ' ';
  //       }
  //     }
  //   }
  //   // same x coordinate and island 1 is under island 2.
  //   if (island1._xPos == island2._xPos && island1._yPos > island2._yPos) {
  //     int x = island1._xPos;
  //     for (int y = island1._yPos; y >= island2._yPos; y--) {
  //       if (_currentField[x][y] = ' ') {
  //         _nextField[x][y] = '_';
  //       } else if (_currentField[x][y] = '_') {
  //         _nextField[x][y] = '=';
  //       } else if (_currentField[x][y] = '=') {
  //         _nextField[x][y] = ' ';
  //       }
  //     }
  //   }
  //   // same y coordiate and island 1 is left from island 2.
  //   if (island1._yPos == island2._yPos && island1._xPos < island2._xPos) {
  //     int y = island1._yPos;
  //     for (int x = island1._xPos; x <= island2._xPos; x++) {
  //       if (_currentField[x][y] = ' ') {
  //         _nextField[x][y] = '_';
  //       } else if (_currentField[x][y] = '_') {
  //         _nextField[x][y] = '=';
  //       } else if (_currentField[x][y] = '=') {
  //         _nextField[x][y] = ' ';
  //       }
  //     }
  //   }
  //
  //   // same y coordiate and island 1 is right from island 2.
  //   if (island1._yPos == island2._yPos && island1._xPos > island2._xPos) {
  //     int y = island1._yPos;
  //     for (int x = island1._xPos; x >= island2._xPos; x--) {
  //       if (_currentField[x][y] = ' ') {
  //         _nextField[x][y] = '_';
  //       } else if (_currentField[x][y] = '_') {
  //         _nextField[x][y] = '=';
  //       } else if (_currentField[x][y] = '=') {
  //         _nextField[x][y] = ' ' ;
  //       }
  //     }
  //   }
  //   char (temp*)[MAX_GRID_SIZE] = _currentField;
  //   _currentField = _nextField;
  //   _nextField = temp;
  // }
// }

// _____________________________________________________________________________
// bool HashiField::bridgePossible(HashiIsland* island1,
// HashiIsland* island2) const {
//  return false;
// }

// _____________________________________________________________________________
int HashiField::processUserInput(int key) const {
  // d => game done, check if right.
  // u => undo;
  // ESC => exit game;
  return -1;
}

// _____________________________________________________________________________
bool HashiField::gameDone() const { return false;}

// _____________________________________________________________________________
void HashiField::undo() {}

// _____________________________________________________________________________
void HashiField::play(std::string file) {
  // getLevel(file);
  // while (true) {
  //     int key = getch();
  //     int newRun = processUserInput(key);
  //     if (newRun == -1) {
  //       // Exit
  //       break;
  //     }
  //     if (done) {
  //
  //     }
  //     if (undo) {
  //
  //     }
  //     // Draw and wait.
  //     showState();
  //     usleep(10 * 1000);
}
*/

