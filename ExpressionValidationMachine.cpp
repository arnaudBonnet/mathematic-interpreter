#include <iostream>
#include "ExpressionValidationMachine.h"
#include "StartState.h"
#include "ReadOperatorState.h"
#include "ReadOperandState.h"
#include "OpenBracketState.h"
#include "CloseBracketState.h"
#include "StateName.h"
#include "NodeType.h"
#include "Operator.h"
#include "Operand.h"

ExpressionValidationMachine::ExpressionValidationMachine(void)
{
	this->currentState = new StartState();
	states[START] = this->currentState;
	states[READ_OPERAND] = new ReadOperandState;
	states[OPEN_BRACKET] = new OpenBracketState;
	states[READ_OPERATOR] = new ReadOperatorState;
	states[CLOSE_BRACKET] = new CloseBracketState;
}

void ExpressionValidationMachine::clear()
{
	this->setState(START);
	this->fileToken = "";
	while (this->bracketStack.empty() == false)
	{
		this->bracketStack.pop();
	}
	while (this->fileNode.empty() == false)
	{
		this->fileNode.pop();
	}
}

ExpressionValidationMachine::~ExpressionValidationMachine(void)
{
}

const std::string &ExpressionValidationMachine::getTokenFile()
{
	return this->fileToken;
}

bool ExpressionValidationMachine::checkSynthax(std::string &s)
{
	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] != ' ')
		{
			if (currentState->tryTransition(s[i], *this) == false)
			{
				return false;
			}
		}
	}
	currentState->stop(*this);
	if (bracketStack.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ExpressionValidationMachine::dumpNodes()
{
	int i = 1;

	while (this->fileNode.empty() == false)
	{
		AbstractNode *tmp = fileNode.front();
		fileNode.pop();
		std::cout<<"Noeud "<<i<<" : ==============="<<std::endl;
		tmp->dump();
		std::cout<<"================================"<<std::endl;
		i++;
	}
}

bool ExpressionValidationMachine::setState(enum StateName state)
{
	std::map<enum StateName, AbstractState *>::iterator it = states.find(state);

	if (it == states.end())
	{
		return false;
	}
	currentState = it->second;
	return true;
}

void ExpressionValidationMachine::pushOpenBracket()
{
	bracketStack.push('(');
}

void ExpressionValidationMachine::pushCloseBracket()
{
	if (bracketStack.top() == '(')
	{
		bracketStack.pop();
	}
	else
	{
		bracketStack.push(')');
	}
}

bool ExpressionValidationMachine::generateAndPushNode(enum NodeType node_type)
{
	AbstractNode *node;

	node = nf.create(node_type, fileToken);
	if (node == false)
	{
		return false;
	}
	fileNode.push(node);
	if (node_type == OPERAND)
	{
		fileToken = "";
	}
	return true;
}

std::queue<AbstractNode *> ExpressionValidationMachine::getNodeQueue()
{
	return this->fileNode;
}

void ExpressionValidationMachine::pushTokenCharacter(char c)
{
	fileToken += c;
}
