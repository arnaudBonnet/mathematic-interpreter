#include "ArithmeticExpressionInterpreter.h"


ArithmeticExpressionInterpreter::ArithmeticExpressionInterpreter(void)
{
}

bool ArithmeticExpressionInterpreter::interpret(std::string &expression, double &result)
{
	if (automaton.checkSynthax(expression) == false)
	{
		return false;
	}
	std::queue<AbstractNode *> queue = automaton.getNodeQueue();
	astBuilder.setQueue(queue);
	AbstractNode *root = astBuilder.buildAST();
	automaton.clear();
	if (root == NULL)
	{
		return false;
	}
	result = computeTree(root);
	return true;
}

double ArithmeticExpressionInterpreter::computeTree(AbstractNode *root)
{
	root->compute();
	return root->getData()->getOperandValue();
}


ArithmeticExpressionInterpreter::~ArithmeticExpressionInterpreter(void)
{
}
