#include "NodeFactory.h"
#include "Operator.h"
#include "Operand.h"


AbstractNode *NodeFactory::createOpenBracket()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator('(');
	tmp->setPriority(3);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createCloseBracket()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator(')');
	tmp->setPriority(3);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createMul()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator('*');
	tmp->setPriority(2);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createMinus()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator('-');
	tmp->setPriority(1);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createDiv()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator('/');
	tmp->setPriority(2);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createAdd()
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operator();

	tmp->setOperator('+');
	tmp->setPriority(1);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::createOperand(std::string &token)
{
	AbstractNode *an = new AbstractNode();
	Data *tmp = new Operand();

	tmp->setOperandValue(atof(token.c_str()));
	tmp->setOperand(token);
	tmp->setPriority(4);
	an->setData(tmp);
	return an;
}

AbstractNode *NodeFactory::create(enum NodeType type, std::string &token)
{
	switch (type)
	{
	case OPERATOR_OPEN_BRACKET:
		return createOpenBracket();
		break;
	case OPERATOR_CLOSE_BRACKET:
		return createCloseBracket();
		break;
	case OPERATOR_MUL:
		return createMul();
		break;
	case OPERATOR_MINUS:
		return createMinus();
		break;
	case OPERATOR_DIV:
		return createDiv();
		break;
	case OPERATOR_ADD:
		return createAdd();
		break;
	case OPERAND:
		return createOperand(token);
		break;
	}
	return NULL;
}

NodeFactory::NodeFactory(void)
{
}


NodeFactory::~NodeFactory(void)
{
}
