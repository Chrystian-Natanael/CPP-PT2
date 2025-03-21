/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:50:26 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/19 17:28:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Colors.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

std::string trim(const std::string &str) {
	std::string::const_iterator start = str.begin();
	while (start != str.end() && std::isspace(*start)) {
		start++;
	}

	std::string::const_reverse_iterator end = str.rbegin();
	while (end.base() != start && std::isspace(*end)) {
		end++;
	}

	return (std::string(start, end.base()));
}

std::string trimInternSpaces(const std::string &str) {
	std::string newStr = "";

	std::string::const_iterator start = str.begin();
	while (start != str.end() && std::isspace(*start)) {
		start++;
	}

	std::string::const_reverse_iterator end = str.rbegin();
	while (end.base() != start && std::isspace(*end)) {
		end++;
	}

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!::isspace(*it)) {
			newStr += *it;
		}
	}

	return (newStr);
}

bool isOp(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

bool doubleDigit(const std::string &str) {
	std::string noSpace = trim(str);
	for (std::string::const_iterator it = noSpace.begin(); it != noSpace.end();
			 ++it) {
		while (::isspace(*it)) {
			++it;
		}
		if (isdigit(*it) && isdigit(*(it + 1))) {
			return (true);
		} else if (isOp(*it) && isOp(*(it + 1)))
			return (true);
	}
	return (false);
}

int performOperation(char op, int a, int b) {

	switch (op) {
	case '+':
		return (a + b);
	case '-':
		return (a - b);
	case '*':
		return (a * b);
	case '/':
		if (b == 0) {
			throw std::runtime_error("Division by zero");
		}
		return (a / b);
	default:
		throw std::invalid_argument("Invalid operator");
	}
}

bool nbOp(const std::string &str) {
	int nb = 0, op = 0;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (isOp(*it)) {
			++op;
		} else if (isdigit(*it)) {
			++nb;
		}
	}
	if ((op - 1) == nb) {
		return true;
	} else {
		return false;
	}
}