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

sDate  AddXDayToDate(sDate Date, int xDay)
{
	for (int i = 1; i <= xDay; i++)
	{
		Date = AddOneDay(Date);
	}

	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	return AddXDayToDate(Date, 7);
}

sDate IncreaseDateByXWeeks(sDate Date, int Weeks)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month != 12)
	{
		++Date.Month;
	}
	else
	{
		Date.Month = 1;
		++Date.Year;
	}

	int DaysInAMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInAMonth)
	{
		Date.Day = DaysInAMonth;
	}

	return Date;
}

sDate IncreaseDateByXMonths(sDate Date, int Months)
{

	short OriginalDay = Date.Day;

	for (int i = 0; i < Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	//عشان لو اول سنة كانت كبيسة واليوم 29 واخر سنة كانت كبيسة نرجع يوم 29
	Date.Day = (OriginalDay <= NumberOfDaysInCurrentMonth) ? OriginalDay : NumberOfDaysInCurrentMonth;

	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	++Date.Year;

	int DaysInAMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInAMonth)
	{
		Date.Day = DaysInAMonth;
	}

	return Date;

	//Another way 
	/*
	return IncreaseDateByXMonths(Date, 12);
	*/

}

sDate IncreaseDateByXYear(sDate Date, int Years)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;

	//Another way (Faster way)
	/*
	Date.Year += Years;

	int DaysInAMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInAMonth)
	{
		Date.Day = DaysInAMonth;
	}
	return Date;
	*/
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	return IncreaseDateByXYear(Date, 10);
}

sDate IncreaseDateByXDecade(sDate Date, int Decades)
{
	for (int i = 1; i <= Decades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;

	//Another way (Faster way)
	/*
	Date.Year += (Decades * 10);

	int DaysInAMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInAMonth)
	{
		Date.Day = DaysInAMonth;
	}
	return Date;
	*/
}

int main()
{
	sDate Date = ReadFullDate();
	cout << "\nDate After:\n\n";

	Date = AddOneDay(Date);
	cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = AddXDayToDate(Date, 10);
	cout << "02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXMonths(Date, 5);
	cout << "06-Adding 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneYear(Date);
	cout << "07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYear(Date, 10);
	cout << "08-Adding 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYear(Date, 10); // Faster
	cout << "09-Adding 10 years (Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding one decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecade(Date, 10);
	cout << "11-Adding 10 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecade(Date, 10); // Faster
	cout << "12-Adding 10 decades (Faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}