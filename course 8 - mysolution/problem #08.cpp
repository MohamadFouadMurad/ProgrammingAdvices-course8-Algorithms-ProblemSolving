#include <iostream> 
#include <cstdio>
#include <iomanip>

using namespace std;

short ReadNumber(string message)
{
	int Number = 0;
	cout << message;
	cin >> Number;
	return Number;
}

short ReadYear(string message)
{
	int Year = 0;
	cout << message;
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar","Apr", "May", "Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec"};

	return (Months[MonthNumber - 1]);
}

int NumberOfDaysInAMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :NumberOfDays[Month - 1];
	
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short Day)
{
	string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arr[Day];
}

void PrintMonthCalendar(short Month, short Year)
{
	cout << "---------------";
	cout << MonthShortName(Month);
	cout << "-------------------" << endl;

	short current = DayOfWeekOrder(1, Month, Year);

	short NumberOfDays = NumberOfDaysInAMonth(Year, Month);

	cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

	for (int i = 0; i < current; i++)
	{
		printf("     ");
	}


	for (int j = 1; j <= NumberOfDays; j++)
	{
		cout << setw(5) << j;


		if (++current == 7)
		{
			current = 0;
			cout << "\n";
		}
	}



	cout << "\n-------------------------------------" << endl;
}


int main()
{
	short Year = ReadYear("Pls enter a Year to check? ");

	cout << endl;

	short Month = ReadNumber("pls enter a monthe to check? ");

	cout << endl;

	PrintMonthCalendar(Month, Year);

	return 0;
}