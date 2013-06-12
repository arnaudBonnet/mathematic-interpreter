#include <iostream>
#include "Operator.h"



Operator::Operator(void)
{
	isOperandBoolean = false;
	this->operandValue = 0.0;
	this->operatorChar = 0;
}

void Operator::dump()
{
	std::cout<<"Type : Operateur"<<std::endl;
	std::cout<<"Valeur : "<<this->getOperator()<<std::endl;
}

Operator::~Operator(void)
{
}
