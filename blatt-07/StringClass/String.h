/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#ifndef STRING_H_
#define STRING_H_

#include <gtest/gtest.h>

class String {
 public:
  // Default constructor.
  String();

  // Copy constructor.
  String(const String& s);

  // Destructor.
  ~String();

  // Set to given C-style string.
  void set(const char* s);

  // convert a string to float
  float toFloat(void);

  // accuracy
  int count(const char c);

  // split
  void split(const char sep, const int maxParts, String result[]) const;

  // get the content with a public method
  char* getContents(void) {
      return _contents;
  }

  FRIEND_TEST(StringTest, constructor);
  FRIEND_TEST(StringTest, set);
  FRIEND_TEST(StringTest, copyConstructor);
  FRIEND_TEST(StringTest, count);
  FRIEND_TEST(StringTest, toFloat);
  FRIEND_TEST(StringTest, split);
  FRIEND_TEST(StringTest, splitTooManyDelimiters);
  FRIEND_TEST(StringTest, splitTooFewDelimiters);
  FRIEND_TEST(StringTest, splitNoDelimiter);

 private:
  // Keep track of the number of objects.
  static int _numObjects;

  // The contents of the string. We use a null-terminated C-style string, so
  // that we can pass on _contents to C-style functions like printf("%s", ...).
  char* _contents;

  // The length of the string. We keep track of this explicitly, so that we can
  // answer length queries in constant time.
  int _length;

  // Id (for demonstration purposes).
  int _id;
};

#endif  // STRING_H_
