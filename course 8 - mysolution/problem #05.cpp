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

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (int i = 0; i < 7; i++)
	{
		if (arr31Days[i] == Month)
		{
			return 31;
		}
	}


	return 30;
}

int NumberOfHoursInAMonth(int Year , int Month)
{
	return NumberOfDaysInAMonth(Year,Month) * 24;
}

int NumberOfMinutesInAMonth(int Year,int Month)
{
	return NumberOfHoursInAMonth(Year,Month) * 60;
}

int NumberOfSecondsInAMonth(int Year,int Month)
{
	return NumberOfMinutesInAMonth(Year,Month) * 60;
}

int main()
{
	int Year = ReadYear("Pls enter a year to check? ");
	cout << endl;

	int Month = ReadNumber("pls enter a monthe to check? ");

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year,Month);
	cout << "\nNumber of Hours in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year,Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year,Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year,Month);

	return 0;
}