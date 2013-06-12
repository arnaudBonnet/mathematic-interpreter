#pragma once
#include <map>
#include <string>
#include <queue>
#include <stack>
#include "AbstractNode.h"
#include "NodeFactory.h"
#include "StateName.h"
#include "AbstractState.h"



class ExpressionValidationMachine
{
protected:
	AbstractState *currentState;
	std::map<enum StateName, AbstractState *> states;
	std::stack<char> bracketStack;
	std::string fileToken;
	std::queue<AbstractNode *> fileNode;
	NodeFactory nf;
public:
	ExpressionValidationMachine(void);
	~ExpressionValidationMachine(void);
	bool checkSynthax(std::string &s);
	bool setState(enum StateName);
	void pushOpenBracket();
	void pushCloseBracket();
	bool generateAndPushNode(enum NodeType);
	std::queue<AbstractNode *> getNodeQueue();
	void pushTokenCharacter(char c);
	void dumpNodes();
	const std::string &getTokenFile();
	void clear();
};

