#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

class BureaucratTest : public ::testing::Test {
protected:
	Bureaucrat* bureaucrat;
	PresidentialPardonForm* form;

	void SetUp() override {
		bureaucrat = new Bureaucrat("TestBureaucrat", 5);
		form = new PresidentialPardonForm("TestTarget");
	}

	void TearDown() override {
		delete bureaucrat;
		delete form;
	}
};

// Mock class for AForm to test Bureaucrat::executeForm
class MockForm : public AForm {
public:
	MockForm() : AForm("MockForm", 25, 5) {}
	void execute(Bureaucrat const &executor) const override {
		if (executor.getGrade() > 5) {
			throw AForm::GradeTooLowException();
		}
		if (!this->getIsSigned()) {
			throw AForm::FormNotSignedException();
		}
	}
};

// Test function with success
TEST_F(BureaucratTest, ExecuteFormSuccess) {
	form->beSigned(*bureaucrat);
	EXPECT_NO_THROW(bureaucrat->executeForm(*form));
}

