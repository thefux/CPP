/*
 * copyright Abderrahmen Rakez 
 * 
 * */
#ifndef MARKETSIMULATOR_H_
#define MARKETSIMULATOR_H_

#include <gtest/gtest.h>
#include "./Trader.h"

class Trader;
class MarketSimulator {
 private:
     // file name
     const char* _inputFileName;

     // print statistics in true
     bool _verbose;

     // money after sold or buy
     float _money;

     // capital
     float _seedMoney;

     // number of bitcoins
     int _assets;

     int _lastPrices[4];

     // print usage if the wrong arguments are used
     void printUsageAndExit(void) const;
     FRIEND_TEST(MarketSimulatorTest, printUsageAndExit);

 public:
     // constructor
     MarketSimulator();
     FRIEND_TEST(MarketSimulatorTest, constructor);

     // simulate from Trader class
     void simulate(Trader *trader) const;
     FRIEND_TEST(MarketSimulatorTest, simulateCantOpenInputFile);
     FRIEND_TEST(MarketSimulatorTest, simulateSimpleTraderInteraction);

     // parse user argument
     void parseCommandLineArguments(int argc, char** argv);
     FRIEND_TEST(MarketSimulatorTest, parseCommandLineArgumentsNoArguments);
     FRIEND_TEST(MarketSimulatorTest, parseCommandLineArguments);
     FRIEND_TEST(MarketSimulatorTest, parseCommandLineArgumentsSetFunds);

     // read file content
     // void processFile();
};

#endif  // MARKETSIMULATOR_H_
