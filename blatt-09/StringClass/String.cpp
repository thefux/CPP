/*
 * copyright Abderrahmen Rakez
 *
 * */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include "./String.h"

/* constructor [[*/
// ___________________________________________________________________________
String::String() {
  _contents = "";
}
/*]]*/

/* constructor with argument [[*/
// ___________________________________________________________________________
String::String(const String& s) {
  _contents = "";  // delete[] 0 in set no problem.
  set(s._contents);
  // printf("Copy constructor ... created object #%d\n", _id);
}
/*]]*/

/* set [[*/
// ___________________________________________________________________________
void String::set(const std::string s) {
    _contents = s;
}
/*]]*/

/* split [[*/
// ___________________________________________________________________________
std::vector<std::string> String::split(std::string s) {
    std::istringstream is(s);

    // split each time a space was found
    std::vector<std::string> stri{std::istream_iterator<std::string>{is},
        std::istream_iterator<std::string>{}};

    // return vector
    return stri;
}
/*]]*/
