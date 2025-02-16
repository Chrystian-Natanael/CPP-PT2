#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define R_SIGN_GRADE 145
# define R_EXEC_GRADE 137

class RobotomyRequestForm : public AForm{
private:
	std::string	_target;
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src );
	~RobotomyRequestForm(void);

	RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

	void	execute(Bureaucrat const &executor) const;
};

#endif // ! ROBOTOMYREQUESTFORM_H