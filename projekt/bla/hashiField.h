// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <gtest/gtest.h>
#include <vector>
#include <string>
// #include "./hashiIsland.h"

#ifndef HASHIFIELD_H_
#define HASHIFIELD_H_


// class that builds the field fpr the game hashi.
class HashiField {
 public:
  HashiField();

  ~HashiField();

  // methods
  // puts in the game islands by reading in the file.
  void initilizeGame();

  // prints out the current state with the islands status, bridges new and old.
  void showState();

  // reads in the .plain file containing the map.
  void getLevelPlain(std::string filename);

  // reads in the .xy file containing the map.
  void getLevelXY(std::string filename);

  // draws the inital state of the game, according to a .plain file.
  void drawLevel() const;

  // draws the inital state of the game, according to a .xy file.
  void drawLevelXY() const;

  // prints the manual how to start the game and exits afterwards.
  void printUsage() const;

  // finds the neighbors of the island and returns the coordinates.
  // int* getNeighbors(HashiIsland* island);

  // draws the wanted bridge.
  // void drawBridge(HashiIsland& islandOne, HashiIsland& islandTwo);
  // FRIEND_TEST(hashiField, drawBridge);

  // checks if wanted bridge is allowed,
  // bool bridgePossible(HashiIsland* island1, HashiIsland* island2) const;

  // checks if game is done and right, with the xy.solution
  bool gameDone() const;

  // checks if undo is possible, with the given number of undos in cmd and
  // if yes undoes the last step.
  void undo();

  // processes user input
  int processUserInput(int key) const;

  // runs the game according to the result of processUserInput.
  void play(std::string file);

  // static const int MAX_GRID_SIZE = 50;  // probably going to be replaced
                                        // by something dynamic, from the
                                        // the input file.

 private:
  // variablen
  // Grids and pointers.
  char** _currentField;
  char** _nextField;

  // Last coordinate clicked inside grid. for undo maybe....
  // int _lastClickedX;
  // int _lastClickedY;

  // Display size
  int _xGridSize;
  int _yGridSize;

  int _xSize;
  int _ySize;

  // Bounding box of displayed region.
  int _drawMinX;
  int _drawMaxX;
  int _drawMinY;
  int _drawMaxY;

  int _numBridges;

  bool _allowed;
};

#endif  // HASHIFIELD_H_
