#include "JSONParser.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

std::string JSONParser::transactions_to_json(const std::vector<Transaction>& transactions_list)
{
	rapidjson::Document doc(rapidjson::kObjectType);
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

	rapidjson::Value transactionsArray(rapidjson::kArrayType);
	for (const Transaction& transaction : transactions_list)
	{
		rapidjson::Value transactionObject(rapidjson::kObjectType);
		transactionObject.AddMember("description", transaction.get_description(), allocator);
		transactionObject.AddMember("amount", std::to_string(transaction.get_money().get_base_money()), allocator);
		transactionsArray.PushBack(transactionObject, allocator);
	}
	doc.AddMember("transactions", transactionsArray, allocator);

	rapidjson::StringBuffer  buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	return buffer.GetString();
}

void JSONParser::json_to_transactions(std::string& json_string, std::vector<Transaction>& transactions_list,
	std::vector<Expense>& expense_list, std::vector<Income>& income_list)
{
	rapidjson::Document doc;
	doc.Parse(json_string.c_str());

	const auto& transactionsArray = doc["transactions"].GetArray();
	for (const auto& transactionsObject : transactionsArray)
	{
		const std::string description = transactionsObject["description"].GetString();
		const BaseMoney amount{std::stoi(transactionsObject["amount"].GetString())};
		if (amount > 0) {
			income_list.push_back(Income{ description, BaseMoney{amount} });
			transactions_list.push_back(income_list.back());
		}
		else
		{
			expense_list.push_back(Expense{ description, BaseMoney{amount} });
			transactions_list.push_back(expense_list.back());
		}
	}

}