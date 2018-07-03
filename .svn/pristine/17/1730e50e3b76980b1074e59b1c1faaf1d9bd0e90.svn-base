/*
 * copyright Abderrahmen Rakez
 *
 * */

#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

class WordCounter {
 private:
     // file name
     std::string _inputFileName;

     // store elements and frequency
     std::unordered_map<std::string, std::size_t> _elementAndFrequency;

     // min lenght of word
     std::size_t _minLength;

     // word counter
     std::size_t _counter;

     // output
     std::size_t _topK;

     // print usage if argument does not match
     void printUsageAndExit(void) const;

     // increase counter
     void updateWordCounts(const std::vector<std::string> str);
     FRIEND_TEST(WordCounter, updateWordCounts);

     // return the occurrence of the given word
     const std::size_t getWordCount(const std::string s);
     FRIEND_TEST(WordCounter, getSizeAndGetWordCount);

     // return the number of stored words
     const std::size_t getNumWords(void) const;

     // return the word and the frequency
     std::vector<std::pair<std::string, std::size_t> >
         computeFrequentWords(void) const;
     FRIEND_TEST(WordCounter, computeFrequentWords);

 public:
     // constructor
     WordCounter();

     // read file: no used
     void readFile(std::string str);
     FRIEND_TEST(WordCounter, readFile);
     FRIEND_TEST(WordCounter, readInvalidFile);

     // process command line
     void processCommandLineArguments(int argc, char** argv);

     // process file
     void process(void);
};

#endif  // WORDCOUNTER_H_
