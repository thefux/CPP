/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./String.h"

// ___________________________________________________________________________
int String::_numObjects = 0;

/* constructor [[*/
// ___________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
  _id = ++_numObjects;

  // printf("Default constructor ... created object #%d\n", _id);
}
/*]]*/

/* constructor with argument [[*/
// ___________________________________________________________________________
String::String(const String& s) {
  _contents = 0;  // delete[] 0 in set no problem.
  set(s._contents);
  _id = ++_numObjects;
  // printf("Copy constructor ... created object #%d\n", _id);
}
/*]]*/

/* destructor[[*/
// ___________________________________________________________________________
String::~String() {
  delete[] _contents;
}
/*]]*/

/* set [[*/
// ___________________________________________________________________________
void String::set(const char* s) {
  _length = strlen(s);
  delete[] _contents;
  _contents = new char[_length + 1];
  for (int i = 0; i < _length + 1; i++) { _contents[i] = s[i]; }
}
/*]]*/

/* split [[*/
// ___________________________________________________________________________
void String::split(const char c, const int numberOfElement, String s[]) {
    // used to store the location of each delimiter and useful location
    int* _DelimiterInArray = new int[numberOfElement + 1];
    *_DelimiterInArray = 0;

    int delimiterCounter = 0;
    _DelimiterInArray[0] = 0;
    int count = 1;

    // store position of delimiter inside the array
    for (int i = 0; i < _length; ++i) {
        if (_contents[i] == c  && delimiterCounter < numberOfElement - 1) {
            _DelimiterInArray[count] = i;
            count++;
            delimiterCounter++;
        }
    }
    _DelimiterInArray[count] = _length;

    // counters
    int word = 0;
    int i = 0;
    int p = 0;
    while (i < numberOfElement && delimiterCounter != 0) {
        for (int j = _DelimiterInArray[i]; j < _DelimiterInArray[i + 1]; ++j) {
            if (_contents[j] != c) {
                // why is this a Problem
                s[word]._contents[p] = _contents[j];
                p++;
            }
        }
        p = 0;
        word++;
        i++;
    }

    // the case were too many delimiters exists
    int alphabet = 0;
    if (delimiterCounter >= numberOfElement - 1) {
        for (int i = _DelimiterInArray[numberOfElement - 1] + 1;
                i < _length; ++i) {
            s[numberOfElement - 1]._contents[alphabet] = _contents[i];
            alphabet++;
        }
    }

    if (delimiterCounter == 0) {
        for (int i = 0; i < _length; ++i) {
            s[0]._contents[i] = _contents[i];
        }
    }

    delete[] _DelimiterInArray;
}
/*]]*/

/* count [[*/
// ___________________________________________________________________________
int String::count(const char c) {
    int count = 0;
    for (int i = 0; i < _length; ++i) {
        if (_contents[i] == c) {
            count++;
        }
    }
    return count;
}
/*]]*/

/* toFloat[[*/
// ___________________________________________________________________________
float String::toFloat(void) {
    float toNum = 0.0;
    toNum = strtof(_contents, 0);
    return toNum;
}/*]]*/

// tests
/*[[*/

    // debugging to check the functionality
    // printf("delimiter: %d\n",  _DelimiterInArray[0]);
    // printf("delimiter: %d\n",  _DelimiterInArray[1]);
    // printf("delimiter: %d\n",  _DelimiterInArray[2]);
    // printf("delimiter: %d\n",  _DelimiterInArray[3]);
    // printf("delimiter: %d\n",  _DelimiterInArray[4]);
    // printf("delimiterCounter : %d\n", delimiterCounter);
    // printf("delimiter 0: %c\n",  s[0]._contents[0]);
    // printf("delimiter 0: %c\n",  s[0]._contents[1]);
    // printf("delimiter 0: %c\n",  s[0]._contents[2]);
    // printf("delimiter 0: %c\n",  s[0]._contents[3]);
    // printf("delimiter 0: %c\n",  s[0]._contents[4]);

    // printf("delimiter 1: %c\n",  s[1]._contents[0]);
    // printf("delimiter 1: %c\n",  s[1]._contents[1]);
    // printf("delimiter 1: %c\n",  s[1]._contents[2]);

    // printf("delimiter 2: %c\n",  s[2]._contents[0]);
    // printf("delimiter 2: %c\n",  s[2]._contents[1]);
    // printf("delimiter 2: %c\n",  s[2]._contents[2]);
    // printf("delimiter 2: %c\n",  s[2]._contents[3]);
    // printf("delimiter 2: %c\n",  s[2]._contents[4]);
    // printf("delimiter 2: %c\n",  s[2]._contents[5]);

    // printf("delimiter 3: %c\n",  s[3]._contents[0]);
    // printf("delimiter 3: %c\n",  s[3]._contents[1]);
    // printf("delimiter 3: %c\n",  s[3]._contents[2]);
    // printf("delimiter 3: %c\n",  s[3]._contents[3]);/*]]*/
