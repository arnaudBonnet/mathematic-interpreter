#pragma once
#include "AbstractState.h"
#include "ExpressionValidationMachine.h"

class ReadOperandState :
	public AbstractState
{
public:
	ReadOperandState(void);
	virtual bool tryTransition(char c, ExpressionValidationMachine &ref);
	virtual bool isTerminalState();
	virtual void stop(ExpressionValidationMachine &e);
	virtual ~ReadOperandState(void);
};

