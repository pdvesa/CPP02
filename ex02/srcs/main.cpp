#include <Fixed.hpp>

int main(void) {
    fixedPoint a;
    fixedPoint const b(fixedPoint(5.05f) * fixedPoint(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << fixedPoint::max( a, b ) << std::endl;
    return 0;
}