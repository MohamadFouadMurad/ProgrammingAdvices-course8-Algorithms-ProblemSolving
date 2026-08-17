#include <iostream>

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

bool IsValidateDate(sDate Date)
{
	if (Date.Month < 1 && Date.Month > 12)
	{
		return false;
	}
	

	if (Date.Day < 1 || Date.Day > NumberOfDaysInAMonth(Date.Year,Date.Month))
	{
		return false;
	}

	//Another way 
	/*
	if (Date.Day < 1 || Date.Day>31)
		return false;
	if (Date.Month < 1 || Date.Month>12)
		return false;

	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}

	short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > DaysInMonth)
		return false;


	return true;
	*/

	return true;
}

int main()
{
	sDate Date = ReadFullDate();


	if (IsValidateDate(Date))
	{
		cout << "\nYes, Date is valide date" << endl;
	}
	else
	{
		cout << "\nNo, Date is a NOT valide date" << endl;
	}
	

	return 0;
}