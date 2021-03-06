// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "./hashi.h"
#include "./island.h"
// _____________________________________________________________________________
Hashi::Hashi() {
  // datatype
  _plain = false;
  _xy = false;
  _xySolution = false;
  _firstClick = true;
}

// _____________________________________________________________________________
Hashi::~Hashi() {
  endwin();
}

// _____________________________________________________________________________
void Hashi::initilizeGame() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_MAGENTA);  // island correct
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);  // island wrong
  init_pair(3, COLOR_WHITE, COLOR_GREEN);  // bridge
    refresh();
  // getch();
}

// _____________________________________________________________________________
void Hashi::printUsage() const {
  std::string usage = "Usage: ./hashiMain <filename>";
  std::string option1 = "-Undo <int> (optional, default: 5)";
  std::cout << usage << std::endl;
  std::cout << option1 << std::endl;
  exit(1);
}

// _____________________________________________________________________________
void Hashi::parseCommandLineArguments(int argc, char** argv) {
  struct option options[] = {
    {"undo", 1, NULL, 'u'},
    {NULL, 0, NULL, 0}
  };
  optind = 1;

  // Default values
  _inputFileName = "";
  _undoOp = 5;

  while (true) {
    char c = getopt_long(argc, argv, "u:", options, NULL);
    if (c == -1) { break; }
    switch (c) {
    case 'u':
      _undoOp = atoi(optarg);
      break;
    case '?':
    default:
      printUsage();
    }
  }

  // input file is required argument.
  if (optind + 1 != argc) {
    printUsage();
  }
  _inputFileName = argv[optind];
  // std::cout << _inputFileName << std::endl;
  size_t ending1 = _inputFileName.find('.');
  // size_t ending2 = _inputFileName.find('.', ending1 + 1);

  // check which file type is given.
  // if (ending2 == std::npos) {
  std::string dataType = _inputFileName.substr(ending1 + 1);
  if (dataType == "plain") {
    // std::cout << "plain file" << std::endl;
    _plain = true;
  } else if (dataType == "xy") {
    // std::cout << "xy file" << std::endl;
    _xy = true;
  } else if (dataType == "xy.solution") {
    // std::cout << "xy.solution file" << std::endl;
    _xySolution = true;
  }
}

// _____________________________________________________________________________

void Hashi::getLevel() {
  std::ifstream file(_inputFileName.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << _inputFileName << std::endl;
    exit(1);
  }

  std::string line;
  int x = 0, y = 0;

  island islando;

  while (!file.eof()) {
    std::getline(file, line);
    // reached end of file.
    // if (file.eof()) {break;}

    std::size_t a = line.find('#');
    if (a != std::string::npos) {
        continue;
    }

    // draw Level with plain file.
    if (_plain) {
      for (unsigned int i = 0; i < line.size(); i++) {
        char content = line.at(i);
        if (content != ' ') {
          islando._xCoor = i;  // i = x
          islando._yCoor = y;
          islando._numBridge = content - '0';  // convert char to int
          // add island to all islands
          isl.push_back(islando);
        }
      }
    }
    y++;

    // draw level with xy file.
    if (_xy) {
      // first and second coordinate
      size_t pos1 = line.find(',');
      if (pos1 == std::string::npos) { continue; }
      // second coordinate and number of bridges
      size_t pos2 = line.find(',', pos1 + 1);
      if (pos2 == std::string::npos) { continue; }
      // set coordinates
      x = stoi(line.substr(0, pos1));
      y = stoi(line.substr(pos1 + 1, pos2 - (pos1 +1)));
      _numBridges = std::stoi(line.substr(pos2 + 1, pos2 + 2));
      islando._xCoor = x;
      islando._yCoor = y;
      islando._numBridge = _numBridges;
      // add island to all islands
      isl.push_back(islando);
    }
  }
}

// _____________________________________________________________________________
void Hashi::drawLevel() const  {
  for (auto &a : isl) {
    for (unsigned int i = a._xCoor * 3; i < a._xCoor * 3 + 3; i++) {
            for (unsigned int j = a._yCoor * 3 ; j < a._yCoor * 3 + 3; j++) {
              attron(COLOR_PAIR(2));
              mvprintw(j, i, " ");
            }
    }
    mvprintw(a._yCoor * 3 + 1, a._xCoor * 3 + 1, "%d", a._numBridge);
  }
  attroff(COLOR_PAIR(2));
  refresh();
}

