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

int main()
{
	sDate Date1 = ReadFullDate();
	cout << endl;
	sDate Date2 = ReadFullDate();

	if (isDate1BeforeDate2(Date1,Date2))
	{
		cout << "Yes Date1 is less than Date2" << endl;
	}
	else
	{
		cout << "No Date1 is NOT less than Date2" << endl;
	}

	return 0;
}