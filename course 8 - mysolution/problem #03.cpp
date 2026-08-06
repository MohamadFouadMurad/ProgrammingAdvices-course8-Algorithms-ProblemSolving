#include <iostream> 

using namespace std;

int ReadYear(string message)
{
	int Year = 0;
	cout << message;
	cin >> Year;
	return Year;
}

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
	short Year = ReadYear("Pls enter a year to check? ");
	cout << endl;

	if (IsLeapYear(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else
	{
		cout << "\nNO, Year [" << Year << "] is NOT a leap year.\n";
	}

	return 0;
}