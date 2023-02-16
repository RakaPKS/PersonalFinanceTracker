#include "cli_static_data.h"


// Main menu loop
std::string cli_static_data::welcome = "Welcome!";

std::string cli_static_data::current_balance = "\nYour current balance is:	 ";
std::string cli_static_data::current_income = "Your current total income is:	 ";
std::string cli_static_data::current_expense = "Your current total expense is:	 ";

std::string cli_static_data::main_message = "\nWhat would you like to do? \n	1. Input Income/Expense \n	2. Remove Income/Expense \n	3. View Income/Expense \n	4. Save/Load data \n	5. Exit";
std::string cli_static_data::user_error_main = "Please enter a correct number between 1 and 5";



//Add Income/Expense
std::string cli_static_data::income_or_expense = "Do you want to enter a: \n	1. Income \n	2. Expense\n	3. Cancel";
std::string cli_static_data::user_error_income_or_expense = "Please enter a correct number between 1 and 3";

std::string cli_static_data::add_name = "Enter the description";
std::string cli_static_data::add_val = "Enter the amount";
std::string cli_static_data::user_error_add_val = "Please enter a numerical value";
std::string cli_static_data::add_success = "Successfully added transaction";
std::string cli_static_data::add_success_expense = "Successfully added expense";
std::string cli_static_data::add_success_income = "Successfully added income";
std::string cli_static_data::keep_adding = "Do you want to keep adding incomes/expenses:\n	1. Yes \n	2. No";

// View Transactions
std::string cli_static_data::view_transactions = "Do you want to:\n	1. View all transactions\n	2. View all Incomes\n	3. View all expenses\n	4. Cancel";
std::string cli_static_data::current_transactions = "Current transactions:\n";
std::string cli_static_data::current_expenses ="Current incomes:\n";
std::string cli_static_data::current_incomes = "Current expenses:\n";

// Save/Load Data

std::string cli_static_data::save_or_load_prompt = "Do you want to: \n	1. Save data \n	2. Load data \n	3. Exit";
std::string cli_static_data::load_list = "The following data has been found:";
std::string cli_static_data::load_prompt = "Please enter the name of the file you want to load (type exit to cancel):";
std::string cli_static_data::load_success = "Successfully loading file!";
std::string cli_static_data::load_fail = "Failed loading file!";

std::string cli_static_data::save_prompt = "Please a name for the save (type exit to cancel):";
std::string cli_static_data::save_success = "Successfully saved file!";
std::string cli_static_data::save_fail = "Failed saving file!";
std::string cli_static_data::save_override = "File already exists. Do you want to overwrite: \n	1. Yes\n	2. No";
std::string cli_static_data::load_err_not_found = "There is no file with name: ";
std::string cli_static_data::overwrite_err = "Please enter a correct number between 1 and 2";
//DEBUG
std::string cli_static_data::exit = "exit";
std::string cli_static_data::nyi = "Not yet Implemented";