#pragma warning(disable : 4996)

#include <iostream> 
#include <ctime>

using namespace std;

struct sDate
{
	int Day; int Month; int Year;
};

sDate GetTodayDate()
{
	sDate Date;

	time_t t = time(0);
	tm* Now = localtime(&t);

	Date.Year = Now->tm_year + 1900;
	Date.Month = Now->tm_mon + 1;
	Date.Day = Now->tm_mday;

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

bool IsEndOfWeek(sDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(sDate Date)
{
	return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

bool IsEndOfWeek(sDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(sDate Date)
{
	return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

int DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
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


	if (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2))
	{
		SwapFlag = -1;

		SwapDates(Date1, Date2);
	}

	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days += 1;
		Date1 = AddOneDay(Date1);
	}

	return (WithIncludeEndDay ? ++Days : Days) * SwapFlag;
}

int DaysUntilTheEndOfMonth(sDate Date)
{
	return NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;

	//Another way
	/*
	sDate EndOfTheMonthDate;
	EndOfTheMonthDate.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
	EndOfTheMonthDate.Month = Date.Month;
	EndOfTheMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfTheMonthDate, true);
	*/
}

int  DaysUntilTheEndOfYear()
{

}

int main()
{
	sDate Date = GetTodayDate();

	string NumberOfDay = DayShortName(DayOfWeekOrder(Date));

	cout << "Today is " << NumberOfDay << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	cout << "\n\nIs it End of Week?" << endl;
	if (IsEndOfWeek(Date))
	{
		cout << "yes, it's end of week." << endl;
	}
	else
	{
		cout << "No, it's Not end of week" << endl;
	}

	cout << "\n\nIs it Weekend?" << endl;
	if (IsWeekEnd(Date))
	{
		cout << "yes, it's a Week End." << endl;
	}
	else
	{
		cout << "No, it's Not a Week End." << endl;
	}

	cout << "\n\nIs itBusiness Day?" << endl;
	if (IsBusinessDay(Date))
	{
		cout << "yes, it's a Business Day." << endl;
	}
	else
	{
		cout << "No, it's Not a Business Day." << endl;
	}

	cout << "\n\nDays until end of week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";

	cout << "\nDays until end of month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";

	//cout << "\nDays until end of year : " << DaysUntilTheEndOfYear(Date) << " Day(s).";

	return 0;
}