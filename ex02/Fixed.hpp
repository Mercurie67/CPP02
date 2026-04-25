/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:46 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:46 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <math.h>

class Fixed
{
    private:
        int _rawBits;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits (void) const;
        void setRawBits(const int raw);

        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed operator+(const Fixed&other) const; 
        Fixed operator-(const Fixed&other) const;
        Fixed operator*(const Fixed&other) const;
        Fixed operator/(const Fixed&other) const;

        Fixed &operator++( void );
        Fixed &operator--( void );
        Fixed operator++( int );
        Fixed operator--( int );

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

#endif

