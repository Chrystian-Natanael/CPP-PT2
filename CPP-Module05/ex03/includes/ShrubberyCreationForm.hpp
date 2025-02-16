#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define ASCII_TRESS                                                              \
	"             _{\\ _{\\{\\/}/}/}__\n             {/{/\\}{/{/\\}(\\}{/{/\\} "   \
	"_\n            {/{/\\}{/{/\\}(_)/}{/{/\\}  _\n         "                      \
	"{\\{/(/\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n        "                            \
	"{/{/(_)/}{\\{/\\)\\}{\\(_){/}/}/}/}\n       "                                 \
	"_{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n      "                                   \
	"/{/{\\{\\{\\{\\{/(_)/}/}{/{/{/\\}\\})\\}{/\\}\n      "                        \
	"_{\\{/{\\{/(_)(\\}/}{/{/{/\\}\\})\\}{/\\}\n     "                             \
	"/{/{\\{\\{\\(/}{\\{/}/}{\\}(_){\\/}\\}\n     "                                \
	"_{\\{/{\\{/(_)(\\}/}{/{/{/\\}\\})\\}{/\\}\n    "                              \
	"{/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}\n     "                               \
	"{\\{\\/}(_){\\{\\/}/}(_){\\/}{\\/}/)/}\n      "                               \
	"{/{\\{\\/}{/{\\{\\/}/}{\\{\\/}/}\\}(_)\n     "                                \
	"{/{\\{\\/}{/){\\{\\/}/}{\\{\\(/}/}\\}/}\n      "                              \
	"{/{\\{\\/}(_){\\{\\(/}/}{\\(_)/}/}\\}\n        "                              \
	"{/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n          "                            \
	"(_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n            "                             \
	"{/{/{\\{\\/}{/{\\{\\(_)/}\n             {/{\\{\\{\\/}/}{\\{\\\\}/}\n      "   \
	"        {){/ {\\/}{\\/} \\}\\}\n              (_)  \\.-'.-/\n          "      \
	"__...--- |'-.-'| --...__\n   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n "   \
	"-\"    ' .  . '    |.'-._| '  . .  '   \"__\n .  '-  '    .--'  | '-.'|    "   \
	".  '  . '\n          ' ..     |'-_.-|\n  .  '  .       _.-|-._ -|-._  .  "    \
	"'  .\n              .'   |'- .-|   '.\n  ..-'   ' .  '.   `-._.-�   .'  ' " \
	" - .\n   .-' '        '-._______.-'     '  .\n        .      ~,\n    .    "   \
	"   .   |\\   .    ' '-.\n    ___________/  \\____________\n   /  Why is "     \
	"it, when you want \\\n  |  something, it is so damn   |\n  |    much work "   \
	"to get it?     |\n   \\___________________________/"


# define S_SIGN_GRADE 145
# define S_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
	ShrubberyCreationForm(void);

public:
	class FileAlreadyExistException : public std::exception {
		public:
			virtual const char *what() const throw() { return ("File already exists."); }
	};

	class FailedToOpenException : public std::exception {
		public:
			virtual const char *what() const throw() { return ("Failed opening file"); }
	};

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	bool	getSignature(void) const;
	void	execute(Bureaucrat const &executor) const;
};

#endif // ! SHRUBBERYCREATIONFORM_HPP