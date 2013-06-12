#include <iostream>
#include "ArithmeticExpressionInterpreter.h"

int main()
{
	ArithmeticExpressionInterpreter interpreter;
	std::string cmd;
	double result;

	std::cout<<"Veuillez entrer une expression arithmetique ou tappez \"quit\":"<<std::endl;
	std::getline(std::cin, cmd);
	while (cmd != "quit")
	{
		if (interpreter.interpret(cmd, result) == false)
		{
			std::cout<<"A synthax error has occured."<<std::endl;
		}
		else
		{
			std::cout<<"Result = "<<result<<std::endl;
		}
	std::getline(std::cin, cmd);
	}
	return 0;
}
