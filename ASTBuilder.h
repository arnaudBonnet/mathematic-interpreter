#pragma once
#include <queue>
#include "AbstractNode.h"


class ASTBuilder
{
protected:
	std::queue<AbstractNode *> queue;
private:
	void SecondRule(AbstractNode *&E, AbstractNode *&NC);
	void FirstRule(AbstractNode *&E, AbstractNode *&NC);
	void rewindAST(AbstractNode *&NC);
public:
	ASTBuilder(void);
	void setQueue(std::queue<AbstractNode *> &queue);
	AbstractNode *buildAST();
	~ASTBuilder(void);
};

