#include <iostream> 
#include <cstdio>

using namespace std;

struct sDate 
{ int Day; int Month; int Year; };

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

int NumberOfDaysInAMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

int NumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
{
	short TotalDays = 0;

	for (int i = 1; i < month; i++)
	{
		TotalDays += NumberOfDaysInAMonth(year, i);
	}

	TotalDays += day;

	return TotalDays;
}

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	int RemainsDays = DateOrderInYear;

	Date.Year = Year;

	for (int Month = 1; Month <= 12; Month++)
	{
		int MonthDays = NumberOfDaysInAMonth(Year,Month);

		if (RemainsDays > MonthDays)
		{
			RemainsDays -= MonthDays;
		}
		else
		{
			Date.Month = Month;
			break;
		}
	}

	Date.Day = RemainsDays;


	return Date;
}


int main()
{
	short Year = ReadYear("Pls enter a year to check? ");

	cout << endl;

	short Month = ReadNumber("pls enter a monthe to check? ");

	cout << endl;

	short Day = ReadNumber("pls enter a day to check? ");

	cout << endl;

	short DayOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);
	cout << "Number of days from the begining of the year is " << DayOrderInYear;

	sDate Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);

	cout << "\n\nDate for [" << DayOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	return 0;

}