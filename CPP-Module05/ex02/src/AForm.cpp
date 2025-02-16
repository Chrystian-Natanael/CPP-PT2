#include "AForm.hpp"

const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Form: GradeTooHighException");
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Form: GradeTooLowException");
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return ("Form:FormNotsignedException");
}

AForm::AForm(void) :
	_name("Generic Form"), _gradeToSign(150)
	, _gradeToExecute(150), _isSigned(false) {}

AForm::AForm(AForm const &rhs) :
	_name(rhs._name), _gradeToSign(rhs._gradeToSign)
	, _gradeToExecute(rhs._gradeToExecute), _isSigned(rhs._isSigned) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute), _isSigned(false) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs._name;
		const_cast<int &>(this->_gradeToExecute) = rhs._gradeToExecute;
		const_cast<int &>(this->_gradeToSign) = rhs._gradeToSign;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string AForm::getName(void) const {return (this->_name);}

int AForm::getGradeToExecute(void) const {return (this->_gradeToExecute);}

int AForm::getGradeToSign(void) const {return (this->_gradeToSign);}

bool AForm::getIsSigned(void) const {return (this->_isSigned);}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

void AForm::validGradeToExec(Bureaucrat const &executor) {
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::FormNotSignedException());
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
	os << form.getName() << ", Grade to sign is " << form.getGradeToSign()
		<< ", grade to execute is " << form.getGradeToExecute()
		<< ", signature status " << form.getIsSigned();
	return (os);
}
