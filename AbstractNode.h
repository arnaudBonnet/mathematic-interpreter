#pragma once

#include "Data.h"

class AbstractNode
{
protected:
	AbstractNode *parent;
	AbstractNode *left;
	AbstractNode *right;
	Data *data;
private:
	void doOp();
public:
	AbstractNode(void);
	~AbstractNode(void);
	void setLeft(AbstractNode *node);
	void setRight(AbstractNode *node);
	void setParent(AbstractNode *node);
	AbstractNode *getParent();
	AbstractNode *getLeft();
	AbstractNode *getRight();
	Data *getData();
	void setData(Data *data);
	void dump();
	void displayTree();
	void compute();
};

