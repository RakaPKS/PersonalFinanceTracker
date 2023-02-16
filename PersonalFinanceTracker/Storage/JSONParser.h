#pragma once

#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson/document.h"

#include <string>
#include <vector>
#include "../Transactions/transaction.h"
#include "../Transactions/Expense.h"
#include "../Transactions/Income.h"


class JSONParser
{
public:
	static std::string transactions_to_json(const std::vector<Transaction>& transactions_list);
	static void json_to_transactions(std::string& json_string, std::vector<Transaction>& transactions_list, std::vector<Expense>& expense_list, std::vector<Income>& income_list);
};
