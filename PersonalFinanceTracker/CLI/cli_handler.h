#pragma once
#include <vector>

#include "../Transactions/transaction.h"
#include "../Transactions/Expense.h"
#include "../Transactions/Income.h"

class cli_handler
{
public:

	static bool run_cli();

private:
	static void cli_add_();

	static void cli_remove_();

	static void cli_view_();

	static void cli_loadsave_();

	static void cli_save_();

	static void save_file_(std::string filename);

	static void cli_load_();

	static std::vector<Transaction> transaction_list_;
	static std::vector<Income> income_list_;
	static std::vector<Expense> expense_list_;

};
