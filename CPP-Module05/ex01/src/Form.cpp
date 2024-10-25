#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Form: GradeTooHighException");
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Form: GradeTooLowException");
}

Form::Form(void)
	: _name("Generic Form"), _gradeToSign(150)
	, _gradeToExecute(150), _isSigned(false) {}

Form::Form(Form const &rhs)
	: _name(rhs._name), _gradeToSign(rhs._gradeToSign)
	, _gradeToExecute(rhs._gradeToExecute), _isSigned(rhs._isSigned) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute), _isSigned(false) {}

Form::~Form(void) {}

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs._name;
		this->_gradeToExecute = rhs._gradeToExecute;
		this->_gradeToSign = rhs._gradeToSign;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string Form::getName(void) const {return (this->_name);}

int Form::getGradeToExecute(void) const {return (this->_gradeToExecute);}

int Form::getGradeToSign(void) const {return (this->_gradeToSign);}

bool Form::getIsSigned(void) const {return (this->_isSigned);}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
	os << form.getName() << ", Grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradeToExecute() << ", signature status " << form.getIsSigned();
	return (os);
}
