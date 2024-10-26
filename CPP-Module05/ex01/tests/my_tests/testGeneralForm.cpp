#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class FormTest : public ::testing::Test {
protected:
	Form *demissional;
	Form *form;

	std::string captureOutput(std::function<void()> func) {
		std::ostringstream oss;
		std::streambuf* oldCoutBuffer = std::cout.rdbuf();

		std::cout.rdbuf(oss.rdbuf());
		func();
		std::cout.rdbuf(oldCoutBuffer);

		return oss.str();
	}

	void SetUp() override {
		demissional = new Form("Dismissal Form", 20, 2);
		form = new Form("Generic Form", 150, 150);
	}

	void TearDown() override {
		delete demissional;
		delete form;
	}
};

// Teste de inicialização por construtor padrão
TEST_F(FormTest, DefaultConstructor) {
	Form defaultForm;
	EXPECT_EQ(defaultForm.getName(), "Generic Form");
	EXPECT_EQ(defaultForm.getGradeToSign(), 150);
	EXPECT_EQ(defaultForm.getGradeToExecute(), 150);
	EXPECT_FALSE(defaultForm.getIsSigned());
}

// Teste de inicialização por construtor parametrizado
TEST_F(FormTest, ParameterizedConstructor) {
	EXPECT_EQ(demissional->getName(), "Dismissal Form");
	EXPECT_EQ(demissional->getGradeToSign(), 20);
	EXPECT_EQ(demissional->getGradeToExecute(), 2);
	EXPECT_FALSE(demissional->getIsSigned());
}

// Teste de assinatura bem-sucedida
TEST_F(FormTest, SuccessfulSign) {
	Bureaucrat highRank("High Rank", 10);
	EXPECT_NO_THROW(demissional->beSigned(highRank));
	EXPECT_TRUE(demissional->getIsSigned());
}

// Teste de falha ao assinar por grade baixa
TEST_F(FormTest, SignFailureDueToLowGrade) {
	Bureaucrat lowRank("Low Rank", 25);
	EXPECT_THROW(demissional->beSigned(lowRank), Form::GradeTooLowException);
	EXPECT_FALSE(demissional->getIsSigned());
}

// Teste da exceção GradeTooLowException
TEST_F(FormTest, GradeTooLowException) {
	Bureaucrat lowRank("Low Rank", 150);  // Bureaucrat com grade muito baixa
	EXPECT_THROW(demissional->beSigned(lowRank), Form::GradeTooLowException);
}

// Teste de cópia e atribuição
TEST_F(FormTest, CopyAndAssignment) {
	Form copy = *demissional;
	EXPECT_EQ(copy.getName(), demissional->getName());
	EXPECT_EQ(copy.getGradeToSign(), demissional->getGradeToSign());
	EXPECT_EQ(copy.getGradeToExecute(), demissional->getGradeToExecute());
	EXPECT_EQ(copy.getIsSigned(), demissional->getIsSigned());

	Form assigned("Assigned Form", 100, 100);
	assigned = *form;
	EXPECT_EQ(assigned.getName(), form->getName());
	EXPECT_EQ(assigned.getGradeToSign(), form->getGradeToSign());
	EXPECT_EQ(assigned.getGradeToExecute(), form->getGradeToExecute());
	EXPECT_EQ(assigned.getIsSigned(), form->getIsSigned());
}

// Teste da saída do operador de stream
TEST_F(FormTest, OutputOperator) {
	std::string output = captureOutput([&]() { std::cout << *demissional; });
	std::string expectedOutput = "Dismissal Form, Grade to sign is 20, grade to execute is 2, signature status 0";
	EXPECT_EQ(output, expectedOutput);
}