#pragma once

class ExpressionValidationMachine;

class AbstractState
{
public:
	AbstractState(void){};
	virtual ~AbstractState(void) {};
	virtual bool tryTransition(char c, ExpressionValidationMachine &ref) = 0;
	virtual bool isTerminalState() = 0;
	virtual void stop(ExpressionValidationMachine &e) = 0;
};

