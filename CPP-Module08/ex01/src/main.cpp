/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:33:25 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 15:51:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <climits>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <exception>
#include <iostream>
#include <vector>

#define NL std::cout << std::endl;

// Helper function to generate random numbers
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  try {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    NL;
    // Create a Span object with a maximum size of 10
    std::cout << G << "Creating a vector with 10 positions" << RST << std::endl;
    Span span(10);

    // Add some numbers
    int nbs[] = {3, 7, 2, 9, 1, 4, 8, 6, 5, 10};
    for (int i = 0; i < 10; ++i) {
      std::cout << Y << "Adding number " << nbs[i] << " to Span" << RST
                << std::endl;
      span.addNumber(nbs[i]);
    }

    NL;
    // Test shortest span
    std::cout << G << "Shortest span: " << RST << span.shortestSpan() << std::endl;

    // Test longest span
    std::cout << G << "Longest span: " << RST << span.longestSpan() << std::endl;

    NL;
    // Test adding a number to a full Span
    std::cout << RED << "Attempting to add a number to a full Span..." << RST
              << std::endl;
    std::cout << B << "Trying to add number 11 to span." << RST << std::endl;
    span.addNumber(11); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << RED << "Exception: " << RST << e.what() << std::endl;
  }

  // Additional testing with larger dataset
  try {
    std::cout << G << "\nAdditional Testing with Larger Dataset:\n" << RST;

    // Create a Span object with a maximum size of 10000
    std::cout << Y << "Creating a large span with 10000 positions" << RST
              << std::endl;
    Span largeSpan(10000);

    // Fill the large span with random numbers
    std::cout << B << "Adding a randon numbers to the vector" << RST << std::endl;
    for (int i = 0; i < 10000; ++i) {
      largeSpan.addNumber(generateRandomNumber(1, 100000000));
    }
    NL;

    // Test shortest span
    std::cout << G << "Shortest span: " << RST << largeSpan.shortestSpan()
              << std::endl;

    // Test longest span
    std::cout << G << "Longest span: " << RST << largeSpan.longestSpan()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  NL;

  {
    try {
      std::cout << G << "Testing my function to add a range numbers" << RST
                << std::endl;

      std::cout << Y << "Creating a vector of integers" << RST << std::endl;
      std::vector<int> numbs;
      for (int i = 0; i < 10; ++i) {
        numbs.push_back(generateRandomNumber(100, 1000));
      }
      Span lastSpan(20);
      std::cout << "numbs size " << numbs.size() << std::endl;
      lastSpan.addRange(numbs.begin(), numbs.end());
      NL;
      std::cout << G << "Shortest span: " << RST << lastSpan.shortestSpan()
                << std::endl;

      // Test longest span
      std::cout << G << "Longest span: " << RST << lastSpan.longestSpan()
                << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  return 0;
}