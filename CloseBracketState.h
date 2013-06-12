#pragma once
#include "AbstractState.h"

class CloseBracketState :
	public AbstractState
{
public:
	CloseBracketState(void);
	virtual bool tryTransition(char c, ExpressionValidationMachine& e);
	virtual bool isTerminalState();
	virtual ~CloseBracketState(void);
	void stop(ExpressionValidationMachine &e);
};

