/*
 * copyright Abderrahmen Rakez
 *
 * */

#include <getopt.h>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "./ReadFile.h"

/* constructor [[*/
// _____________________________________________________________________________
ReadFile::ReadFile() {
    // init fileName
    _fileName = "";
    // default sizeFiled
    _fieldSize = 10;
}
/*]]*/

/* processCommandLineArguments [[*/
// _____________________________________________________________________________
void ReadFile::processCommandLineArguments(int argc, char**argv) {
    // structure
    struct option long_options[] = {
        {"version", 1, 0, 'v'},
        {NULL, 0, NULL, 0}
    };


    // index
    optind = 1;
    // index check
    while (1) {
        char choice = getopt_long(argc, argv, "v:", long_options, NULL);

        if (choice == -1)
            break;

        switch (choice) {
            case 'v':
                std::cout << "hello v" << std::endl;
                break;

            case '?':
            default:
                printUsageAndExit();
        }
    }

    // check if enough arguments
    if (optind + 1 != argc) {
        printUsageAndExit();
    }

    // get fileName
    _fileName = argv[optind];
    std::cout << "fileName: " << _fileName << std::endl;
}
/*]]*/

/* printUsaggeAndExit [[*/
// _____________________________________________________________________________
void ReadFile::printUsageAndExit(void) const {
    std::cerr << "Error file not found: " << std::endl;
}
/*]]*/

/* extractCoordination [[*/
// _____________________________________________________________________________
void ReadFile::extractCoordination(void) {
    // read file
    std::ifstream file(_fileName);

    // check if exist or break
    if (!file.is_open()) {
        printUsageAndExit();
    }

    // while (true) {
    //
    // }
}
/*]]*/
