#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "expression.h"

using namespace std;

// Protótipo das funções parse
Expression* parseExpression(const string&, size_t&);
Expression* parseOrExp(const string&, size_t&);
Expression* parseAndExp(const string&, size_t&);
Expression* parseEqExp(const string&, size_t&);
Expression* parseRelExp(const string&, size_t&);
Expression* parseAddExp(const string&, size_t&);
Expression* parseMulExp(const string&, size_t&);
Expression* parseUnaryExp(const string&, size_t&);
Expression* parsePrimaryExp(const string&, size_t&);
Expression* parseLiteralExp(const string&, size_t&);

#endif // PARSER_H
