#pragma once
#include "AbstractState.h"

class OpenBracketState :
	public AbstractState
{
public:
	OpenBracketState(void);
	virtual bool tryTransition(char c, ExpressionValidationMachine &e);
	virtual bool OpenBracketState::isTerminalState();
	virtual void stop(ExpressionValidationMachine &e);
	virtual ~OpenBracketState(void);
};

