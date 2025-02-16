#include <gtest/gtest.h>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestFormTest : public ::testing::Test {
protected:
	RobotomyRequestForm* form;
	Bureaucrat* bureaucrat;

	void SetUp() override {
		form = new RobotomyRequestForm("TestTarget");
		bureaucrat = new Bureaucrat("TestBureaucrat", 137);
	}

	void TearDown() override {
		delete form;
		delete bureaucrat;
	}
};

// Test constructor
TEST_F(RobotomyRequestFormTest, Constructor) {
	EXPECT_EQ(form->getName(), "Robotomy Request form");
	EXPECT_FALSE(form->getIsSigned());
}

// Test function with success
TEST_F(RobotomyRequestFormTest, ExecuteSuccess) {
	form->beSigned(*bureaucrat);
	EXPECT_NO_THROW(form->execute(*bureaucrat));
}

// Test function with form not assigned
TEST_F(RobotomyRequestFormTest, ExecuteFormNotSigned) {
	EXPECT_THROW(form->execute(*bureaucrat), AForm::FormNotSignedException);
}

// Test to low grade to exec
TEST_F(RobotomyRequestFormTest, ExecuteGradeTooLow) {
	form->beSigned(*bureaucrat);
	Bureaucrat lowGradeBureaucrat("LowGradeBureaucrat", 138);
	EXPECT_THROW(form->execute(lowGradeBureaucrat), AForm::GradeTooLowException);
}
