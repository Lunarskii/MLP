#include <iostream>

#include "common/strategy.h"


int main() {

    A a;
    std::cout << a.l << '\n';
    a.l = 5; // ERROR
    a.SetL(5);
    std::cout << a.l << '\n';
    
    return 0;
}
