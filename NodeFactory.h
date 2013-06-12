#pragma once

#include "AbstractNode.h"
#include "NodeType.h"

class NodeFactory
{
private:
	AbstractNode *createOpenBracket();
	AbstractNode *createCloseBracket();
	AbstractNode *createMul();
	AbstractNode *createMinus();
	AbstractNode *createDiv();
	AbstractNode *createAdd();
	AbstractNode *createOperand(std::string &operand);
public:
	NodeFactory(void);
	~NodeFactory(void);
	AbstractNode *create(enum NodeType type, std::string &token);
};

