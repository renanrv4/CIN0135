# Expression Interpreter – C++ Project

This project is an **Expression Interpreter** developed using **Object-Oriented Programming in C++**. It supports both **arithmetic** and **logical expressions**, and was implemented as part of a Data Structures and OOP course.

---

## 📁 Project Structure

Here's a breakdown of the main files and folders in the project:

- ### `main.cpp`
  The main file of the project. This is where input is received and passed on to other components to be parsed and evaluated.

- ### `Expression.h`
  Contains the abstract class `Expression`, which serves as the base class for:
  - `Literal`
  - `UnaryExpression`
  - `BinaryExpression`

  These classes are responsible for representing parts of an expression.  
  **Example:**  
  The expression `3 / 2` would be represented by a `BinaryExpression` object, where:
  - `3` is the left operand  
  - `/` is the operator  
  - `2` is the right operand

- ### `ExpressionTypes/`
  This folder contains the implementation of the expression types:
  - `Literal.cpp`
  - `UnaryExpression.cpp`
  - `BinaryExpression.cpp`  
  These files implement the logic of the methods declared in `Expression.h`.

- ### `Parse.h`
  Declares the parser functions responsible for analyzing the expressions.

- ### `Parse.cpp`
  Contains the implementation of the parser functions declared in `Parse.h`.

---

## ⚙️ Compilation & Execution

This project was compiled using **g++ (version 6.3.0)**.  
To compile and run the program, follow these steps:

1. **Compile the project:**

   ```bash
   g++ main.cpp -o <executable_name>
   ```
