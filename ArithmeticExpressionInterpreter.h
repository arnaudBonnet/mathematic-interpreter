#pragma once

#include <string>
#include "ExpressionValidationMachine.h"
#include "ASTBuilder.h"

class ArithmeticExpressionInterpreter
{
protected:
	ExpressionValidationMachine automaton;
	ASTBuilder astBuilder;
public:
	ArithmeticExpressionInterpreter(void);
	bool interpret(std::string &expression, double &result);
	double computeTree(AbstractNode *root);
	~ArithmeticExpressionInterpreter(void);
};

