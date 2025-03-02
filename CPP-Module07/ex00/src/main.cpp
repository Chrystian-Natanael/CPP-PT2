/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:16:34 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:27:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Whatever.hpp"
#include <iostream>

#define NL std::cout << std::endl;

void intTest(void) {
	int a = 2;
	int b = 3;

	NL;
	std::cout << RED << "Initial value of a: " << RST << a << std::endl;
	std::cout << RED << "Initial value of b: " << RST << b << std::endl;

	NL;
	std::cout << Y << "Swaping values of 'a' and 'b'." << RST << std::endl;
	::swap(a, b);

	std::cout << G << "Value of a after swap: " << a << RST << std::endl;
	std::cout << G << "Value of b after swap: " << b << RST << std::endl;

	NL;

	std::cout << Y << "Min value between 'a' and 'b'" << RST << std::endl;

	std::cout << G << "min( a, b ) = " << RST << ::min(a, b) << std::endl;
	NL;

	std::cout << Y << "Max value between 'a' and 'b'" << RST << std::endl;
	std::cout << G << "max( a, b ) = " << RST << ::max(a, b) << std::endl;
	NL;
}

void strTest(void) {
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << RED << "Initial value of c: " << RST << c << std::endl;
	std::cout << RED << "Initial value of d: " << RST << d << std::endl;
	NL;

	std::cout << Y << "Swaping values of 'c' and 'd'." << RST << std::endl;
	::swap(c, d);
	std::cout << G << "Value of c after swap: " << c << RST << std::endl;
	std::cout << G << "Value of d after swap: " << d << RST << std::endl;
	NL;

	std::cout << Y << "Min value between 'c' and 'd'" << RST << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	NL;

	std::cout << Y << "Max value between 'c' and 'd'" << RST << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void subjectTest(void) {
	NL;
	std::cout << "Test provided by subject" << std::endl;
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

int main(void) {
	intTest();
	strTest();
	subjectTest();
	return 0;
}

// !OTHER TESTS

// class Awesome
// {
// 	public:
// 		Awesome(void) : _n(0) {}
// 		Awesome( int n ) : _n( n ) {}
// 		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// 		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// 		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 		int get_n() const { return _n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
// 	Awesome a(2), b(4);
// 	swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }