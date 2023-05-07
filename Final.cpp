#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "FinalHeader.h"

using namespace std;

void Expense::expenseDetails()
{
    cout << endl << "You have made a payment of " << setprecision(2) << fixed << payment << " for " << type;
}