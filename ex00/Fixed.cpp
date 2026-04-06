#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other)
        this->rawBits = other.rawBits;
    return *this;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}
void Fixed::setRawBits(const int raw)
{
    rawBits = raw;
}