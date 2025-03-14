/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:33:22 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 14:45:02 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Parser.hpp"

int	main(int argc, char** argv) {
	std::string input = (argc > 1) ? argv[1] : "";

	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open() || dataFile.fail()) {
		std::cerr << "Error: opening data.csv file" << std::endl;
		return (-1);
	}

	std::map<std::string, float> dateValueMap;

	try {
		Parser::fileParse(dataFile, dateValueMap);
	} catch (std::exception& e) {
		std::cerr << "Error: data.csv " << e.what() << std::endl;
		dataFile.close();
		return (-1);
	}
	dataFile.close();

	std::ifstream inputFile(input.c_str());
	if (!inputFile.is_open() || inputFile.fail() || argc < 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return (-1);
	}
	BitcoinExchange exchange(dateValueMap);

	std::string line;
	std::getline(inputFile, line);
	while(std::getline(inputFile, line)) {
		std::string trimmedInput;
		try {
			trimmedInput = Parser::inputFormat(line);
			exchange.makeExchange(trimmedInput);
		} catch(std::exception& e) {
			std::cerr << e.what() << " => " << line << std::endl;
		}
	}
	inputFile.close();
	return (0);
}
