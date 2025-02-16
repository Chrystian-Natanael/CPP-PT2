#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon Form created", P_SIGN_GRADE, P_EXEC_GRADE), _target("unknow") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form created", P_SIGN_GRADE, P_EXEC_GRADE), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) :
	AForm("Presidential Pardon Form created", P_SIGN_GRADE, P_EXEC_GRADE) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if ( this != &rhs )
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	if (bureaucrat.getGrade() > P_EXEC_GRADE)
		throw (AForm::GradeTooLowException());
	std::cout << Y  << this->_target << " has been pardoned by Zaphod Beeblebrox." << RST << std::endl;
}
