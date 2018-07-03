/*
 * copyright Abderrahmen Rakez 
 * 
 * */

#include <math.h>
#include "./Trader.h"

/* constructor [[*/
// _____________________________________________________________
Trader::Trader() {
    _verbose = false;
    _seedMoney = 0.0;
    _money = _seedMoney;
    _assets = 0;
    _lastPrices[0] = 0.0;
    _lastPrices[1] = 0.0;
    _lastPrices[2] = 0.0;
    _lastPrices[3] = 0.0;
}
/*]]*/

/* trade [[*/
// _____________________________________________________________
void Trader::trade(float x) {
    // x tells the coast of bitcoins
    // store x always at last position and shift the array
    _lastPrices[0] = _lastPrices[1];
    _lastPrices[1] = _lastPrices[2];
    _lastPrices[2] = _lastPrices[3];
    _lastPrices[3] = x;

    // count rise and fall of price
    int countRise = 0;
    int countFall = 0;
    // all the elements of _lastPrices has to be different from 0
    // check and assume that the new price never back to zero
    if (_lastPrices[3] != 0) {
        for (int i = 0; i < 3; ++i) {
            if (_lastPrices[i] < _lastPrices[i + 1]) {
                countRise++;
            } else {
                countFall++;
            }
        }
        // cases of fall and rise of prices
        if (countFall == 3) {
            // check if enough bitcoins
            if (_assets > 0) {
                _money += x;
                _assets--;
            }
        }
        if (countRise == 3) {
            // check if _money were enough to buy
            if (static_cast<float>(_money) > x) {
                _money -= x;
                _assets++;
            }
        }
    }
}
/*]]*/

/* printStatistics [[*/
// _____________________________________________________________
void Trader::printStatistics(void) const {
    printf("absolute win: %f\n", (_money - _seedMoney));
    printf("relative win: %f\n", (_money / _seedMoney));
}
/*]]*/
