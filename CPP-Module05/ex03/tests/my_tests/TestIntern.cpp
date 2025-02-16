#include <gtest/gtest.h>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class InternTest : public ::testing::Test {
protected:
	Intern* intern;

	void SetUp() override {
		intern = new Intern();
	}

	void TearDown() override {
		delete intern;
	}
};

TEST_F(InternTest, CreateRobotomyRequestForm) {
	AForm* form = intern->makeForm("robotomy request", "TestTarget");
	EXPECT_NE(dynamic_cast<RobotomyRequestForm*>(form), nullptr);
	delete form;
}

TEST_F(InternTest, CreateShrubberyCreationForm) {
	AForm* form = intern->makeForm("shrubbery creation", "TestTarget");
	EXPECT_NE(dynamic_cast<ShrubberyCreationForm*>(form), nullptr);
	delete form;
}

TEST_F(InternTest, CreatePresidentialPardonForm) {
	AForm* form = intern->makeForm("presidential pardon", "TestTarget");
	EXPECT_NE(dynamic_cast<PresidentialPardonForm*>(form), nullptr);
	delete form;
}

TEST_F(InternTest, CreateInvalidForm) {
	EXPECT_THROW(intern->makeForm("invalid form", "TestTarget"), Intern::InvalidFormException);
}