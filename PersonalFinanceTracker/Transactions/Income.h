#pragma once

#include "transaction.h"

class Income : public Transaction {
public:
	Income(std::string description, BaseMoney amount);
};