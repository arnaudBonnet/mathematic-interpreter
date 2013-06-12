#include "ReadOperatorState.h"
#include "StateName.h"
#include "NodeType.h"
#include "ExpressionValidationMachine.h"

ReadOperatorState::ReadOperatorState(void)
{
}

bool ReadOperatorState::tryTransition(char c, ExpressionValidationMachine& e)
{
	if (c == '(')
	{
		e.pushOpenBracket();
		e.generateAndPushNode(OPERATOR_OPEN_BRACKET);
		e.setState(OPEN_BRACKET);
		return true;
	}
	if (c == ')')
	{
		e.pushCloseBracket();
		e.generateAndPushNode(OPERATOR_CLOSE_BRACKET);
		e.setState(CLOSE_BRACKET);
		return true;
	}
	if (c >= '0' && c <= '9')
	{
		e.pushTokenCharacter(c);
		e.setState(READ_OPERAND);
		return true;
	}
	return false;
}

void ReadOperatorState::stop(ExpressionValidationMachine &e)
{
}

bool ReadOperatorState::isTerminalState()
{
	return false;
}

ReadOperatorState::~ReadOperatorState(void)
{
}
