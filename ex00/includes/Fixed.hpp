#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class fixedPoint {
    private:
        int                 _fixedPoint;
        static const int    _scale = 8;
    public:
        fixedPoint();
        ~fixedPoint();
        fixedPoint(const fixedPoint &src);
        fixedPoint  &operator=(const fixedPoint &src);
        int         getRawBits(void) const;
        void        setRawBits(int const raw);
};

#endif