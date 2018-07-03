// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./Trader.h"

// _____________________________________________________________________________
TEST(TraderTest, constructor) {
  Trader trader;
  ASSERT_FALSE(trader._verbose);
  ASSERT_FLOAT_EQ(0, trader._money);
  ASSERT_FLOAT_EQ(0, trader._seedMoney);
  ASSERT_EQ(0, trader._assets);
  ASSERT_FLOAT_EQ(0, trader._lastPrices[0]);
  ASSERT_FLOAT_EQ(0, trader._lastPrices[1]);
  ASSERT_FLOAT_EQ(0, trader._lastPrices[2]);
}

// _____________________________________________________________________________
TEST(TraderTest, trade) {
  Trader trader;
  trader._money = 5;
  // Buy after 3 raising ticks.
  trader.trade(0);
  ASSERT_FLOAT_EQ(5, trader._money);
  ASSERT_FLOAT_EQ(0, trader._assets);
  trader.trade(0.1);
  ASSERT_FLOAT_EQ(5, trader._money);
  ASSERT_FLOAT_EQ(0, trader._assets);
  trader.trade(0.2);
  ASSERT_FLOAT_EQ(5, trader._money);
  ASSERT_FLOAT_EQ(0, trader._assets);
  trader.trade(1);
  ASSERT_FLOAT_EQ(4, trader._money);
  ASSERT_FLOAT_EQ(1, trader._assets);
  trader.trade(2);
  ASSERT_FLOAT_EQ(2, trader._money);
  ASSERT_FLOAT_EQ(2, trader._assets);
  // Would buy but not enough money.
  trader.trade(3);
  ASSERT_FLOAT_EQ(2, trader._money);
  ASSERT_FLOAT_EQ(2, trader._assets);

  // Sell after 3 falling ticks.
  trader.trade(20);
  ASSERT_FLOAT_EQ(2, trader._money);
  ASSERT_FLOAT_EQ(2, trader._assets);
  trader.trade(15);
  ASSERT_FLOAT_EQ(2, trader._money);
  ASSERT_FLOAT_EQ(2, trader._assets);
  trader.trade(10);
  ASSERT_FLOAT_EQ(2, trader._money);
  ASSERT_FLOAT_EQ(2, trader._assets);
  trader.trade(5);
  ASSERT_FLOAT_EQ(7, trader._money);
  ASSERT_FLOAT_EQ(1, trader._assets);
  trader.trade(4);
  ASSERT_FLOAT_EQ(11, trader._money);
  ASSERT_FLOAT_EQ(0, trader._assets);
  // Would sell, but no more assets.
  trader.trade(4);
  ASSERT_FLOAT_EQ(11, trader._money);
  ASSERT_FLOAT_EQ(0, trader._assets);

  // Do nothing if fluctuating.
  trader._money = 20;
  trader._assets = 20;
  trader.trade(16);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
  trader.trade(14);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
  trader.trade(16);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
  trader.trade(14);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
  trader.trade(16);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
  trader.trade(14);
  ASSERT_FLOAT_EQ(20, trader._money);
  ASSERT_FLOAT_EQ(20, trader._assets);
}
