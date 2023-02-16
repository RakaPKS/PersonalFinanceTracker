#include "FileManager.h"
#include <fstream>
#include "JSONParser.h"

std::filesystem::path FileManager::folder_path_ = "../../../../.saved_data";
std::string FileManager::extension_ = ".json";

bool FileManager::saveFile(const std::string& filename, std::vector<Transaction>& transactions_list, std::vector<Expense>& expense_list, std::vector<Income>& income_list)
{
	const std::string json_string = JSONParser::transactions_to_json(transactions_list);
	std::ofstream file(folder_path_ / (filename + extension_));
	if (!file) return false;
	file << json_string;
	file.close();
	return true;
}

bool FileManager::loadFile(const std::string& filename, std::vector<Transaction>& transactions_list, std::vector<Expense>& expense_list, std::vector<Income>& income_list)
{
	transactions_list.clear();
	expense_list.clear();
	income_list.clear();

	std::string json_string;
	std::ifstream file(folder_path_ / (filename + extension_));
	if (file.is_open()) {
		std::stringstream buffer;
		buffer << file.rdbuf();
		json_string = buffer.str();
	}
	file.close();
	
	JSONParser::json_to_transactions(json_string, transactions_list, expense_list, income_list);
	return true;
}

bool FileManager::fileExists(const std::string& filename)
{
	return exists(folder_path_ / (filename + extension_));
}

std::vector<std::string> FileManager::listFiles()
{

	std::vector<std::string> file_list;

	for (const auto& entry : std::filesystem::directory_iterator(folder_path_)) {
		if (entry.is_regular_file() && entry.path().extension() == extension_) {
			file_list.push_back(entry.path().stem().string());
		}
	}
	return file_list;
}

