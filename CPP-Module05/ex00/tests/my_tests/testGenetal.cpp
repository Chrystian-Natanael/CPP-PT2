#include <gtest/gtest.h>
#include "Bureaucrat.hpp"

class BureaucratTest : public ::testing::Test {
protected:
	Bureaucrat* bureaucrat;

	void SetUp() override {
		bureaucrat = new Bureaucrat("Von Buroc", 75);
	}

	void TearDown() override {
		delete bureaucrat;
	}
};

// Teste de Construtor Padrão
TEST_F(BureaucratTest, DefaultConstructor) {
	Bureaucrat defaultBureaucrat;
	EXPECT_EQ(defaultBureaucrat.getName(), "NULL");
	EXPECT_EQ(defaultBureaucrat.getGrade(), 0);
}

// Teste de Construtor com Nome e Grau Válidos
TEST_F(BureaucratTest, ConstructorWithValidNameAndGrade) {
	EXPECT_EQ(bureaucrat->getName(), "Von Buroc");
	EXPECT_EQ(bureaucrat->getGrade(), 75);
}

// Teste de Exceção para Grau Muito Alto
TEST(BureaucratTestExceptions, GradeTooHigh) {
	EXPECT_THROW(Bureaucrat("High Grade", 0), Bureaucrat::GradeTooHighException);
}

// Teste de Exceção para Grau Muito Baixo
TEST(BureaucratTestExceptions, GradeTooLow) {
	EXPECT_THROW(Bureaucrat("Low Grade", 151), Bureaucrat::GradeTooLowException);
}

// Teste de Incremento de Grau
TEST_F(BureaucratTest, IncrementGrade) {
	bureaucrat->incrementGrade();
	EXPECT_EQ(bureaucrat->getGrade(), 74);
	EXPECT_THROW({
		while (bureaucrat->getGrade() < 150)
			bureaucrat->incrementGrade();
		bureaucrat->incrementGrade(); // Este deve lançar a exceção
	}, Bureaucrat::GradeTooHighException);
}

// Teste de Decremento de Grau
TEST_F(BureaucratTest, DecrementGrade) {
	bureaucrat->decrementGrade();
	EXPECT_EQ(bureaucrat->getGrade(), 76);
	EXPECT_THROW({
		while (bureaucrat->getGrade() < 150)
			bureaucrat->decrementGrade();
		bureaucrat->decrementGrade(); // Este deve lançar a exceção
	}, Bureaucrat::GradeTooLowException);
}

// Teste de Cópia
TEST_F(BureaucratTest, CopyConstructor) {
	Bureaucrat copyBureaucrat(*bureaucrat);
	EXPECT_EQ(copyBureaucrat.getName(), bureaucrat->getName());
	EXPECT_EQ(copyBureaucrat.getGrade(), bureaucrat->getGrade());
}

// Teste de Atribuição
TEST_F(BureaucratTest, AssignmentOperator) {
	Bureaucrat anotherBureaucrat("Another", 100);
	anotherBureaucrat = *bureaucrat;
	EXPECT_EQ(anotherBureaucrat.getName(), bureaucrat->getName());
	EXPECT_EQ(anotherBureaucrat.getGrade(), bureaucrat->getGrade());
}

// Teste do Operador de Saída
TEST_F(BureaucratTest, OutputOperator) {
	std::ostringstream oss;
	oss << *bureaucrat;
	EXPECT_EQ(oss.str(), "Von Buroc, bureaucrat grade 75");
}
