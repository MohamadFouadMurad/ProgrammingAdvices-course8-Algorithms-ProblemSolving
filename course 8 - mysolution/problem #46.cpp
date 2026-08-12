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

sDate DecreaseDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

sDate DecreaseDateByXDay(sDate Date, int Day)
{
	for (int i = 1; i <= Day; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
	Date = DecreaseDateByXDay(Date, 7);
	return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, int Weeks)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInMonth)
	{
		Date.Day = DaysInMonth;
	}

	return Date;
}

sDate DecreaseDateByXMonths(sDate Date, int Months)
{
	short OringinalDay = Date.Day;

	for (int i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	short DaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
	Date.Day = (OringinalDay <= DaysInCurrentMonth) ? OringinalDay : DaysInCurrentMonth;

	return Date;
}

sDate DecreaseDateByOneYear(sDate Date) 
{
	Date.Year--;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInMonth)
	{
	Date.Day = DaysInMonth;
	}

	return Date;
}

sDate  DecreaseDateByXYear(sDate Date, int Years)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;


	//Another way (Faster way)
	/*
	Date.Year -= Years;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInMonth)
	{
		Date.Day = DaysInMonth;
	}

	return Date;
	*/
}

sDate  DecreaseDateByOneDecade(sDate Date)
{
	Date = DecreaseDateByXYear(Date, 10);
	return Date;
}

sDate DecreaseDateByXDecade(sDate Date, int Decade)
{
	for (int i = 1; i <= Decade; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;


	//Another way (Faster way)
	/*
	Date.Year -= (Decade *10);

	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInMonth)
	{
		Date.Day = DaysInMonth;
	}
	*/
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	Date = DecreaseDateByXDecade(Date, 10);
	return Date;
}

sDate  DecreaseDateByOneMillennium(sDate Date)
{
	Date = DecreaseDateByXDecade(Date, 100);
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();
	cout << endl;


	Date = DecreaseDateByOneDay(Date);
	cout << "01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDay(Date, 10);
	cout << "02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXWeeks(Date, 10);
	cout << "04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXMonths(Date, 5);
	cout << "06-Subtracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneYear(Date);
	cout << "07-Subtracting one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYear(Date, 10);
	cout << "08-Subtracting 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneDecade(Date);
	cout << "09-Subtracting one decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecade(Date, 10);
	cout << "10-Subtracting 10 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneCentury(Date);
	cout << "11-Subtracting one century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMillennium(Date);
	cout << "12-Subtracting One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");

	return 0;
}