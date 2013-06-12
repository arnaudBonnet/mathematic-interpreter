#include "Data.h"


Data::Data(void)
{
}

Data::~Data(void)
{
}

bool Data::isOperand()
{
	return this->isOperandBoolean;
}

bool Data::isOperator()
{
	return !this->isOperandBoolean;
}

std::string Data::getOperand()
{
	return this->operand;
}

char Data::getOperator()
{
	return this->operatorChar;
}

double Data::getOperandValue()
{
	return this->operandValue;
}

void Data::setOperandValue(double value)
{
	this->operandValue = value;
}

void Data::setOperand(std::string str)
{
	this->operand = str;
}

unsigned int Data::getPriority()
{
	return this->priority;
}

void Data::setPriority(unsigned int priority)
{
	this->priority = priority;
}

void Data::setOperator(char c)
{
	this->operatorChar = c;
}
