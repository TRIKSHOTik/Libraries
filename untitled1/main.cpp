#include <iostream>
#include <ostream>

#include "Number.h"
#include "Vector.h"

int main() {
    Number a = createNumber(13.0);
    Number b = createNumber(23.0);

    std::cout << a << std ::endl;
    std::cout << b+a << std ::endl;
    std::cout << a+b << std ::endl;
    std::cout << ONE << std ::endl;
    a += b;
    std::cout << a << std ::endl;

    Vector col(a, b);
    std::cout << col << std ::endl;
    std::cout << col.toPolarCoordRho() << std ::endl;
    std::cout << col.toPolarCoordPhi() << std ::endl;
    std::cout << col << std ::endl;
    std::cout << NULL_VECTOR << std ::endl;
    std::cout << UNIT_VECTOR << std ::endl;
    std::cout << col + col << std ::endl;
}