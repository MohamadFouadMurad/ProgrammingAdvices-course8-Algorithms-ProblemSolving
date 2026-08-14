#pragma warning(disable : 4996)

#include <iostream> 
#include <ctime>

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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
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

bool IsWeekEnd(sDate Date)
{
	return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

int ActualVacationDays(sDate DateFrom , sDate DateTo)
{
	short Dayscount = 0;

	while (isDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			Dayscount++;
		}

		DateFrom = AddOneDay(DateFrom);
	}

	return Dayscount;
}


int main()
{
	cout << "Vacation Strart: " << endl;
	sDate Date1 = ReadFullDate();

	cout << "\nVacation End: " << endl;
	sDate Date2 = ReadFullDate();

	cout << endl;

	string DateFrom = DayShortName(DayOfWeekOrder(Date1));

	cout << "Vacation From: " << DateFrom << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	string DateTo = DayShortName(DayOfWeekOrder(Date2));

	cout << "Vacation To: " << DateTo << " , " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year << endl;

	cout << "\n\nActual Vacation Days is : " << ActualVacationDays(Date1,Date2) << endl;
}