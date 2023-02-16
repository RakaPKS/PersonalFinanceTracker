#include "Calculator.h"
#include <numeric>

BaseMoney Calculator::calculate_total_income(std::vector<Income>& incomeList)
{
	return std::accumulate(incomeList.begin(), incomeList.end(), BaseMoney(0), [](BaseMoney acc, const Income& income)->BaseMoney {
		return acc + income.get_money();
	});
}

BaseMoney Calculator::calculate_total_expenses(std::vector<Expense>& expenseList)
{
	return std::accumulate(expenseList.begin(), expenseList.end(), BaseMoney(0),
		[](const BaseMoney& total, const Expense& expense) { return total - expense.get_money(); });
}

BaseMoney Calculator::calculate_balance(std::vector<Income>& incomeList, std::vector<Expense>& expenseList)
{
	return calculate_total_income(incomeList) - calculate_total_expenses(expenseList);
}