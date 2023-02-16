#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "../Transactions/transaction.h"
#include "../Transactions/Expense.h"
#include "../Transactions/Income.h"

class FileManager
{
public:

	static bool saveFile(const std::string& filename, std::vector<Transaction>& transactions_list, std::vector<Expense>& expense_list, std::vector<Income>& income_list);
	static bool loadFile(const std::string& filename, std::vector<Transaction>& transactions_list, std::vector<Expense>& expense_list, std::vector<Income>& income_list);
	static bool fileExists(const std::string& filename);
	static std::vector<std::string> listFiles();

private:
	static std::filesystem::path folder_path_;
	static std::string extension_;

};
