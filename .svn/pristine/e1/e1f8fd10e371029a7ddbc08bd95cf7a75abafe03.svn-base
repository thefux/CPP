/*
 * copyright Abderrahmen Rakez
 *              
 * */
#include <iostream>
#include "./approximationEulersNumber.h"


// _______________________________________________________________________
double approximationEulersNumber::approximationEulerNumber(const int a) {
    double num = 1.0;
    double apporximation = 1.0;

    if (a == 0) {
        return 1;
    }

    for (int i = 1; i != a+1; ++i) {
        num *= 1.0/i;
        apporximation += num;
    }

    return apporximation;
}
