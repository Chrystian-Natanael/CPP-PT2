#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;

protected:
	virtual void validGradeToExec(Bureaucrat const &executor);

public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	AForm(void);
	AForm(AForm const &rhs);
	AForm(std::string name, int gradeToSign, int gradeToExecute);

	virtual ~AForm(void);

	AForm &operator=(AForm const &rhs);

	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getIsSigned(void) const;

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif // ! AFORM_HPP