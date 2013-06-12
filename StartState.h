#pragma once
#include "AbstractState.h"
#include "ExpressionValidationMachine.h"

class StartState :
	public AbstractState
{
public:
	StartState(void);
	virtual bool tryTransition(char c, ExpressionValidationMachine &ref);
	virtual bool isTerminalState();
	virtual void stop(ExpressionValidationMachine &e);
	virtual ~StartState(void);
};

