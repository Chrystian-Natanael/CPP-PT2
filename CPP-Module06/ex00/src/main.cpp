/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:44:17 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 12:09:12 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

void testChar() {
  std::cout << std::endl;
  std::cout << Y << "Testing char: 'A'" << RST << std::endl;
  ScalarConverter::convert("A");

  std::cout << std::endl;
  std::cout << Y << "Testing char: '0'" << RST << std::endl;
  ScalarConverter::convert("0");

  std::cout << std::endl;
  std::cout << Y << "Testing char: '?'" << RST << std::endl;
  ScalarConverter::convert("?");

  std::cout << std::endl;
  std::cout << Y << "Testing char: ' '" << RST << std::endl;
  ScalarConverter::convert(" ");

  std::cout << std::endl;
  std::cout << Y << "Testing char: '\\n'" << RST << std::endl;
  ScalarConverter::convert("\n");

  std::cout << std::endl;
  std::cout << Y << "Testing char: '.'" << RST << std::endl;
  ScalarConverter::convert(".");

  std::cout << std::endl;
  std::cout << Y << "Testing char: 'nan'" << RST << std::endl;
  ScalarConverter::convert("nan");
}

void testInt() {
  std::cout << std::endl;
  std::cout << Y << "Testing int: '42'" << RST << std::endl;
  ScalarConverter::convert("42");

  std::cout << std::endl;
  std::cout << Y << "Testing int: '-1234'" << RST << std::endl;
  ScalarConverter::convert("-1234");

  std::cout << std::endl;
  std::cout << Y << "Testing int: '2147483647'" << RST << std::endl;
  ScalarConverter::convert("2147483647");

  std::cout << std::endl;
  std::cout << Y << "Testing int: '-2147483648'" << RST << std::endl;
  ScalarConverter::convert("-2147483648");

  std::cout << Y << "Testing int: 'nan'" << RST << std::endl;
  ScalarConverter::convert("nan");
}

void testFloat() {
  std::cout << std::endl;
  std::cout << Y << "Testing float: '42.00001f'" << RST << std::endl;
  ScalarConverter::convert("42.00001f");

  std::cout << std::endl;
  std::cout << Y << "Testing float: '-1234.5678f'" << RST << std::endl;
  ScalarConverter::convert("-1234.5678f");

  std::cout << std::endl;
  std::cout << Y << "Testing float: '3.14159f'" << RST << std::endl;
  ScalarConverter::convert("3.14159f");

  std::cout << std::endl;
  std::cout << Y << "Testing float: '-1.2345678e5f'" << RST << std::endl;
  ScalarConverter::convert("-1.2345678e5f");

  std::cout << std::endl;
  std::cout << Y << "Testing float: 'inf'" << RST << std::endl;
  ScalarConverter::convert("inf");

  std::cout << std::endl;
  std::cout << Y << "Testing float: '-inf'" << RST << std::endl;
  ScalarConverter::convert("-inf");
  
  std::cout << Y << "Testing float: 'nan'" << RST << std::endl;
  ScalarConverter::convert("nan");
}

void testDouble() {
  std::cout << std::endl;
  std::cout << Y << "Testing double: '42.00001'" << RST << std::endl;
  ScalarConverter::convert("42.00001");

  std::cout << std::endl;
  std::cout << Y << "Testing double: '-1234.5678'" << RST << std::endl;
  ScalarConverter::convert("-1234.5678");

  std::cout << std::endl;
  std::cout << Y << "Testing double: '3.14159'" << RST << std::endl;
  ScalarConverter::convert("3.14159");

  std::cout << std::endl;
  std::cout << Y << "Testing double: '-1.2345678e5'" << RST << std::endl;
  ScalarConverter::convert("-1.2345678e5");

  std::cout << std::endl;
  std::cout << Y << "Testing double: 'inf'" << RST << std::endl;
  ScalarConverter::convert("inf");

  std::cout << std::endl;
  std::cout << Y << "Testing double: '-inf'" << RST << std::endl;
  ScalarConverter::convert("-inf");

  std::cout << Y << "Testing double: 'nan'" << RST << std::endl;
  ScalarConverter::convert("nan");
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cout << RED << "Usage: " << Y << "./convert <arg>" << RST << std::endl;
    return EXIT_FAILURE;
  }

  ScalarConverter::convert(argv[1]);

  std::string answer;
  std::cout << "Do you wanna run my own tests? [Y/n]" << std::endl;
  std::getline(std::cin, answer);
  if (!answer.compare("y") || !answer.compare("Y")) {
    testChar();
    testInt();
    testFloat();
    testDouble();
  } else {
    std::cout << "Thank you!" << std::endl;
  }

  return 0;
}