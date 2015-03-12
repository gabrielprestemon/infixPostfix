#include "expression.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <cctype>

std::string expressionConversion(std::string input)
{
	Queue<char> expression;
	Stack<char> operators;

	//cycle through the input string
	for (int i = 0; i < input.length(); i++){
		//if the character is a digit push it directly into the queue
		if (isdigit(input[i])){
			expression.pushBack(input[i]);
			//for floating point numbers
			if (input[i + 1] == '.'){
				expression.pushBack(input[++i]);
			}
		}
		//if the character is a left parenthesis operator push it into the stack
		else if (input[i] == '(' || input[i] == '[' || input[i] == '{'){
			operators.pushTop(input[i]);
		}
		//if the character is a right parenthesis operator, pop the stack into the queue until the left
		else if (input[i] == ')' && !operators.isEmpty()){
			char popped = operators.popTop();
			while (popped != '('){
				expression.pushBack(' ');
				expression.pushBack(popped);
				if (!operators.isEmpty()){
					popped = operators.popTop();
				}
				if (popped == '('){
					break;
				}
			}
		}
		//if the character is a right parenthesis operator, pop the stack into the queue until the left
		else if (input[i] == ']' && !operators.isEmpty()){
			char popped = operators.popTop();
			while (popped != '[' && !operators.isEmpty()){
				expression.pushBack(' ');
				expression.pushBack(popped);
				if (!operators.isEmpty()){
					popped = operators.popTop();
				}
			}
		}
		//if the character is a right parenthesis operator, pop the stack into the queue until the left
		else if (input[i] == '}' && !operators.isEmpty()){
			char popped = operators.popTop();
			while (popped != '{' && !operators.isEmpty()){
				expression.pushBack(' ');
				expression.pushBack(popped);
				if (!operators.isEmpty()){
					popped = operators.popTop();
				}
			}
		}
		//if the character is an operator check precedence and push it into the stack
		else if(isOperator(input[i])){
			//put a space into the expression to make it look pretty
			expression.pushBack(' ');
			//if the precedence is true (greater), pop until necessary
			while (!operators.isEmpty() && checkPrecedence(input[i], operators.checkTop())){
				//push the operator into the expression
				expression.pushBack(operators.popTop());
				//push a space into the expression to make it look pretty
				expression.pushBack(' ');
			}
			//else just push into the stack
			operators.pushTop(input[i]);
		}
		//else the character is not an operator, digit, or parenthesis, or mathematic thing, ignore
	}

	//when done pop stack into expression
	while (!operators.isEmpty()){
		//push a space into the expression to make it look pretty
		expression.pushBack(' ');
		//push the operator into the expression
		expression.pushBack(operators.popTop());
	}

	//put the postfix expression back into a string
	std::string output;
	while (!expression.isEmpty()){
		output.push_back(expression.popFront());
	}

	return output;
}

///returns true if the stack needs to be popped, false if not
//false includes left parenthesis
bool checkPrecedence(char pushing, char top)
{
	int topPrecedence, pushPrecedence;

	if (top == '(' || top == '[' || top == '{'){
		return false;
	}

	//set top's precedence level
	if (top == '+' || top == '-'){
		topPrecedence = 1;
	}
	else{
		topPrecedence = 2;
	}
	//set pushing's precedence level
	if (pushing == '+' || pushing == '-'){
		pushPrecedence = 1;
	}
	else{
		pushPrecedence = 2;
	}

	if (pushPrecedence > topPrecedence){
		return false;
	}
	else{
		return true;
	}
}

//returns true if input is an arithmetic operator
bool isOperator(char c)
{
	switch (c){
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

double evaluateExpression(std::string input)
{
	Stack<double> evaluation;

	for (int i = 0; i < input.length(); i++){
		//if it's an digit
		if (isdigit(input[i])){
			//this holds the sum for multi-digit numbers
			double temp = 0;
			//these deal with floating point numbers
			bool floatingPoint = false;
			int decimal = 0;

			//deal with multi-digit numbers
			while (isdigit(input[i])){
				temp *= 10;
				temp += input[i++] - '0';
				//increment decimal places, if there are decimals
				if (floatingPoint){
					decimal++;
				}
				//if there's a decimal start counting places
				if (input[i] == '.'){
					floatingPoint = true;
					i++;
				}
			}
			//if there are decimal places, move decimal into place
			//this is mainly to avoid dividing by zero
			if (decimal){
				temp /= pow(10, decimal);
			}
			//push the result
			evaluation.pushTop(temp);
		}
		//if it's an operator
		else if (isOperator(input[i])){
			//pop the top two numbers
			double a = evaluation.popTop();
			double b = evaluation.popTop();
			//and operate appropriately
			evaluation.pushTop(operate(b, a, input[i]));
		}
	}

	//return the result, which is the only thing left in the stack
	return evaluation.popTop();
}

//operates on the input: a b c (ex: 2 3 -)
//operates as a c b (ex: 2 - 3)
double operate(double a, double b, char c)
{
	switch (c){
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0;
	}
}