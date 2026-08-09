//Change GetDifferenceInDays function for support minus Date
#include <iostream> 
#include <cstdio>

using namespace std;

struct sDate
{
	int Day; int Month; int Year;
};

short ReadYear()
{
	int Number = 0;
	cout << "Pls enter a year to check? ";
	cin >> Number;
	return Number;
}

short ReadMonth()
{
	int Number = 0;
	cout << "pls enter a monthe to check? ";
	cin >> Number;
	return Number;
}

short ReadDay()
{
	int Number = 0;
	cout << "pls enter a day to check? ";
	cin >> Number;
	return Number;
}

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
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

bool isLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool isLastMonthInYear(sDate Date)
{
	return Date.Month == 12;
}

bool isDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
}

sDate AddOneDay(sDate Date)
{

	if (isLastDayInMonth(Date) && !isLastMonthInYear(Date))
	{
		Date.Day = 1;
		Date.Month += 1;
	}
	else if (isLastDayInMonth(Date) && isLastMonthInYear(Date))
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year += 1;
	}
	else
	{
		Date.Day += 1;
	}

	return Date;
}

bool isDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

void SwapDates(sDate& Date1, sDate& Date2)
{
	sDate Temp = Date1;
	Date1 = Date2;
	Date2 = Temp;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool WithIncludeEndDay = false)
{
	int Days = 0;
	short SwapFlag = 1;


	if (!isDate1BeforeDate2(Date1,Date2) && !isDate1EqualDate2(Date1,Date2))
	{
		SwapFlag = -1;

		SwapDates(Date1, Date2);
	}

	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days += 1;
		Date1 = AddOneDay(Date1);
	}

	return (WithIncludeEndDay?++Days : Days) * SwapFlag;
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << endl;

	sDate Date2 = ReadFullDate();
	cout << endl;

	cout << "Difference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s)" << endl;
	cout << "Difference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)";

	return 0;
}