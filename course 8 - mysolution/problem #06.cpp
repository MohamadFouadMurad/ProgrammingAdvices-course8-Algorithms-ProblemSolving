#include <iostream> 
#include "MyFunctions.h"

using namespace std;
using namespace myfunc;

short ReadYear(string message)
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

int NumberOfDaysInAMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ((Month == 3) || (Month == 5) || (Month == 7) || (Month == 8) || (Month == 10) || (Month == 12)) ? 31 : 30;

	//Another way
	/*
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :NumberOfDays[Month - 1];
	*/

}

int main()
{
	int Year = ReadYear("Pls enter a year to check? ");

	cout << endl;

	int Month = ReadNumber("pls enter a monthe to check? ");

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);

	return 0;
}