/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:14 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:14 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other._rawBits;
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
    return _rawBits;
}
void Fixed::setRawBits(const int raw)
{
    _rawBits = raw;
}