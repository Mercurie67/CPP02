/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:42 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:42 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int value)
{
    _rawBits = value << _bits;
}

Fixed::Fixed(const float value)
{
    _rawBits = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_rawBits / (1 << _bits);
}

int Fixed::toInt(void) const
{
    return _rawBits / (1 << _bits);
}

bool Fixed::operator>(const Fixed &other) const
{
    return _rawBits > other._rawBits;
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
    return _rawBits == other._rawBits;
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
    result._rawBits = this->_rawBits + other._rawBits;
    return (result);
}

Fixed Fixed::operator-(const Fixed&other) const
{
    Fixed result;
    result._rawBits = this->_rawBits - other._rawBits;
    return (result);
}

Fixed Fixed::operator*(const Fixed&other) const
{
    Fixed result;
    result._rawBits = (long)_rawBits * other._rawBits >> _bits;
    return (result);
}

Fixed Fixed::operator/(const Fixed&other) const
{
    if (other._rawBits == 0)
    {
        std::cout << "Error: division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result._rawBits = ((long)_rawBits << _bits) / other._rawBits;
    return result;
}

Fixed &Fixed::operator++( void )
{
    _rawBits++;
    return *this;
}

Fixed &Fixed::operator--( void )
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _rawBits++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _rawBits--;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}