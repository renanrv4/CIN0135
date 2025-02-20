#include "../expression.h"
#include <stdexcept>

using namespace std;

// Sobrescrita de operadores
namespace Operators {
	struct ExpressionValue {
		public: 
			double value;
			bool isBoolean;

			ExpressionValue(double value, bool isBoolean = false) {
				this->value = isBoolean ? static_cast<bool>(value) : value;
				this->isBoolean = isBoolean;
			}

			double getValue() const { return isBoolean ? static_cast<bool>(value) : value; }
			bool getIsBoolean() const { return isBoolean; }

			ExpressionValue operator+(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value + other.value);
			}

			ExpressionValue operator-(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value - other.value);
			}

			ExpressionValue operator*(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value * other.value);
			}

			ExpressionValue operator/(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				if (other.value == 0) {
					throw runtime_error("Divisão por zero");
				}
				return ExpressionValue(value / other.value);
			}

			ExpressionValue operator&&(const ExpressionValue& other) const {
				if (!isBoolean || !other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(static_cast<bool>(value) && static_cast<bool>(other.value), true);
			}

			ExpressionValue operator||(const ExpressionValue& other) const {
				if (!isBoolean || !other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(static_cast<bool>(value) || static_cast<bool>(other.value), true);
			}

			ExpressionValue operator==(const ExpressionValue& other) const {
				return ExpressionValue(value == other.value, true);
			}

			ExpressionValue operator!=(const ExpressionValue& other) const {
				return ExpressionValue(value != other.value, true);
			}

			ExpressionValue operator<(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value < other.value, true);
			}

			ExpressionValue operator<=(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value <= other.value, true);
			}

			ExpressionValue operator>(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value > other.value, true);
			}

			ExpressionValue operator>=(const ExpressionValue& other) const {
				if (isBoolean || other.isBoolean) {
					throw invalid_argument("Operação inválida");
				}
				return ExpressionValue(value >= other.value, true);
			}
	};
}

// Métodos da subclasse BinaryOperation
BinaryOperation::BinaryOperation(const string& op, Expression* left, Expression* right) {
	setOperation(op);
	this->left = left;
	this->right = right;
	left = nullptr;
	right = nullptr;
}

BinaryOperation::BinaryOperation(const BinaryOperation& other) {
	setOperation(other.operation);
	left = new Literal(*dynamic_cast<Literal*>(other.left));
	right = new Literal(*dynamic_cast<Literal*>(other.right));
}

BinaryOperation::~BinaryOperation() {
	delete left; delete right;
}

double BinaryOperation::evaluate() const {
	Operators::ExpressionValue left_val(left->evaluate(), left->isBoolean());
	Operators::ExpressionValue right_val(right->evaluate(), right->isBoolean());

	if (operation == "+") { return (left_val + right_val).getValue(); }
	if (operation == "-") { return (left_val - right_val).getValue(); }
	if (operation == "*") { return (left_val * right_val).getValue(); }
	if (operation == "/") { return (left_val / right_val).getValue(); }
	if (operation == "&&") { return (left_val && right_val).getValue(); }
	if (operation == "||") { return (left_val || right_val).getValue(); }
	if (operation == "==") {
		if(left_val.getIsBoolean() && !right_val.getIsBoolean()) {
			throw invalid_argument("Sintaxe Inválida");
		}
		if(!left_val.getIsBoolean() && right_val.getIsBoolean()) {
			throw invalid_argument("Sintaxe Inválida");
		}
		return (left_val == right_val).getValue();
	}
	if (operation == "!=") { 
		if(left_val.getIsBoolean() && !right_val.getIsBoolean()) {
			throw invalid_argument("Sintaxe Inválida");
		}
		if(!left_val.getIsBoolean() && right_val.getIsBoolean()) {
			throw invalid_argument("Sintaxe Inválida");
		}
		return (left_val != right_val).getValue(); 
	}
	if (operation == "<") { return (left_val < right_val).getValue(); }
	if (operation == "<=") { return (left_val <= right_val).getValue(); }
	if (operation == ">") { return (left_val > right_val).getValue(); }
	if (operation == ">=") { return (left_val >= right_val).getValue(); }
	
	throw invalid_argument("Sintaxe Inválida");
}

bool BinaryOperation::isBoolean() const {
	return operation == "&&" || operation == "||" || 
		   operation == "==" || operation == "!=" || 
		   operation == "<" || operation == "<=" || 
		   operation == ">" || operation == ">=";
}

string BinaryOperation::toString() const {
	return "(" + left->toString() + " " + operation + " " + right->toString() + ")";
}