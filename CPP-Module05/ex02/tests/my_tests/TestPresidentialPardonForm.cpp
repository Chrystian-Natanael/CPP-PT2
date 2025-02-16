#include <gtest/gtest.h>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonFormTest : public ::testing::Test {
protected:
	PresidentialPardonForm* form;
	Bureaucrat* bureaucrat;

	void SetUp() override {
		form = new PresidentialPardonForm("TestTarget");
		bureaucrat = new Bureaucrat("TestBureaucrat", 5);
	}

	void TearDown() override {
		delete form;
		delete bureaucrat;
	}
};

// Test Constructor
TEST_F(PresidentialPardonFormTest, Constructor) {
	EXPECT_EQ(form->getName(), "Presidential Pardon Form created");
	EXPECT_EQ(form->getIsSigned(), false);
}

// Test function with success
TEST_F(PresidentialPardonFormTest, ExecuteSuccess) {
	form->beSigned(*bureaucrat);
	EXPECT_NO_THROW(form->execute(*bureaucrat));
}

// Test function with form not assigned
TEST_F(PresidentialPardonFormTest, ExecuteFormNotSigned) {
	EXPECT_THROW(form->execute(*bureaucrat), AForm::FormNotSignedException);
}

// Test to low grade to execution
TEST_F(PresidentialPardonFormTest, ExecuteGradeTooLow) {
	form->beSigned(*bureaucrat);
	Bureaucrat lowGradeBureaucrat("LowGradeBureaucrat", 6);
	EXPECT_THROW(form->execute(lowGradeBureaucrat), AForm::GradeTooLowException);
}