#include <iostream>

using namespace std;

struct sDate
{
	int Day; int Month; int Year;
};

struct stPeriods
{
	sDate StartDate;
	sDate EndDate;
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

stPeriods ReadPeriod()
{
	stPeriods Period;

	cout << "Enter StartDate:\n";
	cout << endl;
	Period.StartDate = ReadFullDate();

	cout << "\nEnter EndDate:\n";
	cout << endl;
	Period.EndDate = ReadFullDate();

	return Period;
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

	//Another way but it it's worse
	/*
	if (Date2.Year > Date1.Year)
	{
		return true;
	}
	else if (Date1.Year > Date2.Year)
	{
		return false;
	}
	else
	{
		if (Date2.Month > Date1.Month)
		{
			return true;
		}
		else if (Date1.Month > Date2.Month)
		{
			return false;
		}
		else
		{
			if (Date2.Day > Date1.Day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	*/

	//Also Another way and it's easy to understand
	/*
	bool isDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		if (Date1.Year != Date2.Year)
			 return Date1.Year < Date2.Year;

		if (Date1.Month != Date2.Month)
			return Date1.Month < Date2.Month;

		return Date1.Day < Date2.Day;
	}
	*/
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool WithIncludeEndDay = false)
{
	int Days = 0;

	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days += 1;
		Date1 = AddOneDay(Date1);
	}

	if (WithIncludeEndDay)
	{
		Days += 1;
	}

	return Days;
}

int PeriodLengthInDays(stPeriods Period, bool IncludingEndDat = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludingEndDat);
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriods Period1 = ReadPeriod();
	cout << endl;

	cout << "Period length is: " << PeriodLengthInDays(Period1) <<  endl;
	cout << "Periond length (including end date) is: " << PeriodLengthInDays(Period1,true)<<endl;

	return 0;
}