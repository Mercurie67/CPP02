/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:55 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:55 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bsp.hpp"

/// @brief Calcular vectores ab y ac (b.x - a.x, b.y - a.y). Producto cruzado (área orientada) (ab.x * ac.y) - (ab.y - ac.x)
static Fixed area(Point const a, Point const b, Point const c)
{
    return (b.getX() - a.getX()) * (c.getY() - a.getY()) -
           (b.getY() - a.getY()) * (c.getX() - a.getX());
}

/// @brief  Compara la orientación (signo) de las áreas entre 2 vértices del triángulo y el punto
///         Mismo signo: dentro / Distinto: fuera / 0 = en la arista
/// @param  a b y c = Vértices del triángulo
/// @param point El punto
/// @return true = dentro / false = fuera
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = area(point, a, b);
    Fixed d2 = area(point, b, c);
    Fixed d3 = area(point, c, a);

    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    if (d1 < 0 && d2 < 0 && d3 < 0)
    	return true;
	else if (d1 > 0 && d2 > 0 && d3 > 0)
	    return true;
	else
 	   return false;
} 