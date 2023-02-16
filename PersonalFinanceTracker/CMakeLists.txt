# CMakeList.txt : CMake project for PersonalFinanceTracker, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PersonalFinanceTracker "PersonalFinanceTracker.cpp" "PersonalFinanceTracker.h" "CLI/cli_static_data.cpp" "CLI/cli_handler.h" "CLI/cli_handler.cpp" "Transactions/transaction.h" "Transactions/BaseMoney.h"  "Transactions/transaction.cpp" "Transactions/BaseMoney.cpp" "Transactions/Expense.h" "Transactions/Expense.cpp" "Transactions/Income.h" "Transactions/Income.cpp" "Calculator/Calculator.h" "Calculator/Calculator.cpp" "Storage/FileManager.h" "Storage/FileManager.cpp" "Storage/JSONParser.h" "Storage/JSONParser.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PersonalFinanceTracker PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
