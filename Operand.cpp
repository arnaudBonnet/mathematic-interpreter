#include <cstdlib>
#include <iostream>
#include "Operand.h"

Operand::Operand(void)
{
	this->operatorChar = 0;
	this->operandValue = 0.0;
	this->isOperandBoolean = true;
}

void Operand::dump()
{
	std::cout<<"Type : Operande"<<std::endl;
	std::cout<<"Valeur : "<<this->operandValue<<std::endl;
}

Operand::~Operand(void)
{
}
