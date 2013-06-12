#include "ReadOperandState.h"
#include "StateName.h"
#include "NodeType.h"


ReadOperandState::ReadOperandState(void)
{
}

bool ReadOperandState::tryTransition(char c, ExpressionValidationMachine &ref)
{
	if ((c >= '0' && c <= '9') || c == '.')
	{
		ref.pushTokenCharacter(c);
		return true;
	}
	switch (c)
	{
		case ')':
			ref.pushCloseBracket();
			ref.generateAndPushNode(OPERAND);
			ref.generateAndPushNode(OPERATOR_CLOSE_BRACKET);
			ref.setState(CLOSE_BRACKET);
		break;
		case '*' :
			ref.generateAndPushNode(OPERAND);
			ref.generateAndPushNode(OPERATOR_MUL);
			ref.setState(READ_OPERATOR);
		break;
		case '-':
			ref.generateAndPushNode(OPERAND);
			ref.generateAndPushNode(OPERATOR_MINUS);
			ref.setState(READ_OPERATOR);
		break;
		case '/':
			ref.generateAndPushNode(OPERAND);
			ref.generateAndPushNode(OPERATOR_DIV);
			ref.setState(READ_OPERATOR);
		break;
		case '+':
			ref.generateAndPushNode(OPERAND);
			ref.generateAndPushNode(OPERATOR_ADD);
			ref.setState(READ_OPERATOR);
		break;
		default:
			return false;
		break;
	}
	return true;
}

void ReadOperandState::stop(ExpressionValidationMachine& e)
{
	if (e.getTokenFile() != "")
	{
		e.generateAndPushNode(OPERAND);
	}
}

bool ReadOperandState::isTerminalState()
{
	return true;
}

ReadOperandState::~ReadOperandState(void)
{
}
