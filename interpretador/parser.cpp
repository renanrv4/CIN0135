#include "parser.h"
#include "expression.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

using namespace std;

inline char jumpSpace(const string& input, size_t& position) {
	while(position < input.size() && input.at(position) == ' ') {
		position++;
	}
	return position < input.size() ? input.at(position) : '\0';
}

inline Expression* parseExpression(const string& input, size_t& position) {
	return parseOrExp(input, position);
}

Expression* parseOrExp(const string& input, size_t& position) {
	auto left = parseAndExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '|' && (position + 1) < input.size() && input.at(position + 1) == '|') {
			position = position + 2; // Consumindo o token "||"
			Expression* right = parseAndExp(input, position);
			Expression* temp = new BinaryOperation("||", left, right);
			left = temp;
		} else {
			break;
		}
	}
	return left;
}

Expression* parseAndExp(const string& input, size_t& position) {
	auto left = parseEqExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '&' && (position + 1) < input.size() && input.at(position + 1) == '&') {
			position = position + 2; // Consumindo o token "&&"
			Expression* right = parseEqExp(input, position);
			Expression* temp = new BinaryOperation("&&", left, right);
			left = temp;
		} else {
			break;
		}
	}
	return left;
}

Expression* parseEqExp(const string& input, size_t& position) {
	auto left = parseRelExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '=' && (position + 1) < input.size() && input.at(position + 1) == '=') {
			position = position + 2; // Consumindo o token "=="
			Expression* right = parseRelExp(input, position);
			Expression* temp = new BinaryOperation("==", left, right);
			left = temp;
		} else if (c == '!' && (position + 1) < input.size() && input.at(position + 1) == '=') {
			position = position + 2; // Consumindo o token "!="
			Expression* right = parseRelExp(input, position);
			Expression* temp = new BinaryOperation("!=", left, right);
			left = temp;
		} else {
			break;
		}
	}
	return left;
}

Expression* parseRelExp(const string& input, size_t& position) {
	auto left = parseAddExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '<') {
			if((position + 1) < input.size() && input.at(position + 1) == '=') {
				position = position + 2; // Consumindo o token "<="
				Expression* right = parseAddExp(input, position);
				Expression* temp = new BinaryOperation("<=", left, right);
				left = temp;
			} else {
				position++; // Consumindo o token "<"
				Expression* right = parseAddExp(input, position);
				Expression* temp = new BinaryOperation("<", left, right);
				left = temp;
			}
		} else if (c == '>') {
			if((position + 1) < input.size() && input.at(position + 1) == '=') {
				position = position + 2; // Consumindo o token ">="
				Expression* right = parseAddExp(input, position);
				Expression* temp = new BinaryOperation(">=", left, right);
				left = temp;
			} else {
				position++; // Consumindo o token ">"
				Expression* right = parseAddExp(input, position);
				Expression* temp = new BinaryOperation(">", left, right);
				left = temp;
			}
		} else {
			break;
		}
	}
	return left;
}

Expression* parseAddExp(const string& input, size_t& position) {
	auto left = parseMulExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '+') {
			position++; // Consumindo o token "+"
			Expression* right = parseMulExp(input, position);
			Expression* temp = new BinaryOperation("+", left, right);
			left = temp;
		} else if (c == '-') {
			position++; // Consumindo o token "-"
			Expression* right = parseMulExp(input, position);
			Expression* temp = new BinaryOperation("-", left, right);
			left = temp;
		} else {
			break;
		}
	}
	return left;
}

Expression* parseMulExp(const string& input, size_t& position) {
	auto left = parseUnaryExp(input, position);
	while (true) {
		char c = jumpSpace(input, position);
		if (c == '*') {
			position++; // Consumindo o token "*"
			Expression* right = parseUnaryExp(input, position);
			Expression* temp = new BinaryOperation("*", left, right);
			left = temp;
		} else if (c == '/') {
			position++; // Consumindo o token "/"
			Expression* right = parseUnaryExp(input, position);
			Expression* temp = new BinaryOperation("/", left, right);
			left = temp;
		} else {
			break;
		}
	}
	return left;
}

Expression* parseUnaryExp(const string& input, size_t& position) {
	char c = jumpSpace(input, position);
	if (c == '-') {
		position++; // Consumindo o token "-"
		Expression* operand = parseUnaryExp(input, position);
		return new UnaryOperation("-", operand);
	}
	return parsePrimaryExp(input, position);
}

Expression* parsePrimaryExp(const string& input, size_t& position) {
	char c = jumpSpace(input, position);
	if (c == '(') {
		position++; // Consumindo o token "("
		Expression* expr = parseExpression(input, position);
		c = jumpSpace(input, position);
		if (c != ')') {
			throw invalid_argument("Token não encontrado");
		}
		position++; // Consumindo o token ")"
		return expr;
	}
	return parseLiteralExp(input, position);
}

Expression* parseLiteralExp(const string& input, size_t& position) {
	string token;
	while (position < input.size() && isdigit(input.at(position))) {
		token += input.at(position++);
	}
	if (!token.empty()) {
		// Transformando valor da string em double
		return new Literal(stod(token));
	}

	jumpSpace(input, position);
	if ((position + 4) <= input.size() && input.substr(position, 4) == "true") {
		position = position + 4; // Consumindo a string "true"
		return new Literal(true);
	} else if ((position + 5) <= input.size() && input.substr(position, 5) == "false") {
		position = position + 5; // Consumindo a string "false"
		return new Literal(false);
	}
	throw invalid_argument("Token não encontrado");
}

void expressionInterpreter(int tests) {
	for (int i = 0; i < tests; i++) {
		size_t position = 0;
		string input; getline(cin, input);
		try {
			Expression* expression = parseExpression(input, position);
			if (expression->isBoolean()) {
				cout << (expression->evaluate() ? "true" : "false") << "\n";
			} else {
				cout << static_cast<int>(expression->evaluate()) << "\n";
			}
			delete expression;
		} catch (const exception& e) {
			cout << "error" << "\n";
		}
	}
}