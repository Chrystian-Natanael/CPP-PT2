#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	int			_gradeToSign;
	int			_gradeToExecute;
	bool				_isSigned;

public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	Form(void);
	Form(Form const &rhs);
	Form(std::string name, int gradeToSign, int gradeToExecute);

	~Form(void);

	Form &operator=(Form const &rhs);

	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getIsSigned(void) const;

	void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif // ! FORM_HPP