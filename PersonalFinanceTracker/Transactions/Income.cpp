#include "Income.h"
#include <utility>

Income::Income(std::string description, BaseMoney amount) : Transaction(std::move(description), amount) {}

