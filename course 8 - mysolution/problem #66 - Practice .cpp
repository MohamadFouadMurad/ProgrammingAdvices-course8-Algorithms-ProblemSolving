#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

int ReadNumber()
{
	int n;
	cout << "Enter a Number?";
	cin >> n;
	return	n;
}

string NumberToText(int Number)
{
	if (Number == 0)
	{
		return "";
	}
	if (Number >= 1 && Number <= 19)
	{
		string arr[] = { "",
		"One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr[Number] + " ";
	}
	if (Number >= 20 && Number <= 99)
	{
		string arr[] = {
		"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
		,"Ninety" };
		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 199)
	{
		return "One Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + "Hundreds " +
			NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + "Thousands " +
			NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + "Millions " +
			NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + NumberToText(Number %
			1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + "Billions " +
			NumberToText(Number % 1000000000);
	}
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

int ReadDay()
{
	int d;
	cout << "\npls enter a day to check?";
	cin >> d;
	return d;
}

bool isLeapYear(int year)
{
	return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
}

long NumberOfDaysinYear(int Year)
{
	return (isLeapYear(Year)) ? 366 : 365;
}

long NumberOfHoursInYear(int Year)
{
	return NumberOfDaysinYear(Year) * 24;
}

long NumberOfMinutesInYear(int Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

long NumberOfSecondsInYear(int Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	if (Month == 2)
	{
		return isLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	//if you reach here then its 30 days.
	return 30;
}

short NumberOfHoursInAMonth(short Month, short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arr[DayOfWeekOrder];
}

string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar",
	"Apr", "May", "Jun",
	"Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
	};
	return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
	int NumberOFDays = NumberOfDaysInAMonth(Month, Year);

	int current = DayOfWeekOrder(1, Month, Year);

	cout << "-------------------------------" << MonthShortName(Month) << "---------------------------------------" << endl;


	printf("\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n");


	for (int i = 1; i <= current; i++)
	{
		printf("       ");
	}

	for (int j = 1; j <= NumberOFDays; j++)
	{
		printf("%7d", j);

		if (++current == 7)
		{
			current = 0;
			cout << "\n";
		}
	}

	cout << "\n------------------------------------------------------------------------\n";

}

void PrintYearCalendar(int Year)
{
	printf("\n _________________________________\n\n");
	printf("             Calendar - %d\n", Year);
	printf(" _________________________________\n");


	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
	}
}

int NumberOfDaysFromTheBeginingOfTheYear(int Day, int Month, int Year)
{
	short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;

}

struct sDate
{
	short Day;
	short Month;
	short Year;
};

sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
	sDate Date;
	int Remainder = DaysOrderInYear;
	short MonthDays = 1;

	Date.Year = Year;


	while (true)
	{

		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (Remainder > MonthDays)
		{
			Remainder -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = Remainder;
			break;
		}


	}

	return Date;
}

short ReadDaysToAdd()
{
	short Days;
	cout << "\nHow many days to add? ";
	cin >> Days;
	return Days;
}

sDate DateAddDays(int DaysToAdd, sDate Date)
{
	int DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	int RemainingDays = DaysToAdd + DaysOrderInYear;
	int Year = Date.Year;


	while (RemainingDays > NumberOfDaysinYear(Year))
	{
		RemainingDays -= NumberOfDaysinYear(Year);
		Year++;
	}

	Date = GetDateFromDayOrderInYear(RemainingDays, Year);

	return Date;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsDate1LessthatDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) &&
		(Date1.Month == Date2.Month) &&
		(Date1.Day == Date2.Day);
}

bool IsLastDayInMonth(sDate Date)
{
	int DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day == DaysInMonth)
	{
		return true;
	}

	return false;
}

bool IsLastMonthInYear(sDate Date)
{
	return Date.Month == 12 ? true : false;
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;

}

void SwapDates(sDate& Date1, sDate& Date2)
{
	sDate temp;
	temp = Date1;
	Date1 = Date2;
	Date2 = temp;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
	int Days = 0;
	bool Date2BeforeDate1 = false;

	if (!IsDate1LessthatDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		Date2BeforeDate1 = true;
	}

	while (IsDate1LessthatDate2(Date1, Date2))
	{
		Date1 = IncreaseDateByOneDay(Date1);
		Days++;
	}

	Days = IncludingEndDay ? ++Days : Days;


	return Date2BeforeDate1 ? Days * -1 : Days;
}

