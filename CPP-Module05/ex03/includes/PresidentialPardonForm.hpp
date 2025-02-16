#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define P_SIGN_GRADE 25
# define P_EXEC_GRADE 5

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	void	execute(Bureaucrat const &executor) const;
};

#endif // ! PRESIDENTIALPARDONFORM_H