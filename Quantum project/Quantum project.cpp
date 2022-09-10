#include <iostream>
#include "State.h"

int main()
{
    state v1(5, true);
    v1.show();
    state v2(5, true);
    v2.show();
    v1.conjugate();
    std::cout << std::endl << (v1 ^ v2);
    
    
    return 0;
}