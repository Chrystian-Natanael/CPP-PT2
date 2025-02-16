#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

	static const int	_minGrade = 150;
	static const int	_maxGrade = 1;

public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() { return ("Grade is too high");}
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() { return ("Grade is too low");}
	};

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &rhs);
	
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;

	void		incrementGrade(void);
	void		decrementGrade(void);

	void		signForm(AForm &form);
	void		executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif // ! BUREAUCRAT_HPP