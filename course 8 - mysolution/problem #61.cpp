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

bool isDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1equalDate2(sDate Date1, sDate Date2)
{
	return (Date1.Day == Date2.Day) && (Date1.Month == Date2.Month) && (Date1.Year == Date2.Year);
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!isDate1BeforeDate2(Date1, Date2)) && (!IsDate1equalDate2(Date1, Date2));
}

enum enCompareDate
{
	before = -1, equal = 0, After = 1,
};

enCompareDate CompareDates(sDate Date1, sDate Date2)
{
	if (isDate1BeforeDate2(Date1, Date2))
	{
		return enCompareDate::before;
	}
	else if (IsDate1equalDate2(Date1, Date2))
	{
		return enCompareDate::equal;
	}
	else
	{
		return enCompareDate::After;
	}
}

bool IsOverLap(stPeriods Periods1, stPeriods Periods2)
{
	if (CompareDates(Periods2.EndDate, Periods1.StartDate) == enCompareDate::before || CompareDates(Periods1.EndDate, Periods2.StartDate) == enCompareDate::before)
	{
		return false;
	}

	return true;
}

bool IsDateWithinPeriod(stPeriods Period1, sDate Date1)
{
	if ((CompareDates(Date1, Period1.StartDate) == enCompareDate::before) ||
		(CompareDates(Date1, Period1.EndDate) == enCompareDate::After))
	{
		return false;
	}

	return true;

	//Another way
	/*
	stPeriods Period2;
	Period2.StartDate = Date1;
	Period2.EndDate = Date1;

	return IsOverLap(Period1, Period2);
	*/
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

short CountOverlapDays(stPeriods Period1, stPeriods Period2)
{
	int OverLapDays = 0;

	if (!IsOverLap(Period1,Period2))
	{
		return 0;
	}

	sDate StartDate, EndDate;

	if (IsDate1AfterDate2(Period1.StartDate, Period2.StartDate))
	{
		StartDate = Period1.StartDate;
	}
	else
	{
		StartDate = Period2.StartDate;
	}

	if (isDate1BeforeDate2(Period1.EndDate, Period2.EndDate))
	{
		EndDate = Period1.EndDate;
	}
	else
	{
		EndDate = Period2.EndDate;
	}

	OverLapDays = GetDifferenceInDays(StartDate,EndDate,true);

	return OverLapDays;

	//Another way
	/*
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverLapDays = 0;

	if (Period1Length < Period2Length)
	{
		while (isDate1BeforeDate2(Period1.StartDate , Period1.EndDate))
		{
			if (IsDateWithinPeriod(Period2,Period1.StartDate))
			{
				OverLapDays++;
			}
			Period1.StartDate = AddOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (isDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateWithinPeriod(Period1,Period2.StartDate))
			{
				OverLapDays++;
			}
			Period2.StartDate = AddOneDay(Period2.StartDate);
		}
	}
	return OverLapDays;
	*/
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriods Period1 = ReadPeriod();
	cout << endl;

	cout << "\nEnter Period2:\n";
	stPeriods Period2 = ReadPeriod();

	cout << "\nOverlap Days Count is: " << CountOverlapDays(Period1,Period2) << endl;

	return 0;
}