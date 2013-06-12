#pragma once
#include "Data.h"

class Operand : public Data
{
public:
	Operand(void);
	virtual ~Operand(void);
	virtual void dump();
};

