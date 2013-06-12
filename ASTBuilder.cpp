#include <cstdlib>
#include "ASTBuilder.h"


ASTBuilder::ASTBuilder(void)
{
}

void ASTBuilder::setQueue(std::queue<AbstractNode *> &queue)
{
	this->queue = queue;
}

void ASTBuilder::FirstRule(AbstractNode *&E, AbstractNode *&NC)
{
	while ((E->getData()->getPriority() <= NC->getData()->getPriority()) && NC->getParent() != NULL)
	{
		NC = NC->getParent();
	}
}

void ASTBuilder::SecondRule(AbstractNode *&E, AbstractNode *&NC)
{
	AbstractNode *save = NULL;

	if (NC->getParent() == NULL)
	{
		if (E->getData()->getPriority() <= NC->getData()->getPriority())
		{
			E->setLeft(NC);
		}
		else
		{
			save = NC->getRight();
			NC->setRight(E);
			E->setLeft(save);
		}
	}
	else
	{
		save = NC->getRight();
		NC->setRight(E);
		E->setLeft(save);
	}
	NC = E;
}

void ASTBuilder::rewindAST(AbstractNode *&NC)
{
	if (NC != NULL)
	{
		while (NC->getParent() != NULL)
		{
			NC = NC->getParent();
		}
	}
}

AbstractNode *ASTBuilder::buildAST()
{
	AbstractNode *E = NULL;
	AbstractNode *NC = NULL;

	while (this->queue.empty() == false)
	{
		E = this->queue.front();
		this->queue.pop();
		if (E->getData()->getOperator() == ')')
		{
			rewindAST(NC);
			return NC;
		}
		if (NC == NULL)
		{
			NC = E;
		}
		else
		{
			FirstRule(E, NC);
			SecondRule(E, NC);
		}
		if (NC->getData()->getOperator() == '(')
		{
			NC->setLeft(buildAST());
		}
	}
	rewindAST(NC);
	return NC;
}

ASTBuilder::~ASTBuilder(void)
{
}
