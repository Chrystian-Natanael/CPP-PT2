/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:04:20 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 14:29:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	// Test default constructor
	std::cout << G << "Testing default constructor:" << RST << std::endl;
	Array<int> arr1;
	std::cout << Y << "arr1 size: " << RST << arr1.size() << std::endl; // Expected: 0

	// Test constructor with size
	std::cout << G << "\nTesting constructor with size:" << RST << std::endl;
	unsigned int n = 5;
	Array<int> arr2(n);
	std::cout << Y << "arr2 size: " << RST << arr2.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr2.size(); ++i) {
		std::cout << B << "arr2[" << i << "] = " << RST << arr2[i]
							<< std::endl; // Expected: 0 (default initialization)
	}

	// Test copy constructor
	std::cout << G << "\nTesting copy constructor:" << RST << std::endl;
	Array<int> arr3(arr2);
	std::cout << Y << "arr3 size: " << RST << arr3.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr3.size(); ++i) {
		std::cout << B << "arr3[" << i << "] = " << RST << arr3[i]
							<< std::endl; // Expected: 0
	}

	// Test assignment operator
	std::cout << G << "\nTesting assignment operator:" << RST << std::endl;
	Array<int> arr4;
	arr4 = arr2;
	std::cout << Y << "arr4 size: " << RST << arr4.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr4.size(); ++i) {
		std::cout << B << "arr4[" << i << "] = " << RST << arr4[i]
							<< std::endl; // Expected: 0
	}

	// Test modifying one array does not affect the copied array
	std::cout
			<< G << "\nTesting modifying one array does not affect the copied array:" << RST
			<< std::endl;
	arr2[0] = 42;
	std::cout << B << "arr2[0] = " << RST << arr2[0] << std::endl; // Expected: 42
	std::cout << B << "arr3[0] = " << RST << arr3[0] << std::endl; // Expected: 0

	// Test out-of-bounds access
	std::cout << G << "\nTesting out-of-bounds access:" << RST << std::endl;
	try {
		std::cout << Y << arr2[10] << std::endl; // Should throw an exception
	} catch (const std::out_of_range &e) {
		std::cerr << RED << "Exception caught: " << RST << e.what()
							<< std::endl; // Expected: out_of_range exception
	}

	// Test const array
	std::cout << G << "\nTesting const array:" << RST << std::endl;
	const Array<int> arr5(3);
	std::cout << Y << "arr5 size: " << RST << arr5.size() << std::endl; // Expected: 3
	for (std::size_t i = 0; i < arr5.size(); ++i) {
		std::cout << B << "arr5[" << i << "] = " << RST << arr5[i]
							<< std::endl; // Expected: 0
	}

	// Test print all elements
	std::cout << G << "\nTesting print all elem of array:" << RST << std::endl;
	Array<int> arr6(4);
	std::cout << Y << "arr6 size: " << RST << arr6.size() << std::endl; // Expected: 4
	for (std::size_t i = 0; i < arr6.size(); ++i) {
		arr6[i] = i;
	}
	std::cout << B << "arr6 = " << RST << arr6
							<< std::endl; // Expected: 0 - 3;

	// Test print all elements
	std::cout << G << "\nTesting print all elem of char array:" << RST << std::endl;
	Array<char> arr7(4);
	std::cout << Y << "arr7 size: " << RST << arr7.size() << std::endl; // Expected: 4
	for (std::size_t i = 0; i < arr7.size(); ++i) {
	    arr7[i] = 'A' + i;
	}
	std::cout << B << "arr7 = " << RST << arr7 << std::endl; // Expected: A - D;

	return 0;
}