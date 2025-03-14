/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:45:33 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 14:42:59 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <string>

class Parser {
 public:
	static void fileParse(std::ifstream& file, std::map<std::string, float>& map);
	static std::string inputFormat(const std::string& input);
	static std::string dateParse(const std::string& rawKey);
	static float floatParse(const std::string& rawValue);

 private:
	Parser();
	Parser(const Parser& other);
	Parser& operator=(const Parser& other);
	~Parser();

	static std::string trim(const std::string& str);
	static int intParse(const std::string& rawValue);
	static void validDate(int year, int month, int day);
	static bool leapYear(int year);
};

#endif // ! PARSER_HPP