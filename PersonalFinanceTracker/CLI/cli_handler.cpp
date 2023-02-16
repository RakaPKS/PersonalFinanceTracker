#include "cli_handler.h"
#include "cli_static_data.h"
#include "../Transactions/transaction.h"
#include "../Transactions/Expense.h"
#include "../Transactions/Income.h"
#include "../Calculator/Calculator.h"
#include "../Storage/FileManager.h"
#include <iostream>

using namespace std;

std::vector<Transaction> cli_handler::transaction_list_;
std::vector<Income> cli_handler::income_list_;
std::vector<Expense> cli_handler::expense_list_;


bool cli_handler::run_cli()
{
	cout << cli_static_data::current_balance << Calculator::calculate_balance(income_list_, expense_list_)<< endl;
	cout << cli_static_data::current_income << Calculator::calculate_total_income(income_list_)<< endl;
	cout << cli_static_data::current_expense << Calculator::calculate_total_expenses(expense_list_) << endl;

	cout << cli_static_data::main_message << endl;
	int num;
	if (!(cin >> num))
	{
		cout << cli_static_data::user_error_main << endl;
		return true;
	}

	switch (num)
	{
	case 1:
		cli_add_();
		break;
	case 2:
		cli_remove_();
		break;
	case 3:
		cli_view_();
		break;
	case 4:
		cli_loadsave_();
		break;
	case 5: return false;
	default:
		cout << cli_static_data::user_error_main << endl;
	}
	return true;
}

void cli_handler::cli_add_()
{
	bool adding = true;
	while (adding) {
		cout << cli_static_data::income_or_expense << endl;
		int num;
		if (!(cin >> num) || num < 1 || num > 3)
		{
			cout << cli_static_data::user_error_income_or_expense << endl;
		}
		else {
			if (num == 3) return;
			std::string description;
			cout << cli_static_data::add_name << endl;
			cin >> description;

			cout << cli_static_data::add_val << endl;
			double amount;
			while (!(cin >> amount))
			{
				cout << cli_static_data::user_error_add_val << endl;
				cout << cli_static_data::add_val << endl;
			}

			if (num == 1)
			{
				income_list_.push_back(Income{ description, BaseMoney{static_cast<int>(amount * 100)} });
				transaction_list_.push_back(income_list_.back());
			}
			else
			{
				expense_list_.push_back(Expense{ description, BaseMoney{static_cast<int>(amount * -100)} });
				transaction_list_.push_back(expense_list_.back());
			}
		}
		std::string cont;
		cout << cli_static_data::keep_adding << endl;
		cin >> cont;
		if (!(cont == "1" || cont == "yes"))
			adding = false;
	}

}


void cli_handler::cli_remove_()
{
	cout << cli_static_data::nyi << endl;
};

void cli_handler::cli_view_()
{
	int prompt;
	cout << cli_static_data::view_transactions << endl;
	if (!(cin >> prompt) || prompt < 1 || prompt > 3)
	{
		cout << cli_static_data::user_error_main << endl;
		return;
	}
	switch(prompt)
	{
	case 1:
		cout << cli_static_data::current_transactions << endl;
		for (const Transaction& transaction : transaction_list_)
		{
			cout << transaction << endl;
		}
		break;
	case 2:
		cout << cli_static_data::current_transactions << endl;
		for (const Income& income : income_list_)
		{
			cout << income << endl;
		}
		break;
	case 3:
		cout << cli_static_data::current_transactions << endl;
		for (const Expense& expense : expense_list_)
		{
			cout << expense << endl;
		}
		break;
	default: return;
	}
};

void cli_handler::cli_loadsave_()
{
	int prompt;
	cout << cli_static_data::save_or_load_prompt << endl;
	if (!(cin >> prompt) || prompt < 1 || prompt > 3)
	{
		cout << cli_static_data::user_error_income_or_expense << endl;
		return;
	}

	switch (prompt)
	{
	case 1:
		cli_save_();
		break;
	
	case 2:
		cli_load_();
		break;
	default: return;
	}

}

void cli_handler::cli_save_() {
	bool save_success = false;
	while (!save_success) {
		string filename;
		cout << cli_static_data::save_prompt << endl;
		cin >> filename;
		if (filename == "exit") return;
		if (FileManager::fileExists(filename))
		{
			int overwrite;
			cout << cli_static_data::save_override << endl;
			cin >> overwrite;
			if (overwrite != 1)
				continue;
		}
		if (FileManager::saveFile(filename, transaction_list_, expense_list_, income_list_))
			cout << cli_static_data::save_success << endl;
		else
			cout << cli_static_data::save_fail << endl;
		save_success = true;
	}
}

void cli_handler::cli_load_()
{
	vector<string> file_list = FileManager::listFiles();
	cout << cli_static_data::load_list << endl;
	for (const string& list_name : file_list)
		cout << "\t" << list_name << endl;
	string filename;

	bool load_success = false;
	while (!load_success) {
		cout << cli_static_data::load_prompt << endl;
		cin >> filename;
		if (filename == "exit") return;
		if (ranges::find(file_list, filename) == file_list.end())
			cout << cli_static_data::load_err_not_found << filename << endl;
		else
		{
			if (FileManager::loadFile(filename, transaction_list_, expense_list_, income_list_)) {
				cout << cli_static_data::load_success << endl;
				load_success = true;
			}
			else
				cout << cli_static_data::load_fail << endl;
		}
	}
}
