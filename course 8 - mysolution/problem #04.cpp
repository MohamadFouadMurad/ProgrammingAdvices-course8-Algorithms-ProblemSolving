#include <iostream> 

using namespace std;

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

int NumberOfDaysInAMonth(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHoursInAMonth(short Year)
{
	return NumberOfDaysInAMonth(Year) * 24;
}

int NumberOfMinutesInAMonth(short Year)
{
	return NumberOfHoursInAMonth(Year) * 60;
}

int NumberOfSecondsInAMonth(short Year)
{
	return NumberOfMinutesInAMonth(Year) * 60;
}

int main()
{
	int Year = ReadYear("Pls enter a year to check? ");
	cout << endl;

	cout << "\nNumber of Days in Year [" << Year << "] is " << NumberOfDaysInAMonth(Year);
	cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHoursInAMonth(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAMonth(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAMonth(Year);

}