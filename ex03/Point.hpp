#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
    Fixed const _x;
    Fixed const _y;
    public:
        Point(void);
        Point(float const x, float const y);
        Point(const Point& other);
        Point &operator=(const Point &other);
        Fixed getX(void) const;
        Fixed getY(void) const;
        ~Point();
};

#endif

