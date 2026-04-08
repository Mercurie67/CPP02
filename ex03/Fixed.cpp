#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(const int value)
{
    rawBits = value << bits;
}

Fixed::Fixed(const float value)
{
    rawBits = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits) {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (*this != other)
        rawBits = other.rawBits;
    return (*this);
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const
{
    return (rawBits);
}
void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (float)rawBits / (1 << bits);
}

int Fixed::toInt(void) const
{
    return rawBits / (1 << bits);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (rawBits > other.rawBits);
}
bool Fixed::operator<(const Fixed &other) const
{
    return other > *this;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return !(*this < other);
}
bool Fixed::operator<=(const Fixed &other) const
{
    return !(*this > other);
}
bool Fixed::operator==(const Fixed &other) const
{
    return (rawBits == other.rawBits);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return !(*this == other);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed Fixed::operator+(const Fixed&other) const
{
    Fixed result;
    result.rawBits = this->rawBits + other.rawBits;
    return (result);
}

Fixed Fixed::operator-(const Fixed&other) const
{
    Fixed result;
    result.rawBits = this->rawBits - other.rawBits;
    return (result);
}

Fixed Fixed::operator*(const Fixed&other) const
{
    Fixed result;
    result.rawBits = (long)rawBits * other.rawBits >> bits;
    return (result);
}

Fixed Fixed::operator/(const Fixed&other) const
{
    if (other.rawBits == 0)
    {
        std::cout << "Error: division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.rawBits = ((long)rawBits << bits) / other.rawBits;
    return (result);
}

Fixed &Fixed::operator++( void )
{
    rawBits++;
    return (*this);
}

Fixed &Fixed::operator--( void )
{
    rawBits--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    rawBits++;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    rawBits--;
    return (temp);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}