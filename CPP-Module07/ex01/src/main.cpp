/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:38:27 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:45:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Iter.hpp"
#include <iostream>

#define NL std::cout << std::endl;

int main(void) {
  int nbs[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};
  char letter[] = {'f', 't', '*', 'w', 'h', 'y'};

  std::cout << G<< "Printing numbers: " << RST;
  iter(nbs, 12, print<int>);
  NL;

  std::cout << G<< "Printing chars: " << RST;
  iter(letter, 6, print<char>);
  NL;

  std::cout << G<< "Increment int values: " << RST;
  iter(nbs, 12, increment<int>);
  NL;

  std::cout << G<< "Increment char values: " << RST;
  iter(letter, 6, increment<char>);
  NL;

  std::cout << G<< "Odd or Even int values: " << RST << std::endl;
  iter(nbs, 12, oddEven<int>);
  NL;

  std::cout << G<< "Odd or Even char values: " << RST << std::endl;
  iter(letter, 6, oddEven<char>);
  NL;

  return 0;
}

// ! Other test

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
// 	o << rhs.get();
// 	return o;
// }

// int main() {
// 	int tab[5] = { 0, 1, 2, 3, 4 };
// 	Awesome tab2[5];
// 	iter(tab, 5, print<const int>);
// 	NL;

// 	iter(tab2, 3, print<Awesome> );
// 	return 0;
// }
