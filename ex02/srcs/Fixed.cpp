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
    return (_fixedPoint);
}

void fixedPoint::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}

int fixedPoint::toInt() const {
	return (_fixedPoint >> _scale);
}

float fixedPoint::toFloat() const {
	return ((float)_fixedPoint / (float)(1 << _scale));
}

bool fixedPoint::operator>(const fixedPoint &comparison) const {
    return (_fixedPoint > comparison._fixedPoint);
}

bool fixedPoint::operator>=(const fixedPoint &comparison) const {
    return (_fixedPoint >= comparison._fixedPoint);
}

bool fixedPoint::operator<(const fixedPoint &comparison) const {
    return (_fixedPoint < comparison._fixedPoint);
}

bool fixedPoint::operator<=(const fixedPoint &comparison) const {
    return (_fixedPoint <= comparison._fixedPoint);
}

bool fixedPoint::operator==(const fixedPoint &comparison) const {
    return (_fixedPoint == comparison._fixedPoint);
}

bool fixedPoint::operator!=(const fixedPoint &comparison) const {
    return (_fixedPoint != comparison._fixedPoint);
}

fixedPoint fixedPoint::operator+(const fixedPoint &add) const {
    fixedPoint ret(*this);
    ret._fixedPoint += add._fixedPoint;
    return (ret);
}

fixedPoint fixedPoint::operator-(const fixedPoint &subtract) const {
    fixedPoint ret(*this);
    ret._fixedPoint -= subtract._fixedPoint;
    return (ret);
}

fixedPoint fixedPoint::operator*(const fixedPoint &multi) const {
   fixedPoint ret(*this);
   ret._fixedPoint *= multi._fixedPoint / (1 <<_scale);
   return (ret);
}

fixedPoint fixedPoint::operator/(const fixedPoint &divide) const {
    fixedPoint ret(*this);
    ret._fixedPoint /= divide._fixedPoint * (1 <<_scale);
    return (ret);
}

fixedPoint& fixedPoint::operator++() {
    ++_fixedPoint;
    return (*this);
}

fixedPoint fixedPoint::operator++(int) {
    fixedPoint  temp(*this);
    _fixedPoint = _fixedPoint + 1;
    return (temp);
}

fixedPoint& fixedPoint::operator--() {
    _fixedPoint--;
    return (*this);
}

fixedPoint fixedPoint::operator--(int) {
    fixedPoint  temp(*this);
    _fixedPoint -= 1; //testing stuff
    return (temp);
}

fixedPoint& fixedPoint::max(fixedPoint &a, fixedPoint &b) {
    return ((a > b) ? a : b);
}

fixedPoint& fixedPoint::min(fixedPoint &a, fixedPoint &b) {
    return ((a < b) ? a : b);
}

const fixedPoint& fixedPoint::max(const fixedPoint &a, const fixedPoint &b) {
    return ((a > b) ? a : b);
}

const fixedPoint& fixedPoint::min(const fixedPoint &a, const fixedPoint &b) {
    return ((a < b) ? a : b);
}

std::ostream &operator<<(std::ostream &stream, const fixedPoint &fixed) {
	stream << fixed.toFloat();
	return (stream);
}

//fixedPoint fixedPoint::operator*(const fixedPoint &multi) const {
//     return fixedPoint(((this->_fixedPoint * multi._fixedPoint) / (1 <<_scale)));
//}
