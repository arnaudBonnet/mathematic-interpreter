#include "OpenBracketState.h"
#include "NodeType.h"
#include "StateName.h"
#include "ExpressionValidationMachine.h"


OpenBracketState::OpenBracketState(void)
{
}

bool OpenBracketState::tryTransition(char c, ExpressionValidationMachine &e)
{
	if (c == '(')
	{
		e.pushOpenBracket();
		e.generateAndPushNode(OPERATOR_OPEN_BRACKET);
		return true;
	}
	if (c >= '0' || c <= '9')
	{
		e.setState(READ_OPERAND);
		e.pushTokenCharacter(c);
		return true;
	}
	if (c == '+' || c == '-')
	{
		if (c == '+')
		{
			e.generateAndPushNode(OPERATOR_ADD);
		}
		else
		{
			e.generateAndPushNode(OPERATOR_MINUS);
		}
		e.setState(READ_OPERATOR);
		return true;
	}
	return false;
}

bool OpenBracketState::isTerminalState()
{
	return false;
}

OpenBracketState::~OpenBracketState(void)
{
}

void OpenBracketState::stop(ExpressionValidationMachine &e)
{
}