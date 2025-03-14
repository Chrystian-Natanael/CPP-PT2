/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:53:39 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 13:01:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

#define NL std::cout << std::endl

int main(void) {

	std::cout << "===STARTING TESTS===" << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << "===GENERATING BASE=== " << i + 1 << std::endl;
		NL;
		Base *ptr = generate();
		std::cout << "===POINTER TEST===" << std::endl;
		identify(ptr);
		std::cout << "===REFERENCE TEST===" << std::endl;
		identify(*ptr);
		NL;

		delete ptr;
	}

	return 0;
}