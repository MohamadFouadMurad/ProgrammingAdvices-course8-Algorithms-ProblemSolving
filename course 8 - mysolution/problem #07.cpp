#include <iostream> 

using namespace std;

short ReadNumber(string message)
{
	int Number = 0;
	cout << message;
	cin >> Number;
	return Number;
}

short ReadYear(string message)
{
	int Year = 0;
	cout << message;
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month,short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short Day)
{
	string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arr[Day];
}

int main()
{
	short Year = ReadYear("Pls enter a year to check? ");

	cout << endl;

	short Month = ReadNumber("pls enter a monthe to check? ");

	cout << endl;

	short Day = ReadNumber("pls enter a day to check? ");

	cout << endl;

	cout << "\nDate     :" << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order  :" << DayOfWeekOrder(Day, Month, Year) << endl;
	cout << "Day Name   :" << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;

	return 0;
}