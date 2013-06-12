#pragma once
#include "AbstractState.h"

class ReadOperatorState :
	public AbstractState
{
public:
	ReadOperatorState(void);
	virtual bool tryTransition(char c, ExpressionValidationMachine& e);
	virtual bool isTerminalState();
	virtual void stop(ExpressionValidationMachine &e);
	virtual ~ReadOperatorState(void);
};

