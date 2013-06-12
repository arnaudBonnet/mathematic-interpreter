#pragma once
#include <string>

class Data
{
protected:
	std::string operand;
	char operatorChar;
	double operandValue;
	bool isOperandBoolean;
	unsigned int priority;
public:
	Data(void);
	virtual ~Data(void);
	bool isOperand();
	bool isOperator();
	std::string getOperand();
	char getOperator();
	double getOperandValue();
	void setOperandValue(double value);
	void setOperand(std::string str);
	void setOperator(char c);
	unsigned int getPriority();
	void setPriority(unsigned int priority);
	virtual void dump() = 0;
};

