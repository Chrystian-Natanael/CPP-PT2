#include <gtest/gtest.h>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationFormTest : public ::testing::Test {
protected:
	ShrubberyCreationForm* form;
	Bureaucrat* bureaucrat;

	void SetUp() override {
		form = new ShrubberyCreationForm("TestTarget");
		bureaucrat = new Bureaucrat("TestBureaucrat", 137);
	}

	void TearDown() override {
		delete form;
		delete bureaucrat;
		std::remove("TestTarget_shrubberry");
	}
};

// Test constructor
TEST_F(ShrubberyCreationFormTest, Constructor) {
	EXPECT_EQ(form->getName(), "Shrubbery Creation Form");
	EXPECT_EQ(form->getSignature(), false);
}

// Test function with success
TEST_F(ShrubberyCreationFormTest, ExecuteSuccess) {
	form->beSigned(*bureaucrat);
	EXPECT_NO_THROW(form->execute(*bureaucrat));
}

// Test function with not assigned form
TEST_F(ShrubberyCreationFormTest, ExecuteFormNotSigned) {
	EXPECT_THROW(form->execute(*bureaucrat), AForm::FormNotSignedException);
}

// Test low grade to exec
TEST_F(ShrubberyCreationFormTest, ExecuteGradeTooLow) {
	form->beSigned(*bureaucrat);
	Bureaucrat lowGradeBureaucrat("LowGradeBureaucrat", 138);
	EXPECT_THROW(form->execute(lowGradeBureaucrat), AForm::GradeTooLowException);
}

// Test exception with file already exist
TEST_F(ShrubberyCreationFormTest, ExecuteFileAlreadyExists) {
	form->beSigned(*bureaucrat);
	std::ofstream out("TestTarget_shrubberry");
	out.close();
	EXPECT_THROW(form->execute(*bureaucrat), ShrubberyCreationForm::FileAlreadyExistException);
	std::remove("TestTarget_shrubberry");
}
