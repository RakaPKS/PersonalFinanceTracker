#pragma once
#include <string>

class cli_static_data
{
public:
	static std::string welcome;
	static std::string current_balance;
	static std::string current_income;
	static std::string current_expense;

	static std::string main_message;
	static std::string nyi;
	static std::string user_error_main;

	static std::string income_or_expense;
	static std::string user_error_income_or_expense;
	static std::string add_name;
	static std::string add_val;
	static std::string user_error_add_val;
	static std::string add_success;
	static std::string add_success_expense;
	static std::string add_success_income;
	static std::string keep_adding;

	static std::string view_transactions;
	static std::string current_transactions;
	static std::string current_expenses;
	static std::string current_incomes;

	static std::string save_or_load_prompt;

	static std::string load_list;
	static std::string load_prompt;
	static std::string load_success;
	static std::string load_fail;
	static std::string load_err_not_found;

	static std::string save_prompt;
	static std::string save_override;
	static std::string save_success;
	static std::string save_fail;

	static std::string exit;
	static std::string overwrite_err;
	

};
