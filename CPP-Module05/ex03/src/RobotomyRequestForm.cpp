#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request form", R_SIGN_GRADE, R_EXEC_GRADE), _target("unknow") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request form", R_SIGN_GRADE, R_EXEC_GRADE), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm("Robotomy Request form", R_SIGN_GRADE, R_EXEC_GRADE) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	if (bureaucrat.getGrade() > R_EXEC_GRADE)
		throw (AForm::GradeTooLowException());
	if ((rand() + clock()) % 2 == 0) {
		std::cout << Y << "Hey hey, look! " << this->_target << " was sucessfully robotomized" << RST << std::endl;
	} else {
		std::cout << RED << "Oh no... " << this->_target << " robotomization failed" << RST << std::endl;
	}
}
