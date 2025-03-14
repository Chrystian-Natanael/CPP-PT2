/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:00:41 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 16:01:39 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "RPN.hpp"
#include <exception>
#include <iostream>

static void usage(void) {
  std::cout << std::endl;
  std::cerr << B << "Usage: ./bin/RPN \"<expression>\"" << RST << std::endl;
}

void start_program(char *av) {
  try {
    RPN rpn(av);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: " << RST << e.what();
  }
}

int main(int ac, char **av) {
  if (ac == 2)
    start_program(av[1]);
  else
    usage();

  return 0;
}