#include <Fixed.hpp>

fixedPoint::fixedPoint() : _fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}


fixedPoint::~fixedPoint() {
    std::cout << "Destructor Called" << std::endl;
}

//fixedPoint::fixedPoint(const fixedPoint &src) : _fixedPoint(src._fixedPoint) {
//    std::cout << "Copy Constructor Called" << std::endl;
//}

fixedPoint::fixedPoint(const fixedPoint &src) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

fixedPoint& fixedPoint::operator=(const fixedPoint &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &src)
		return (*this);
	this->_fixedPoint = src.getRawBits();
	return (*this);
}

int fixedPoint::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return(_fixedPoint);
}

void fixedPoint::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}