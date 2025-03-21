/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:34:04 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/14 15:59:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Utils.hpp"
#include "Colors.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

RPN::RPN() : _input(""), _stack() {}

RPN::RPN(const std::string input) : _input(input) {
	try {
		if (validateInput(this->_input)) {
			std::cout << B << calculate() << RST << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RST << std::endl;
	}
}

RPN::~RPN() {}

RPN::RPN(const RPN &rhs) {
	this->_input = rhs._input;
	this->_stack = rhs._stack;
}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->_input = rhs._input;
		this->_stack = rhs._stack;
	}
	return (*this);
}

const char *RPN::InvalidExpressionException::what() const throw() {
	return "Error";
}

bool RPN::validateInput(const std::string &str) {
	if (str.empty()) {
		throw std::invalid_argument("How you wanna calculate 'nothing'?");
	} else if (doubleDigit(str)) {
		throw std::invalid_argument(
				"Only numbers between 0 and 9. And no double operators.");
	} else if (nbOp(str)) {
		throw std::invalid_argument("Invalid number of operations.");
	}

	std::string validate = trimInternSpaces(str);
	std::string::const_iterator it = validate.begin();

	for (std::string::const_iterator it = validate.begin(); it != validate.end();
			 ++it) {
		if (::isdigit(*it) || isOp(*it)) {
			continue;
		} else {
			throw std::invalid_argument("Only number and operator allowed.");
			return (false);
		}
	}

	if (isOp(*it)) {
		throw std::invalid_argument("Operation cannot be ther first element.");
	} else if (std::isdigit(*it) && isOp(*(it + 1))) {
		throw std::invalid_argument("You need to use 'number number + Operation'");
	}

	this->_input = validate;
	return (true);
}

int RPN::calculate(void) {
	std::size_t index = 0;
	std::string::iterator it = _input.begin();

	if (_input.size() < 3)
		return 0;
	while (index < _input.size()) {
		if (::isdigit(*it)) {
			_stack.push(*it - 48);
		} else if (isOp(*it) && _input.size() > 1) {
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = performOperation(*it, a, b);
			_stack.push(result);
		}
		++index;
		++it;
	}
	return (_stack.top());
}
