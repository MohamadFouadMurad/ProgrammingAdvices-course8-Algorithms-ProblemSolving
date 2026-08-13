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

bool IsEndOfWeek(sDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(sDate Date)
{
	return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6);
}

bool IsBusinessDay()
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

	return 0;
}