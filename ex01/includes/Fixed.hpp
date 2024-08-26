#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class fixedPoint {
    private:
        int                 _fixedPoint;
        static const int    _scale = 8;
    public:
        fixedPoint();
        fixedPoint(const int n);
        fixedPoint(const float f);
        ~fixedPoint();
        fixedPoint(const fixedPoint &src);
        fixedPoint  &operator=(const fixedPoint &src);
        int         getRawBits(void) const;
        void        setRawBits(int const raw);
        float       toFloat(void) const;
        int         toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, const fixedPoint &fixed);

#endif