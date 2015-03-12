#include <iostream>
#include <ctime>
#include <string>
#include "expression.h"

void testStackQueue();

int main()
{
	std::string input;
	std::cout << "Enter expression (don't use white spaces): " << std::endl;
	std::cin >> input;

	std::string output = expressionConversion(input);

	std::cout << std::endl << output << std::endl;

	std::cout << std::endl << "Result: ";
	std::cout << evaluateExpression(output) << std::endl;

	system("pause");
	return 0;
}