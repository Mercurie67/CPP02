/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:18 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:18 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits (void) const;
        void setRawBits(int const raw);
};

#endif

