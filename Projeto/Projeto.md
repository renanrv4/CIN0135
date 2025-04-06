### General Project Requirements Documentation

#### General Requirements

Your code must follow the object-oriented programming (OOP) paradigm. In general, there should be no global variables or standalone functions (except for main). Your program should be composed only of classes and methods. The use of friend should also be avoided. Any deviation from these recommendations must be documented and justified in the code.

Structure your code into .h and .cpp files following good practices. Make use of as many OOP concepts supported in C++ as possible, such as (but not limited to):
classes, methods, access modifiers (public, private, protected), namespaces, object pointers, object references, constructors, copy constructors, destructors, inline methods, getters/setters, pass-by-value, pass-by-reference, static attributes/methods, operator overloading (arithmetic, boolean, assignment, etc.), dynamic memory allocation, inheritance, method overriding, type casting (static and dynamic), virtual methods, abstract classes, exception handling, and templates.

#### Input

The input consists of multiple cases. The first line contains c (1 ≤ c ≤ 100,000), the number of cases. Then, c expressions follow, one per line. Each case consists of an arithmetic or boolean expression. All expressions are guaranteed to be syntactically correct.

```bash
7
1
2 + 3 * 2
( 2 - - -3 ) * 2
3 / 2
true || false == false
( true || false ) == false
true + 3
```

#### Expression Format and Parsing

The format of each expression follows the specification of the Context-Free Grammar (CFG) below, where the starting symbol is the non-terminal exp. Brackets [ A ] indicate optional elements. Double quotes are used to highlight the terminals of the language, which are always space-delimited. The symbol <literal> represents both integer literals (e.g., 2, -3) and boolean literals (true, false).

```bash
<exp>         ::= <or_exp>
<or_exp>      ::= <and_exp> [ “||” <and_exp> ]
<and_exp>     ::= <eq_exp> [ “&&” <eq_exp> ]
<eq_exp>      ::= <rel_exp> [ “==” <rel_exp> | “!=” <rel_exp> ]
<rel_exp>     ::= <add_exp> [ “<” <add_exp> | “>” <add_exp> | “<=” <add_exp> | “>=” <add_exp> ]
<add_exp>     ::= <mul_exp> [ “+” <mul_exp> | “-” <mul_exp> ]
<mul_exp>     ::= <unary_exp> [ “*” <unary_exp> | “/” <unary_exp> ]
<unary_exp>   ::= “-” <primary_exp> | <primary_exp>
<primary_exp> ::= <literal> | “(“ <exp> “)”
<literal>     ::= integer literals | boolean literals
```

Expressions can be parsed using the recursive descent parser algorithm. In this approach, each non-terminal symbol corresponds to a function, whose body reflects the corresponding grammar rule. Here's an example in pseudocode for parsing `<exp>` and `<or_exp>`:

```bash
Expression parse_exp() {
	return parse_or_exp();
}

Expression parse_or_exp() {
	Expression e1;
	e1 = parse_and_exp();
	if (current_token == “||”) {
		Operand op = new Operand(current_token);
	        read_next_token();
	        Expression e2;
	        e2 = parse_and_exp();
        return new BinaryExpression(e1, op, e2);		
	} else {
		return e1;
	}
}
```

#### Output

Print the result of evaluating each expression. If an error occurs during evaluation, print error (without quotation marks).

```bash
1
8
-2
1
true
false
error
```
