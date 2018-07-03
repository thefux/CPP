/*
 * copyright Abderrahmen Rakez
 *              
 * */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "./approximationEulersNumber.h"

int main(void) {
    approximationEulersNumber approx;
    double a =  approx.approximationEulerNumber(10);
    double b =  approx.approximationEulerNumber(12);
    printf("Euler-Approximation\n");
    printf("Approximation for n = 10: %0.10f\n", a);
    printf("Approximation for n = 12: %0.10f\n", b);




    // std::cout << std::setprecision(10) << a  << std::endl;
    // std::cout << std::setprecision(10) << approx.approximationEulerNumber(15)
    //     << std::endl;

    return 0;
}
