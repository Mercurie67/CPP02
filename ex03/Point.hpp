/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:55:53 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:55:53 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
    Fixed const _x;
    Fixed const _y;
    public:
        Point(void);
        Point(float const x, float const y);
        Point(const Point& other);
        Point &operator=(const Point &other);
        Fixed getX(void) const;
        Fixed getY(void) const;
        ~Point();
};

#endif

