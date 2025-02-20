#include <iostream>
#include "expression.h"
#include "ExpressionTypes/literal.cpp"
#include "ExpressionTypes/binaryExpression.cpp"
#include "ExpressionTypes/unaryExpression.cpp"
#include "parser.h"
#include "parser.cpp"

using namespace std;

int main() {
	int tests; cin >> tests;
	cin.sync(); cin.clear(); 
	expressionInterpreter(tests);
	return 0;
}