// _____________________________________________________________________________
void Hashi::checkIfIsland(std::size_t x, std::size_t y) {
  for (auto &a : isl) {
    // mvprintw(11, 20, "in check");
    if (x == a._xCoor && y == a._yCoor) {
      mvprintw(11, 20, "x: %d  y: %d  %d", x, y, a._curBridges);
      a._clicked = true;
    }
  }
}

// _____________________________________________________________________________
bool Hashi::checkIslandCollision(size_t coor, size_t min, size_t max,
                                 bool decision) {
  for (auto &a : isl) {
    // for same x coordinate, and in between y coordinate
    if (coor == a._xCoor && min < a._yCoor && a._yCoor < max && decision) {
      return true;
    }
    // for same y coordinate, and in between x coordinate
    if (coor == a._yCoor && min < a._xCoor && a._xCoor < max && !decision) {
      return true;
    }
  }
  return false;
}

// _____________________________________________________________________________
bool Hashi::checkBridgeCollision(size_t minX, size_t maxX,  size_t minY,
                             size_t maxY, bool decision) {
  std::vector<island*> left;
  std::vector<island*> right;
  // case same x
  if (decision) {
    for (auto &a : isl) {
      if ((a._yCoor > minY) && (a._yCoor < maxY)) {
        if (minX > a._xCoor) {
          mvprintw(3, 75, "left");
          left.push_back(&a);
        }
        // if (maxX > a._xCoor) {
        //  mvprintw(4, 75, "right");
        //  right.push_back(&a);
        // }
      }
    }
    mvprintw(0, 0, "size r: %d", right.size());
    mvprintw(1, 0, "size l: %d", left.size());
    for (unsigned int i = 0; i < left.size(); i++) {
      if (!left[i]->islandConnection.empty()) {
        for (auto &k : left[i]->islandConnection) {
          // usleep(1000*1000);
          mvprintw(7, 75, "k_x: %d", k._xCoor);
          if (k._xCoor > minX) {
            mvprintw(8, 75, "collision!");
            right.clear();
            left.clear();
            return true;
          }
        }
      }
    }
    right.clear();
    left.clear();
    mvprintw(9, 75, "%d, %d", right.size(), left.size());
  }

  usleep(1000*2000);
  for ( int i = 3; i <= 9; i++) { mvprintw(i, 75, "            "); }
  // case y
  // if (!decision) {

  // }
  return false;
}

