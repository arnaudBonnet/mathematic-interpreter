#include <cstdlib>
#include <iostream>
#include "AbstractNode.h"
#include "Operand.h"

AbstractNode::AbstractNode(void)
{
	left = NULL;
	right = NULL;
	parent = NULL;
	data = NULL;
}

void AbstractNode::displayTree()
{
	std::cout<<"Current node =============="<<std::endl;
	dump();
	std::cout<<"==========================="<<std::endl;

	if (left != NULL)
	{
		left->displayTree();
	}
	if (right != NULL)
	{
		right->displayTree();
	}
}

void AbstractNode::dump()
{
	data->dump();
}

AbstractNode::~AbstractNode(void)
{
}


void AbstractNode::setLeft(AbstractNode *node)
{
	if (node != NULL)
	{
		node->parent = this;
	}
	this->left = node;
}

void AbstractNode::setRight(AbstractNode *node)
{
	if (node != NULL)
	{
		node->parent = this;
	}
	this->right = node;
}

void AbstractNode::setParent(AbstractNode *node)
{
	this->parent = node;
}

AbstractNode *AbstractNode::getParent()
{
	return this->parent;
}

AbstractNode *AbstractNode::getLeft()
{
	return this->left;
}

AbstractNode *AbstractNode::getRight()
{
	return this->right;
}

Data *AbstractNode::getData()
{
	return this->data;
}

void AbstractNode::setData(Data *data)
{
	this->data = data;
}

void AbstractNode::doOp()
{
	Data *tmp = new Operand();
	bool replace = true;

	switch (data->getOperator())
	{
		case '+':
			if (left == NULL && right == NULL)
			{
				delete tmp;
				return;
			}
			if (left != NULL && left->getData()->isOperator() == true && right == NULL)
			{
				if (left->getData()->getOperator() == '-')
				{
					data->setOperator('-');
				}
				delete tmp;
				return;
			}
			if (left == NULL && right != NULL && right->getData()->isOperand())
			{
				tmp->setOperandValue(right->getData()->getOperandValue());
			}
			if (left != NULL && right != NULL && left->getData()->isOperator() == true && right->getData()->isOperand() == true)
			{
				tmp->setOperandValue(right->getData()->getOperandValue());
				if (left->getData()->getOperator() == '-')
				{
					tmp->setOperandValue(tmp->getOperandValue() * -1.0);
				}
			}
			if (left != NULL && right != NULL && left->getData()->isOperand() == true && right->getData()->isOperand() == true)
			{
				tmp->setOperandValue(left->getData()->getOperandValue() + right->getData()->getOperandValue());
			}
		break;
		case '-':
			if (left == NULL && right == NULL)
			{
				delete tmp;
				return;
			}
			if (left != NULL && left->getData()->isOperator() == true && right == NULL)
			{
				if (left->getData()->getOperator() == '-')
				{
					data->setOperator('+');
				}
				delete tmp;
				return;
			}
			if (left == NULL && right != NULL && right->getData()->isOperand())
			{
				tmp->setOperandValue(right->getData()->getOperandValue() * -1.0);
			}
			if (left != NULL && right != NULL && left->getData()->isOperator() == true && right->getData()->isOperand() == true)
			{
				tmp->setOperandValue(right->getData()->getOperandValue());
				if (left->getData()->getOperator() == '-')
				{
					tmp->setOperandValue(tmp->getOperandValue() * -1.0);
				}
			}
			if (left != NULL && right != NULL && left->getData()->isOperand() == true && right->getData()->isOperand() == true)
			{
				tmp->setOperandValue(left->getData()->getOperandValue() - right->getData()->getOperandValue());
			}
		break;
		case '*':
			tmp->setOperandValue(left->getData()->getOperandValue() * right->getData()->getOperandValue());
		break;
		case '/':
			tmp->setOperandValue(left->getData()->getOperandValue() / right->getData()->getOperandValue());
		break;
		case '(':
			tmp->setOperandValue(left->getData()->getOperandValue());
		break;
	}
	delete data;
	data = tmp;
}

void AbstractNode::compute()
{
	if (this->data->isOperand())
	{
		return;
	}
	else
	{
		if (this->left != NULL)
		{
			this->left->compute();
		}
		if (this->right != NULL)
		{
			this->right->compute();
		}
		this->doOp();
		delete this->left;
		delete this->right;
		this->left = NULL;
		this->right = NULL;
	}
}