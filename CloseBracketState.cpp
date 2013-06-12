#include "CloseBracketState.h"
#include "NodeType.h"
#include "StateName.h"
#include "ExpressionValidationMachine.h"

CloseBracketState::CloseBracketState(void)
{
}

bool CloseBracketState::tryTransition(char c, ExpressionValidationMachine& e)
{
	if (c == ')')
	{
		e.pushCloseBracket();
		e.generateAndPushNode(OPERATOR_CLOSE_BRACKET);
		return true;
	}
	switch (c)
	{
	case '+':
		e.generateAndPushNode(OPERATOR_ADD);
		e.setState(READ_OPERATOR);
		break;
	case '-':
		e.generateAndPushNode(OPERATOR_MINUS);
		e.setState(READ_OPERATOR);
		break;
	case '*':
		e.generateAndPushNode(OPERATOR_MUL);
		e.setState(READ_OPERATOR);
		break;
	case '/':
		e.generateAndPushNode(OPERATOR_DIV);
		e.setState(READ_OPERATOR);
		break;
	default:
		return false;
		break;
	}
	return true;
}

void CloseBracketState::stop(ExpressionValidationMachine &e)
{
}

bool CloseBracketState::isTerminalState()
{
	return true;
}

CloseBracketState::~CloseBracketState(void)
{
}
