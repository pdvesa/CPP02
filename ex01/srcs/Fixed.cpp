#include <Fixed.hpp>

fixedPoint::fixedPoint() : _fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

fixedPoint::fixedPoint(const int n) : _fixedPoint(n << _scale) {
     std::cout << "Int constructor called" << std::endl;
}

fixedPoint::fixedPoint(const float f) : _fixedPoint(roundf(f * (float)(1 << _scale))) {
     std::cout << "Float constructor called" << std::endl;
}

fixedPoint::~fixedPoint() {
    std::cout << "Destructor Called" << std::endl;
}

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

int fixedPoint::toInt() const
{
	return (_fixedPoint >> _scale);
}

float fixedPoint::toFloat() const
{
	return ((float)_fixedPoint / (float)(1 << _scale));
}

std::ostream &operator<<(std::ostream &stream, const fixedPoint &fixed) {
	stream << fixed.toFloat();
	return (stream);
}