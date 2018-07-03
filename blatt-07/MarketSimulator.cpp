/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include "./MarketSimulator.h"
#include "./Trader.h"
// static library is used
#include "./StringClass/String.h"

/* constructor [[*/
// __________________________________________________________________________
MarketSimulator::MarketSimulator() {
    // initialize the value
    _inputFileName = "";
    _seedMoney = 0;
    _verbose = false;
}
/*]]*/

/* parseCommandLineArguments [[*/
// __________________________________________________________________________
void MarketSimulator::parseCommandLineArguments(int argc, char** argv) {
    // options
    struct option long_options[] = {
        {"seed-money", 1, NULL, 's'},
        {"verbose", 0, NULL, 'n'},
        {NULL, 0, NULL, 0}
    };

    optind = 1;
    // analyze the given argument
    while (true) {
        char choice = getopt_long(argc, argv, "s:n", long_options, NULL);
        if (choice == -1) {
            break;
        }
        switch (choice) {
            case 's':
                _seedMoney = atof(optarg);
                break;
            case 'n':
                _verbose = true;
                break;
        }
    }
    // if not enough arguments are given
    if (optind + 1 != argc) {
        printUsageAndExit();
    }
    if (optind == 1) {
        _seedMoney = 1000;
    }
    // the remaining argument is the name of the file
    _inputFileName = argv[optind];
}
/*]]*/

/* simulate [[*/
// __________________________________________________________________________
void MarketSimulator::simulate(Trader *trader) const {
    // open file to read
    FILE* file = fopen(_inputFileName, "r");
    // initialize String objects to save and interpret data
    String h;
    String str[2];
    // initialize trader capital
    trader->_seedMoney = _seedMoney;
    trader->_money = _seedMoney;
    trader->_verbose = _verbose;
    if (file) {
        while (true) {
            // set max length
            const int kMaxLineLength = 100;
            char line[kMaxLineLength + 1];

            // read line by line
            fgets(line, kMaxLineLength, file);

            // break if end of file is reached
            if (feof(file)) { break; }

           /* 
            * use String object to analyze each line 
            */
            // set string
            h.set(line);

            // split string
            h.split(',', 2, str);

            // catch the coasts and give it to trader function
            // to make decision about buying or sold
            float coast = str[1].toFloat();
            trader->trade(coast);
            if (_verbose) {
                printf("buy or sold bitcoins: price %f, asset %d, money %f\n"
                        , coast, trader->_assets, trader->_money);
            }
        }
        // close file
        fclose(file);
    } else {
        // error if file does not exist
        perror("Error: Could not open input .*");
        exit(1);
    }
    trader->printStatistics();
}/*]]*/

/* printUsageAndExit [[*/
// __________________________________________________________________________
void MarketSimulator::printUsageAndExit(void) const {
    // print usage if argument does not match the expected one
    fprintf(stderr,
            "Usage: ./MarketSimulatorMain [option] <filename> \n"
            "-s, --seed-money=N : seed capital\n"
            "-n, --verbose : do case\n");
    exit(1);
}
/*]]*/

/* processFile [[*/
// __________________________________________________________________________
// void MarketSimulator::processFile() {
//     FILE* file = fopen(_inputFileName, "r");
//     if (file == NULL) {
//         perror("error opening file");
//         exit(1);
//     }
//     while (true) {
//         const int kMaxLineLength = 1000;
//         char line[kMaxLineLength + 1];
//         fgets(line, kMaxLineLength, file);
//         if (feof(file)) { break;}
//         printf("%s", line);
//     }
//     fclose(file);
// }
/*]]*/
