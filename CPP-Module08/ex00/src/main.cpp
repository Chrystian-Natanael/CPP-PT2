/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:13:28 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 15:15:28 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

#define NL std::cout << std::endl;

int main() {
  NL;
  std::cout << G << "Starting tests with vector" << RST << std::endl;
  try {
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
      std::cout << Y << "Adding to vector value: " << i << RST << std::endl;
      vec.push_back(i);
    }
    NL;

    std::cout << G << "Trying to find number 3 in vector" << RST << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << B << "Found in vector: " << RST << *it << std::endl;
    NL;

    std::cout << G << "Trying to find number 42 in vector" << RST << std::endl;
    it = easyfind(vec, 42); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  NL;
  std::cout << G << "Starting tests with list" << RST << std::endl;
  try {
    std::list<int> lst;
    for (int i = 1; i < 10; ++i) {
      std::cout << Y << "Adding to list value: " << (i * 10) << RST << std::endl;
      lst.push_back(i * 10);
    }
    NL;
    std::cout << G << "Trying to find number 30 in list" << RST << std::endl;
    std::list<int>::iterator it = easyfind(lst, 30);
    std::cout << B << "Found in list: " << RST << *it << std::endl;
    NL;

    std::cout << G << "Trying to find number 100 in list" << RST << std::endl;
    it = easyfind(lst, 100); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
