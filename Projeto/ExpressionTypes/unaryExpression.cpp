#include "../expression.h"
#include <stdexcept>

using namespace std;

// Métodos da subclasse UnaryOperation
UnaryOperation::UnaryOperation(const string& op, Expression* operand) {
	setOperation(op);
	this->operand = operand;
	operand = nullptr;
}

UnaryOperation::UnaryOperation(const UnaryOperation& other) {
	setOperation(other.operation);
	operand = new Literal(*dynamic_cast<Literal*>(other.operand));
}

UnaryOperation::~UnaryOperation() {
	delete operand;
}

double UnaryOperation::evaluate() const {
	double val = operand->evaluate();
	if(operand->isBoolean()) {
		throw logic_error("Operação inválida");
	}
	if (operation == "-") { return -val; }
	throw invalid_argument("Sintaxe Inválida");
}

bool UnaryOperation::isBoolean() const {
	return operation == "";
}

string UnaryOperation::toString() const {
	return "(" + operation + operand->toString() + ")";
}