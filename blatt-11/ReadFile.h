/*
 * copyright Abderrahmen Rakez
 *
 * */

#ifndef READFILE_H_
#define READFILE_H_

#include <utility>
#include <string>

class ReadFile {
 private:
     std::pair<unsigned int, unsigned int> _coordination;

     // file name
     std::string _fileName;

     // filed size
     unsigned int _fieldSize;

     // exist usage
     void printUsageAndExit(void) const;

 public:
     ReadFile();

     // process arguments
     void processCommandLineArguments(int argc, char**argv);


     // extract data from file
     void extractCoordination(void);
};

#endif  // READFILE_H__
