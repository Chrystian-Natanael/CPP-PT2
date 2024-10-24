#include "Colors.hpp"
#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << std::endl;
	std::cout << BBLU << "Test increment a high grade and cout." << RST << std::endl;
	{
		try {
			Bureaucrat john("High Grade Bure", 1);
			std::cout << john << std::endl;

			john.incrementGrade();
			std::cout << john << std::endl;

			john.decrementGrade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << RED << "Exception: " << e.what() << RST << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << BBLU << "Test decrement a low grade and cout." << RST << std::endl;
	{
		try {
			Bureaucrat john("Low Grade Bure", 150);
			std::cout << john << std::endl;

			john.decrementGrade();
			std::cout << john << std::endl;

			john.incrementGrade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << RED << "Exception: " << e.what() << RST << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << BBLU << "Now different grade" << RST << std::endl;
	{
		try {
			Bureaucrat john("Mid Grade", 75);
			std::cout << john << std::endl;

			john.incrementGrade();
			std::cout << john << std::endl;

			john.decrementGrade();
			std::cout << john << std::endl;

			while (john.getGrade() > 42)
				john.incrementGrade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << RED << "Exception: " << e.what() << RST << std::endl;
		}
	}

	return 0;
}