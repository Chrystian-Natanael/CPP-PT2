#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation Form", S_SIGN_GRADE, S_EXEC_GRADE), _target("Ghost") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", S_SIGN_GRADE, S_EXEC_GRADE), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) :
	AForm("Shrubbery Creation Form", S_SIGN_GRADE, S_EXEC_GRADE) {
	*this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

bool ShrubberyCreationForm::getSignature(void) const {
	return (this->getIsSigned());
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSignature())
		throw (AForm::FormNotSignedException());

	if (executor.getGrade() > S_EXEC_GRADE)
		throw (AForm::GradeTooLowException());

	const std::string file_name = this->_target + "_shrubberry";

	if (std::ifstream(file_name.c_str()))
		throw (ShrubberyCreationForm::FileAlreadyExistException());

	std::ofstream out(file_name.c_str());
	if (!out)
		throw (ShrubberyCreationForm::FailedToOpenException());

	out << ASCII_TRESS << std::endl;
}
