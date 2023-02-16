// Simple Personal Finance Tracker that allows for entering income and expenses
//

#include "PersonalFinanceTracker.h"

#include "CLI/cli_handler.h"
#include "CLI/cli_static_data.h"

using namespace std;

int main()
{
	cout << cli_static_data::welcome << endl;
	bool run = true;
	while(run)
	{
		run = cli_handler::run_cli();
	}
	return 0;
}
