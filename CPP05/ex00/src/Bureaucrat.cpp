#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("NULL"), _grade(0) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > _minGrade) {
		throw (GradeTooLowException());
	}
	else if (grade < _maxGrade) {
		throw (GradeTooHighException());
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) {*this = rhs;}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
		const_cast<std::string &>(this->_name) = rhs._name;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const {return (this->_name);}

int Bureaucrat::getGrade(void) const {return (this->_grade);}

void Bureaucrat::incrementGrade(void) {
	if (this->_grade > _maxGrade)
		this->_grade--;
	else
		throw (GradeTooHighException());
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade < _minGrade)
		this->_grade++;
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
