#pragma once

#include "../Transactions/BaseMoney.h"
#include "../Transactions/Expense.h"
#include "../Transactions/Income.h"
#include <vector>

class Calculator
{
public:
	static BaseMoney calculate_total_income(std::vector<Income>& incomeList);

	static BaseMoney calculate_total_expenses(std::vector<Expense>& expenseList);

	static BaseMoney calculate_balance(std::vector<Income>& incomeList, std::vector<Expense>& expenseList);

};