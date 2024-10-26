#include <iostream>
#include "Form.hpp"
#include "Colors.hpp"
#include "Bureaucrat.hpp"

void testFormAndBureaucrat() {

	std::cout << Y << "----- Form and Bureaucrat Tests -----" << RST << std::endl;
	try {
		// Creating a form
		Form form("Application Form", 50, 25);

		// Creating a bureaucrat
		Bureaucrat bureaucrat("John", 55);

		std::cout << G << "Form details:" << RST << std::endl;
		std::cout << form << std::endl;

		// Attempting to sign the form
		std::cout << G << "Attempting to sign the form..." << RST << std::endl;
		bureaucrat.signForm(form);

		// Showing form details after signing
		std::cout << G << "Form details after signing:" << RST << std::endl;
		std::cout << form << std::endl;

	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RST << std::endl;
	}

	try {
		// Creating a form
		Form form2("Approval Form", 5, 10);

		// Creating a bureaucrat
		Bureaucrat bureaucrat2("Alice", 2);

		std::cout << G << "\nForm details:" << RST << std::endl;
		std::cout << form2 << std::endl;

		// Attempting to sign the form
		std::cout << G << "Attempting to sign the form..." << RST << std::endl;
		bureaucrat2.signForm(form2);

		// Showing form details after signing
		std::cout << G << "Form details after signing:" << RST << std::endl;
		std::cout << form2 << std::endl;

	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RST << std::endl;
	}

	
}

void testValidationAndGradeTooHighException() {
	try {
		// Creating a form with invalid grade
		std::cout << Y << "----- Testing validation and GradeTooHighException -----" << RST << std::endl;
		std::cout << G << "Attempting to create a form with invalid grade..." << RST << std::endl;
		Form invalidForm("Invalid Form", 150, 25); // Grade too high

	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RST << std::endl;
	}
}

int main() {
	testFormAndBureaucrat();
	testValidationAndGradeTooHighException();
	return (0);
}