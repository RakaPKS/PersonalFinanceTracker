#include "transaction.h"

#include <iostream>

Transaction::Transaction(std::string description, const BaseMoney amount) : description_(std::move(description)), amount_(amount) {}

std::string Transaction::get_description() const {
    return description_;
}

BaseMoney Transaction::get_money() const
{
    return amount_;
}


std::ostream& operator<<(std::ostream& os, const Transaction& transaction)
{
	{
		os << transaction.get_description()<< "	 :	" << transaction.get_money();
		return os;
	}
}
