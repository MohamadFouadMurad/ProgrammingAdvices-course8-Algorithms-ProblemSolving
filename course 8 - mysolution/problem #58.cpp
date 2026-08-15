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
	if (CompareDates(Periods2.EndDate,Periods1.StartDate) == enCompareDate::before || CompareDates(Periods1.EndDate , Periods2.StartDate) == enCompareDate::before)
	{
		return false;
	}
	
	return true;
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriods Period1 = ReadPeriod();
	cout << endl;

	cout << "\nEnter Period2:\n";
	stPeriods Period2 = ReadPeriod();

	if (IsOverLap(Period1,Period2))
	{
		cout << "\nYes , periods overlap\n";
	}
	else
	{
		cout << "\nNo, Periods do not overlap\n";
	}

	return 0;
}