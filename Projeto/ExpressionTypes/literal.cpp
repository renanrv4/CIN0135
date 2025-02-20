#include "../expression.h"
#include <stdexcept>

using namespace std;

// Métodos da subclasse Literal
Literal::Literal(double val) {
	setIsBool(false);
	setValue(val);
}
Literal::Literal(bool val) {
	setIsBool(true);
	setBValue(val);
}

Literal::Literal(const Literal& other) {
	setIsBool(other.isBool);
	if(isBool) {
		setBValue(other.value);
	} else {
		setValue(other.value);
	}
}

double Literal::evaluate() const {
	return isBool ? static_cast<double>(bvalue) : value;
}

bool Literal::isBoolean() const {
	return isBool;
}

string Literal::toString() const {
	if (isBool) {
		return bvalue ? "true" : "false";
	} else {
		return to_string(value);
	}
}