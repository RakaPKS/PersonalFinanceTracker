#include "Expense.h"

#include <utility>

Expense::Expense(std::string description, BaseMoney amount) : Transaction(std::move(description), amount) {}

