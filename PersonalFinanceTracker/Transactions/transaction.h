#pragma once

#include<string>
#include "BaseMoney.h"

class Transaction
{
public:
	Transaction(std::string description, const BaseMoney amount);
	[[nodiscard]] std::string get_description() const;
	[[nodiscard]] BaseMoney get_money() const;

	friend std::ostream& operator<<(std::ostream& os, const Transaction& transaction);

private:
	std::string description_;
	BaseMoney amount_;
};