// _____________________________________________________________________________
void Hashi::buildBridge() {
  // std::vector<std::pair<size_t, size_t> > temp;
  std::vector<island*> isla;
  island *is1;
  island *is2;
  // get the two clicked islands
  for (auto &a : isl) {
    if (a._clicked && isla.size() <= 2) {
      // temp.push_back(std::make_pair(a._xCoor, a._yCoor));
      isla.push_back(&a);
    }
  }
  // after getting the both clicked islands
  if (isla.size() == 2) {
    is1 = isla[0];
    is2 = isla[1];
    mvprintw(15, 29, "%d", is1->_xCoor);
    mvprintw(15, 30, "%d", is1->_yCoor);
    // set bounds in actual coords
    int minX = std::min(is1->_xCoor, is2->_xCoor) * 3 + 3;
    int maxX = std::max(is1->_xCoor, is2->_xCoor) * 3;
    int middleX = std::min(is1->_xCoor, is2->_xCoor) * 3 + 1;
    int minY = std::min(is1->_yCoor, is2->_yCoor) * 3 + 3;
    int maxY = std::max(is1->_yCoor, is2->_yCoor) * 3;
    int middleY = std::min(is1->_yCoor, is2->_yCoor) * 3 + 1;

    // set bounds in grid coordinates
    size_t gridMinX = std::min(is1->_xCoor, is2->_xCoor);
    size_t gridMaxX = std::max(is1->_xCoor, is2->_xCoor);
    size_t gridMinY = std::min(is1->_yCoor, is2->_yCoor);
    size_t gridMaxY = std::max(is1->_yCoor, is2->_yCoor);

    // same x Coordinate (clicked Islands)
    if (is1->_xCoor == is2->_xCoor) {
      // if (is1->_curBridges <= is1->_numBridge &&
      //     is2->_curBridges <= is2->_numBridge) {
      int cnt = 0;
      // if island hast bridges.
      if (!(is1->islandConnection.empty())) {
        for (auto &i : is1->islandConnection) {
          // check whether is2 is connected with is1 already.
          if (i._xCoor == is2->_xCoor && i._yCoor == is2->_yCoor) {
            cnt++;
            mvprintw(0, 75 , "counter: %d", cnt);
          }
        }
      }
      // no connection between the clicked islands.
      if (cnt == 0) {
        // bool to seperate case x and case y
	bool decision = true;
        // check Collision with other island.
        bool colIsland = checkIslandCollision(is1->_xCoor, gridMinY,
                                              gridMaxY, decision);
        // check collision with other bridge.
        bool colBridge = checkBridgeCollision(is1->_xCoor, is2->_xCoor , gridMinY, gridMaxY, true);
	// gridMaxX, decision);

        if (!colIsland) {
          if (!colBridge) {
            // draw bridge
            for (int i = minY ; i < maxY; i++) {
              attron(COLOR_PAIR(3));
              mvprintw(i, middleX, "|");
              is1->_clicked = false;
              is2->_clicked = false;
            }
            // add island connection
            is1->islandConnection.push_back(*is2);
            is2->islandConnection.push_back(*is1);
            // increment bridges
            is1->_curBridges += 1;
            is2->_curBridges += 1;
          }
        }
        // islands are connected through a single bridge
      } else if (cnt == 1) {
        for (int i = minY; i < maxY; i++) {
            attron(COLOR_PAIR(3));
            mvprintw(i, middleX, "H");
            is1->_clicked = false;
            is2->_clicked = false;
        }
        // add island connection
        is1->islandConnection.push_back(*is2);
        is2->islandConnection.push_back(*is1);
        // increment bridges
        is1->_curBridges += 1;
        is2->_curBridges += 1;
        // islands are connected through a double bridge.
      }  // else if (_cnt == 2) {
      // remove the connection from the vector and delete the bridge.
      // }
    }

    // }
    // same y Coordinate (clicked Islands)
    if (is1->_yCoor == is2->_yCoor) {
      // if (is1->_curBridges <= is1->_numBridge &&
      //     is2->_curBridges <= is2->_numBridge) {
      bool decision = false;
      // check if neighbors
      bool collideIsland = checkIslandCollision(is1->_yCoor, gridMinX,
                                                gridMaxX, decision);

      if (!collideIsland) {
        // draw bridge
        for (int i = minX; i < maxX; i++) {
          attron(COLOR_PAIR(3));
          mvprintw(middleY, i, "-");
          is1->_clicked = false;
          is2->_clicked = false;
        }
        // save the connection between the bridges.
        is1->islandConnection.push_back(*is2);
        is2->islandConnection.push_back(*is1);

        // increment the bridge
        is1->_curBridges += 1;
        is2->_curBridges += 1;
      }
      //}
    }
    attroff(COLOR_PAIR(3));
    is1->_clicked = false;
    is2->_clicked = false;
    mvprintw(19, 20, "%d", isla.size());
    isla.clear();
    mvprintw(20, 20, "%d", isla.size());
    for (auto &isla : isl) { isla._clicked = false; }
    // mvprintw(14, 20, "%d  could be friends", is2->_xCoor);
    // mvprintw(15, 20, "%d  could be friends", is2->_yCoor);
  }
  int yy = 0;
  for (auto &a : isl) {
    mvprintw(yy, 90, "xCoor: %d, yCoor: %d, _numB: %d, _curB %d, _clicked %d",
             a._xCoor, a._yCoor, a._numBridge, a._curBridges, a._clicked);
    yy++;
  }
}

// _____________________________________________________________________________
void Hashi::undo() {
  island is;
  is.islandConnection.pop_back();
}

// _____________________________________________________________________________
int Hashi::processUserInput(int key) {
  MEVENT event;
  switch (key) {
  case 27:
    // exit
    return -1;
  case KEY_MOUSE:
    // get the clicked coords and build bridge between islands if possible
    if (getmouse(&event) == OK) {
      std::size_t x = (event.x / 3);
      std::size_t y = (event.y / 3);
      mvprintw(12, 20, "%d, %d", x, y);
      // mvprintw(10, 20, "                           ");
      checkIfIsland(x, y);
      // if (checkIfIsland(x, y)) {
      //  mvprintw(10, 20, "hallo found");
      // buildBridge();
      // }
    }
    break;
  case 'u':
    // undo
    //  start undo function
    break;
  }
  return 0;
}

// _____________________________________________________________________________
void Hashi::play() {
  while (true) {
    int key = getch();
    int input = processUserInput(key);
    // if (input == 2) {
    // undo();
    if (input == -1) {
      // Exit
      break;
    } else {
      buildBridge();
    }
  }
}

// _____________________________________________________________________________
// void Hashi::getStarted() {
//  parseCommandLineArguments(argc, argv);
//  getLevel();
//  initilizeGame();
//  drawLevel();
// }
