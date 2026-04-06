#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <math.h>

class Fixed
{
    private:
        int rawBits;
        static const int bits = 8;
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

        Fixed &operator+(const Fixed&other); 
        Fixed &operator-(const Fixed&other);
        Fixed &operator*(const Fixed&other);
        Fixed &operator/(const Fixed&other);

        Fixed &fixed++( void );
        Fixed &fixed--( void );

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

