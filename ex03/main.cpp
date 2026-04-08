#include "Fixed.hpp"
#include "Point.hpp"
#include "Bsp.hpp"

int main()
{
    Point triangle[3] =	{
		Point(0, 0),
    	Point(5, 0),
    	Point(0, 5)
	};

    std::cout << "Triángulo: (0,0) (5,0) (0,5)\n";

    Point P1(1, 1);
    std::cout << "Punto: (1,1) → esperado: dentro → obtenido: "
              << (bsp(triangle[0], triangle[1], triangle[2], P1) ? "dentro" : "fuera") << std::endl;

    Point P2(5, 5);
    std::cout << "Punto: (5,5) → esperado: fuera → obtenido: "
              << (bsp(triangle[0], triangle[1], triangle[2], P2) ? "dentro" : "fuera") << std::endl;

    Point P3(0, 0);
    std::cout << "Punto: (0,0) → esperado: fuera → obtenido: "
              << (bsp(triangle[0], triangle[1], triangle[2], P3) ? "dentro" : "fuera") << std::endl;

    Point P4(2, 0);
    std::cout << "Punto: (2,0) → esperado: fuera → obtenido: "
              << (bsp(triangle[0], triangle[1], triangle[2], P4) ? "dentro" : "fuera") << std::endl << std::endl;

	Point triangle2[3] = {
		Point(-5, -5),
    	Point(0, 10),
    	Point(10, -5)
	};

    std::cout << "Triángulo: (-5,-5) (0,10) (10,-5)\n";

    Point P5(1, 1);
    std::cout << "Punto: (1,1) → esperado: dentro → obtenido: "
              << (bsp(triangle2[0], triangle2[1], triangle2[2], P5) ? "dentro" : "fuera") << std::endl;

    Point P6(0, 0);
    std::cout << "Punto: (0,0) → esperado: dentro → obtenido: "
              << (bsp(triangle2[0], triangle2[1], triangle2[2], P6) ? "dentro" : "fuera") << std::endl;

    Point P7(-10, 0);
    std::cout << "Punto: (-10,0) → esperado: fuera → obtenido: "
              << (bsp(triangle2[0], triangle[1], triangle2[2], P7) ? "dentro" : "fuera") << std::endl;

    Point P8(10, 10);
    std::cout << "Punto: (2,0) → esperado: fuera → obtenido: "
              << (bsp(triangle2[0], triangle2[1], triangle2[2], P8) ? "dentro" : "fuera") << std::endl << std::endl;
	
	Point triangle3[3] = {
		Point(0, -5),
    	Point(0, 10),
    	Point(0, 0)
	};

    std::cout << "Triángulo: (0,-5) (0,10) (0,0)\n";

    std::cout << "Punto: (1,1) → esperado: fuera → obtenido: "
              << (bsp(triangle3[0], triangle3[1], triangle3[2], P5) ? "dentro" : "fuera") << std::endl;

    std::cout << "Punto: (0,0) → esperado: fuera → obtenido: "
              << (bsp(triangle[0], triangle[1], triangle3[2], P6) ? "dentro" : "fuera") << std::endl;

    std::cout << "Punto: (-10,0) → esperado: fuera → obtenido: "
              << (bsp(triangle3[0], triangle3[1], triangle3[2], P7) ? "dentro" : "fuera") << std::endl;

    std::cout << "Punto: (2,0) → esperado: fuera → obtenido: "
              << (bsp(triangle3[0], triangle3[1], triangle3[2], P8) ? "dentro" : "fuera") << std::endl;
    return 0;
}

/*
	Un punto está dentro del triángulo si, visto desde cada vértice, 
	permanece dentro del ángulo formado por los lados adyacentes, 
	lo que equivale a comprobar que está en el mismo lado de las tres 
	rectas del triángulo
*/