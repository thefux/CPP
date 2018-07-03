/*
 * copyright Abderrahmen Rakez
 *              
 * */
#include <iostream>

/* this function is use to find the Euler approximation of any number   */
double approximationEulerNumber(const int a) {
    double num = 1.0;
    double apporximation = 2.0;

    if (a == 0) {
        return 1;
    }

    for (int i = 2; i != a+1; ++i) {
        num *= 1.0/i;
        apporximation += num;
    }

    return apporximation;
}
