/*
 * copyright Abderrahmen Rakez
 *      		
 * */

#include <iostream>
#include <iomanip>
#include "./approximationEulersNumber.cpp"

int main(void) {
    double a =  approximationEulerNumber(10);
    std::cout << std::setprecision(10) << a  << std::endl;
    std::cout << std::setprecision(10) << approximationEulerNumber(11)
        << std::endl;
    std::cout << std::setprecision(10) << approximationEulerNumber(9)
        << std::endl;

    return 0;
}
