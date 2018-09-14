// Copyright 2018,
// Author: Kerstin Rodko <kerstin.rodko@merkur.uni-freiburg.de>
// Orientated on code kindly provided by:
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#ifndef ISLAND_H_
#define ISLAND_H_
#include <vector>
#include "./hashi.h"

class island {
 public:
  island();
  friend class Hashi;
 private:
  std::size_t _xCoor;
  std::size_t _yCoor;
  std::size_t _numBridge;
  std::size_t _curBridges;
  bool _clicked;
  std::vector<island> islandConnection;
};
#endif  // ISLAND_H_
