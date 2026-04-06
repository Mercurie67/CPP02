#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = value << bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = other.rawBits;
    return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy Assignment operator called" << std::endl;
    this->rawBits = other.rawBits;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (rawBits);
}
void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)rawBits / (1 << bits);
}
int Fixed::toInt( void ) const
{
    return (int)rawBits / (1 << bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
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
static const Fixed &min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}
static const Fixed &max(const Fixed &a, const Fixed b)
{
    return (a > b) ? a : b;
}

static Fixed &min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}
static Fixed &max(Fixed &a, Fixed b)
{
    return (a > b) ? a : b;
}