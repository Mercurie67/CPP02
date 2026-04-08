#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) 
{
    (void)other;
    return (*this);
}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
    return _x;
}
Fixed Point::getY(void) const
{
    return _y;
}