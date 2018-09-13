// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <string>
#include <vector>
#include "./island.h"

#ifndef HASHI_H_
#define HASHI_H_


// class that runs the game hashiwa...
class Hashi {
 public:
  // Constructor
  Hashi();

  // Destuctor
  ~Hashi();

  // Methods

  // prepares the painting and bridgebuiling.
  void initilizeGame();

  // prints the usage of the game.
  void printUsage() const;

  // gets the given arguments.
  void parseCommandLineArguments(int argc, char** argv);

  // reads the plain file in.
  // void getLevelPlain(std::string filename);

  // reads in the xy file.
  void getLevel();

  // draws the game map corrosponding to the result of the reading method.
  void drawLevel() const;

  // runs the game.
  void play();

  // processes the input of the user, such as mouse click
  int processUserInput(int key);

  // draws a bridge between two islands
  void buildBridge();

  // checks if an island was clicked or just a random point
  void checkIfIsland(std::size_t x, std::size_t y);

  // checks if the two clicked islands are direct neighbors
  // or if another island is in between those two.
  bool checkIslandCollision(size_t coor, size_t min, size_t max, bool decision);

 private:
  // Bounding box of displayed region.
  // int _drawMinX;
  // int _drawMaxX;
  // int _drawMinY;
  // int _drawMaxY;
  std::vector<class  island> isl;
  int _numBridges;

  // Commandline arguments.
  int _undoOp;
  std::string _inputFileName;

  // datatype
  bool _plain;
  bool _xy;
  bool _xySolution;

  // Mouse clicks
  bool _firstClick;
  bool _secondClick;
};

#endif  // HASHI_H_