sDate GetSystemDate()
{
	sDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

sDate IncreaseDateByXDays(int xDays, sDate Date)
{
	for (int i = 0; i < xDays; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return	Date;
}

sDate IncreaseDateByXWeeks(int Weeks, sDate Date)
{
	for (int i = 0; i < Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return	Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	int CurrentMonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > CurrentMonthDays)
	{
		Date.Day = CurrentMonthDays;
	}

	return Date;
}

sDate IncreaseDateByXMonths(int xMonths, sDate Date)
{

	for (int i = 0; i < xMonths; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	Date.Year++;

	// حماية حالة 29 فبراير عند الانتقال لسنة عادية
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate IncreaseDateByXYears(int xYears, sDate Date)
{
	for (int i = 0; i < xYears; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearsFaster(int xYears, sDate Date)
{
	Date.Year += xYears;

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	//Period of 10 years
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
	//Period of 1000 years
	Date.Year += 1000;
	return Date;
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
			Date.Day = NumberOfDaysInAMonth(Date.Month,
				Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

sDate DecreaseDateByXDays(int Days, sDate Date)
{
	for (int i = 0; i < Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
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
		Date.Month--;


	//last check day in date should not exceed max days in the current month
	// example if date is 31/3/2022 decreasing one month should not be 31 / 2 / 2022, it should
	// be 28/2/2022

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate DecreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
	//Period of 10 years
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
	//Period of 1000 years
	Date.Year -= 1000;
	return Date;
}

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool isEndOfWeek(sDate Date)
{
	if (DayShortName(DayOfWeekOrder(Date)) == "Sat")
	{
		return true;
	}
	return false;
}

bool IsWeekEnd(sDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	sDate EndOfMonth;

	EndOfMonth.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonth.Month = Date.Month;
	EndOfMonth.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonth, true);
}

short DaysUntilTheEndOfYear(sDate Date)
{
	sDate EndOfYear;

	EndOfYear.Day = 31;
	EndOfYear.Month = 12;
	EndOfYear.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYear, true);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
	short Days = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			Days++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return Days;
}

sDate CalculateVacationReturnDate(sDate DateFrom, int VacationDays)
{
	short WeekEndDays = 0;

	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	for (int i = 0; i < VacationDays + WeekEndDays; i++)
	{
		if (IsWeekEnd(DateFrom))
		{
			WeekEndDays++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;

}

bool isDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enCompareDate
{
	After = 1, Equal = 0, Before = -1
};

short CompareDates(sDate Date1, sDate Date2)
{
	enCompareDate CompareDate;

	if (IsDate1BeforeDate2(Date1,Date2))
	{
		return enCompareDate::Before;
	}
	else 
	if (isDate1AfterDate2(Date1,Date2))
	{
		return enCompareDate::After;
	}

	return enCompareDate::Equal;
}

struct stPeriod
{
	sDate StartDate;
	sDate EndDate;
};

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	
	return Period;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period1.EndDate,Period2.StartDate) == enCompareDate::Before ||
		CompareDates(Period2.EndDate,Period1.StartDate) == enCompareDate::Before)
	{
		return false; 
	}

	return true;
}

short PeriodLength(stPeriod Period1, bool IncludingEndDate = false)
{
	return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, true);
}

bool IsDateWithinPeriod(stPeriod Period1, sDate Date)
{
	if (isDate1AfterDate2(Date,Period1.EndDate) || IsDate1BeforeDate2(Date,Period1.StartDate))
	{
		return false;
	}

	return true;
}

short CountOverLap(stPeriod Period1, stPeriod Period2)
{
	if (!IsOverlapPeriods(Period1,Period2))
	{
		return 0;
	}

	sDate SDate, EDate;

	if (isDate1AfterDate2(Period2.StartDate,Period1.StartDate))
	{
		SDate = Period2.StartDate;
	}
	else
	{
		SDate = Period1.StartDate;
	}


	if (IsDate1BeforeDate2(Period1.EndDate,Period2.EndDate))
	{
		EDate = Period1.EndDate;
	}
	else
	{
		EDate = Period2.EndDate;
	}

	return GetDifferenceInDays(SDate,EDate,true);
}

bool isDateValid(sDate Date)
{
	if (Date.Month > 12 || Date.Month < 1)
	{
		return false;
	}

	int ActualNumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > ActualNumberOfDaysInMonth || Date.Day < 1)
	{
		return false;
	}

	return true;
}

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;

	short pos = 0;
	string sWord; // define a string variable
	
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		
		S1.erase(0, pos + Delim.length());
	
	}
	
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	
	return vString;
}

string ReadStringDate(string Message)
{
	string DateString;

	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

sDate StringToDate(string DateString)
{
	sDate Date;
	vector <string> vDate = SplitString(DateString, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(sDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),sRepalceTo);
		
		pos = S1.find(StringToReplace);//find next
	}
	
	return S1;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormtedDate = DateFormat;

	FormtedDate = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormtedDate = ReplaceWordInString(FormtedDate, "mm", to_string(Date.Month));
	FormtedDate = ReplaceWordInString(FormtedDate, "yyyy", to_string(Date.Year));

	return FormtedDate;
}

int main()
{
	
	string DateString = ReadStringDate("\nPlease Enter Date dd / mm / yyyy ? ");

	sDate Date = StringToDate(DateString);
	
	cout << "\n" << FormateDate(Date) << "\n";
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";

	return 0;
}