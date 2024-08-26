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
        bool        operator>(const fixedPoint &comparison) const;
        bool        operator>=(const fixedPoint &comparison) const;
        bool        operator<(const fixedPoint &comparison) const;
        bool        operator<=(const fixedPoint &comparison) const;
        bool        operator==(const fixedPoint &comparison) const;
        bool        operator!=(const fixedPoint &comparison) const;
        fixedPoint  operator+(const fixedPoint &add) const;
        fixedPoint  operator-(const fixedPoint &subtract) const;
        fixedPoint  operator*(const fixedPoint &multi) const;
        fixedPoint  operator/(const fixedPoint &divide) const;
        fixedPoint  &operator++();
        fixedPoint  operator++(int);
        fixedPoint  &operator--();
        fixedPoint  operator--(int);
        static fixedPoint &max(fixedPoint &a, fixedPoint &b);
        static fixedPoint &min(fixedPoint &a, fixedPoint &b);
		static const fixedPoint &max(const fixedPoint &a, const fixedPoint &b);
        static const fixedPoint &min(const fixedPoint &a, const fixedPoint &b);
};

std::ostream &operator<<(std::ostream &stream, const fixedPoint &fixed);

#endif