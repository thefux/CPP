// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./MarketSimulator.h"
#include "./Trader.h"

// _____________________________________________________________________________
TEST(MarketSimulatorTest, constructor) {
  MarketSimulator market;
  ASSERT_STREQ("", market._inputFileName);
  ASSERT_EQ(0, market._seedMoney);
  ASSERT_FALSE(market._verbose);
}

// _____________________________________________________________________________
TEST(MarketSimulatorTest, parseCommandLineArgumentsNoArguments) {
  MarketSimulator market;
  int argc = 1;
  char* argv[1] = {
    const_cast<char*>("")
  };
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(market.parseCommandLineArguments(argc, argv), "Usage: .*");
}

// _____________________________________________________________________________
TEST(MarketSimulatorTest, parseCommandLineArguments) {
  MarketSimulator market;
  int argc = 2;
  char* argv[2] = {
    const_cast<char*>(""),
    const_cast<char*>("myInputFile")
  };
  market.parseCommandLineArguments(argc, argv);
  ASSERT_STREQ("myInputFile", market._inputFileName);
  ASSERT_FLOAT_EQ(1000, market._seedMoney);
}
// _____________________________________________________________________________
TEST(MarketSimulatorTest, parseCommandLineArgumentsSetFunds) {
  MarketSimulator market;
  int argc = 4;
  char* argv[4] = {
    const_cast<char*>(""),
    const_cast<char*>("--seed-money"),
    const_cast<char*>("1337"),
    const_cast<char*>("myInputFile")
  };
  market.parseCommandLineArguments(argc, argv);
  ASSERT_STREQ("myInputFile", market._inputFileName);
  ASSERT_FLOAT_EQ(1337, market._seedMoney);
}
// _____________________________________________________________________________
TEST(MarketSimulatorTest, printUsageAndExit) {
  MarketSimulator market;
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(market.printUsageAndExit(), "Usage: .*");
}
// _____________________________________________________________________________
TEST(MarketSimulatorTest, simulateCantOpenInputFile) {
  MarketSimulator market;
  Trader trader;
  market._inputFileName = "doesNotExist";
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(market.simulate(&trader), "Error: Could not open input .*");
}
// _____________________________________________________________________________
TEST(MarketSimulatorTest, simulateSimpleTraderInteraction) {
  MarketSimulator market;
  Trader trader;
  market._inputFileName = "inputTest.csv";
  market._verbose = false;
  market._seedMoney = 10;
  FILE* inputFile = fopen(market._inputFileName, "w");
  fprintf(inputFile, "lorem,0.5\nipsum,0.6,dolor\nsit,1.0\namet,2.0\n");
  fclose(inputFile);
  market.simulate(&trader);
  ASSERT_EQ(2, trader._assets);
  ASSERT_FLOAT_EQ(7, trader._money);
  unlink(market._inputFileName);
}
