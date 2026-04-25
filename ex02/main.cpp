/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:54:49 by medel-ca          #+#    #+#             */
/*   Updated: 2026/04/25 16:54:49 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c = Fixed::max( a, b );
	Fixed d(5.05f);

	std::cout << "Valor de a: " << a << std::endl; 
	std::cout << "Valor de ++a: " << ++a << std::endl;
	std::cout << "Valor de a: " << a << std::endl;
	std::cout << "Valor de a++: " << a++ << std::endl;
	std::cout << "Valor de a: " << a << std::endl;

	std::cout << "Valor de b: " <<b << std::endl;
	std::cout << "Valor de --b: " <<--b << std::endl;
	std::cout << "Valor de b: " <<b << std::endl;
	std::cout << "Valor de b--: " <<b-- << std::endl;
	std::cout << "Valor de b: " <<b << std::endl;

	std::cout << "Valor de a * b: " << a * b << std::endl;
	std::cout << "Valor de a + b: " <<a + b << std::endl;
	std::cout << "Valor de a - b: " <<a - b << std::endl;
	std::cout << "Valor de a / b: " << a / b << std::endl;

	std::cout << "El valor mayor es: " << Fixed::max( a, b ) << std::endl;
	std::cout << std::boolalpha;
	std::cout << "¿Son estos números iguales? " << (a == b) << std::endl;
	std::cout << "¿Son estos números diferentes? " << (a != b) << std::endl;

	return 0;
}