/*
 * copyright Abderrahmen Rakez
 *
 * */

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <string>
#include <gtest/gtest.h>


class String {
 public:
  // Default constructor.
  String();

  // Copy constructor.
  String(const String& s);

  // Set to given C-style string.
  void set(const std::string s);

  // split
  std::vector<std::string> split(std::string s);
 private:
  // The contents of the string
  std::string _contents;
};

#endif  // STRING_H_
