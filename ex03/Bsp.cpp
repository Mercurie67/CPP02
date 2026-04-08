#include "Bsp.hpp"

//Calcular vectores ab y ac (b.x - a.x, b.y - a.y)
//Producto cruzado (área orientada) (ab.x * ac.y) - (ab.y - ac.x)
static Fixed area(Point const a, Point const b, Point const c)
{
    return (b.getX() - a.getX()) * (c.getY() - a.getY()) -
           (b.getY() - a.getY()) * (c.getX() - a.getX());
}
//Comparar signos de las áreas orientadas entre 2 vértices del triángulo y el punto.
//Mismo signo: el punto está dentro
//Distinto signo: el punto está fuera
//0 si está en la arista
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