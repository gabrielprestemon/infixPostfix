#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <string>

std::string expressionConversion(std::string input);
bool checkPrecedence(char pushing, char top);
bool isOperator(char c);
double operate(double a, double b, char c);
double evaluateExpression(std::string input);

#endif