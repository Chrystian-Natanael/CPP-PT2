/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:20:00 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/19 16:41:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>

static void usage(void) {
	std::cout << "\n";
	std::cerr << B << "Usage: ./bin/PmergeMe \"<unsorted number sequence>\"" << RST
			<< std::endl;
}

void start_program(int ac, char **av) {
	try {
		Ford srt(validateAndProcessInput<std::vector<int> >(av, ac),
				validateAndProcessInput<std::list<int> >(av, ac));

		std::cout << G << "before: " << RST;
		printSequence(srt.getVector());
		std::vector<int> vec(srt.getVector());
		std::list<int> lis(srt.getList());

		displayTime(lis, "list");
		printAfter = false;
		displayTime(vec, "vector");

	} catch (const std::exception &e) {
		std::cerr << RED << "Error: " << RST << e.what() << std::endl;
	}
}

int main(int ac, char **av) {
	if (ac > 2)
		start_program(ac, av);
	else
		usage();
	return (0);
}