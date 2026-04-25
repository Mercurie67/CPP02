/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:29 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:29 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}
void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)_rawBits / (1 << _bits);
}
int Fixed::toInt( void ) const
{
    return _rawBits / (1 << _bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}