#pragma once

#include "transaction.h"

class Expense : public Transaction {
public:
	Expense(std::string description, BaseMoney amount);

};

