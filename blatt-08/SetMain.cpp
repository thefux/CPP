/*
 * copyright Abderrahmen Rakez
 *
 * */

#include <iostream>
#include "Set.h"


int main(void) {
    Set<int> s;
    s.insert(129);
    s.insert('\x81');
    s.insert('\x82');
    std::cout << "found \n" << s.lookup(129) << std::endl;
    std::cout << "found \n" << s.lookup('\x81') << std::endl;
    std::cout << "found \n" << s.lookup('\x82') << std::endl;
    return 0;
}
