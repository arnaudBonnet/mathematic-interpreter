#include "StartState.h"
#include "StateName.h"
#include "NodeType.h"


bool StartState::tryTransition(char c, ExpressionValidationMachine &ref)
{
	if (c >= '0' && c <= '9')
	{
		ref.pushTokenCharacter(c);
		ref.setState(READ_OPERAND);
		return true;
	}
	if (c == '(')
	{
		ref.pushOpenBracket();
		ref.generateAndPushNode(OPERATOR_OPEN_BRACKET);
		ref.setState(OPEN_BRACKET);
		return true;
	}
	if (c == '-' || c == '+')
	{
		if (c == '+')
		{
		 ref.generateAndPushNode(OPERATOR_ADD);
		}
		else
		{
		 ref.generateAndPushNode(OPERATOR_MINUS);
		}
		ref.setState(READ_OPERATOR);
		return true;
	}
 return false;
}

void StartState::stop(ExpressionValidationMachine &e)
{
}

bool StartState::isTerminalState()
{
	return false;
}

StartState::StartState(void)
{
}


StartState::~StartState(void)
{
}
