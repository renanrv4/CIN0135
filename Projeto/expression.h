#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <stdexcept>

using namespace std;

// Classe base Expression
class Expression {
	public:
		virtual ~Expression() = default;
		virtual double evaluate() const = 0;
		virtual bool isBoolean() const = 0;
		virtual string toString() const = 0;
};

// Subclasse para valores literais
class Literal : public Expression {
	private:
		bool isBool;
		union {
			double value;
			bool bvalue;
		};
	public:
		// Métodos Construtores
		Literal(double val);
		Literal(bool val);
		Literal(const Literal& other); // Construtor cópia

		// Métodos de acesso
		bool getIsBool() const {
			return isBool;
		}
		void setIsBool(bool isBool) {
			this->isBool = isBool;
		}
		double getValue() const {
			if(isBool) {
				throw logic_error("Argumento Inválido");
			}
			return value;
		};
		void setValue(double val) {
			isBool = false;
			this->value = val;
		};
		bool getBValue() const {
			if(!isBool) {
				throw logic_error("Argumento Inválido");
			}
			return bvalue;
		}
		void setBValue(bool val) {
			isBool = true;
			bvalue = val;
		}

		// Métodos para avaliar e transformar expressões
		double evaluate() const override;
		bool isBoolean() const override;
		string toString() const override;
};

// Subclasse para expressões com operador binário 
// (+, -, *, /, &&, ||, ==, !=, <, <=, >, >=)
class BinaryOperation : public Expression {
	private:
		string operation;
		Expression* left;
		Expression* right;
	public:
		// Métodos Construtores
		BinaryOperation(const string& op, Expression* left, Expression* right);
		BinaryOperation(const BinaryOperation& other);
		~BinaryOperation(); // Destrutor

		// Métodos de acesso
		string getOperation() const {
			return operation;
		}
		void setOperation(const string& op) {
			operation = op;
		}
		Expression* getLeft() const {
			return left;
		}
		void setLeft(Expression* left) {
			delete this->left;
			this->left = left;
		}
		Expression* getRight() const {
			return right;
		}
		void setRight(Expression* right) {
			delete this->right;
			this->right = right;
		}

		// Métodos para avaliar e transformar expressões
		double evaluate() const override;
		bool isBoolean() const override;
		string toString() const override;
};

// Subclasse para expressões com operador unário
// ( - )
class UnaryOperation : public Expression {
	private:
		string operation;
		Expression* operand;
	public:
		// Métodos Construtores
		UnaryOperation(const string& op, Expression* operand);
		UnaryOperation(const UnaryOperation& other);
		~UnaryOperation(); // Destrutor

		// Métodos de acesso
		string getOperation() const {
			return operation;
		}
		void setOperation(const string& op) {
			operation = op;
		};
		Expression* getOperand() const {
			return operand;
		};
		void setOperand(Expression* operand) {
			delete this->operand;
			this->operand = operand;
		}

		// Métodos para avaliar e transformar expressões
		double evaluate() const override;
		bool isBoolean() const override;
		string toString() const override;
};

#endif
