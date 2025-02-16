#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	AForm *tmp;

	std::cout << G << ("\nROBOTOMY REQUEST") << RST << std::endl;
	try {
		tmp = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << G << ("Form created successfully!") << RST << std::endl;
		delete tmp;
	} catch (Intern::InvalidFormException &e) {
		std::cout << Y << ("Form not found!") << RST << std::endl;
	}

	std::cout << G << ("\nSHRUBBERY CREATION") << RST << std::endl;
	try {
		tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
		std::cout << G << ("Form created successfully!") << RST << std::endl;
		delete tmp;
	} catch (Intern::InvalidFormException &e) {
		std::cout << Y << ("Form not found!") << RST << std::endl;
	}

	std::cout << G << ("\nPRESIDENTIAL PARDON") << RST << std::endl;
	try {
		tmp =
		someRandomIntern.makeForm("presidential pardon", "corrupt politician");
		std::cout << G << ("Form created successfully!") << RST << std::endl;
		delete tmp;
	} catch (Intern::InvalidFormException &e) {
		std::cout << Y << ("Form not found!") << RST << std::endl;
	}

	std::cout << G << ("\nTAX EXEMPTION") << RST << std::endl;
	try {
		tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
		std::cout << G << ("Form created successfully!") << RST << std::endl;
		delete tmp;
	} catch (Intern::InvalidFormException &e) {
		std::cout << Y << ("Form not found!") << RST << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
