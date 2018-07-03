// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Johanna Götz <johanna.goetz@uranus.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>
#include "./WordCounter.h"

// _____________________________________________________________________________
TEST(WordCounter, getSizeAndGetWordCount) {
  WordCounter wc;
  ASSERT_EQ(0, wc.getNumWords());
  ASSERT_EQ(0, wc.getWordCount("one"));
  ASSERT_EQ(0, wc.getNumWords());
  ASSERT_EQ(0, wc.getWordCount("ring"));
  ASSERT_EQ(0, wc.getNumWords());
}

TEST(WordCounter, updateWordCounts) {
  WordCounter wc;
  // Set min length to 4 to allow shorter example words in the tests
  wc._minLength = 4;

  ASSERT_EQ(0, wc.getNumWords());

  std::vector<std::string> words;
  wc.updateWordCounts(words);
  ASSERT_EQ(0, wc.getNumWords());

  words.push_back(std::string("one"));
  words.push_back(std::string("ring"));
  wc.updateWordCounts(words);
  ASSERT_EQ(1, wc.getNumWords());
  ASSERT_EQ(1, wc.getWordCount("ring"));

  words.push_back(std::string("to"));
  words.push_back(std::string("rule"));
  words.push_back(std::string("rule"));
  words.push_back(std::string("rule"));
  wc.updateWordCounts(words);
  ASSERT_EQ(2, wc.getNumWords());
  ASSERT_EQ(2, wc.getWordCount("ring"));
  ASSERT_EQ(3, wc.getWordCount("rule"));

  words.clear();
  words.push_back(std::string("all"));
  words.push_back(std::string("rule"));
  words.push_back(std::string("bring"));
  words.push_back(std::string("darkness"));
  wc.updateWordCounts(words);
  ASSERT_EQ(4, wc.getNumWords());
  ASSERT_EQ(2, wc.getWordCount("ring"));
  ASSERT_EQ(4, wc.getWordCount("rule"));
  ASSERT_EQ(1, wc.getWordCount("bring"));
  ASSERT_EQ(1, wc.getWordCount("darkness"));

  ASSERT_EQ(0, wc.getWordCount("bind"));
  ASSERT_EQ(4, wc.getNumWords());
}


TEST(WordCounter, readFile) {
  FILE* input = fopen("WordCounterTest.tmp", "w");
  fprintf(input, "One Ring to rule them all, One Ring to find them,\n"
                 "One Ring to bring them all and in the darkness bind them\n");
  fclose(input);

  WordCounter wc;
  // Set min length to 4 to allow shorter example words in the tests
  wc._minLength = 4;

  ASSERT_EQ(0, wc.getNumWords());

  wc.readFile(std::string("WordCounterTest.tmp"));
  ASSERT_EQ(7, wc.getNumWords());
  ASSERT_EQ(3, wc.getWordCount("ring"));
  ASSERT_EQ(1, wc.getWordCount("rule"));
  ASSERT_EQ(4, wc.getWordCount("them"));
  ASSERT_EQ(1, wc.getWordCount("find"));
  ASSERT_EQ(1, wc.getWordCount("bring"));
  ASSERT_EQ(1, wc.getWordCount("darkness"));
  ASSERT_EQ(1, wc.getWordCount("bind"));

  unlink("WordCounterTest.tmp");
}

TEST(WordCounter, readInvalidFile) {
  WordCounter wc;
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(wc.readFile(std::string("InvalidFile")),
               "Error opening file: .*");
}

TEST(WordCounter, computeFrequentWords) {
  WordCounter wc;
  // Set min length to 4 to allow shorter example words in the tests
  wc._minLength = 4;

  ASSERT_EQ(0, wc.getNumWords());

  std::vector<std::pair<std::string, size_t> > result;
  // Set the number of results to 1
  wc._topK = 1;
  result = wc.computeFrequentWords();
  ASSERT_EQ(0, result.size());

  std::vector<std::string> words;
  words.push_back(std::string("ring"));
  words.push_back(std::string("ring"));
  words.push_back(std::string("ring"));
  words.push_back(std::string("ring"));
  words.push_back(std::string("ring"));
  words.push_back(std::string("bring"));
  words.push_back(std::string("bring"));
  words.push_back(std::string("darkness"));
  words.push_back(std::string("darkness"));
  words.push_back(std::string("darkness"));
  wc.updateWordCounts(words);
  ASSERT_EQ(3, wc.getNumWords());
  ASSERT_EQ(5, wc.getWordCount("ring"));
  ASSERT_EQ(2, wc.getWordCount("bring"));
  ASSERT_EQ(3, wc.getWordCount("darkness"));

  result = wc.computeFrequentWords();
  ASSERT_EQ(1, result.size());
  ASSERT_STREQ("ring", result[0].first.c_str());
  ASSERT_EQ(5, result[0].second);

  // Set the number of results to 3
  wc._topK = 3;
  result = wc.computeFrequentWords();
  ASSERT_EQ(3, result.size());
  ASSERT_STREQ("ring", result[0].first.c_str());
  ASSERT_EQ(5, result[0].second);
  ASSERT_STREQ("darkness", result[1].first.c_str());
  ASSERT_EQ(3, result[1].second);
  ASSERT_STREQ("bring", result[2].first.c_str());
  ASSERT_EQ(2, result[2].second);

  // Set the number of results to 100
  wc._topK = 100;
  result = wc.computeFrequentWords();
  ASSERT_EQ(3, result.size());
  ASSERT_STREQ("ring", result[0].first.c_str());
  ASSERT_EQ(5, result[0].second);
  ASSERT_STREQ("darkness", result[1].first.c_str());
  ASSERT_EQ(3, result[1].second);
  ASSERT_STREQ("bring", result[2].first.c_str());
  ASSERT_EQ(2, result[2].second);
}

