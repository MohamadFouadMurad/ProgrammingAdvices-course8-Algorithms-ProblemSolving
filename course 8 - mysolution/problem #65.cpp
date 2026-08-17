#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sDate
{
	int Day; int Month; int Year;
};

enum enDateFormat
{
	FormatOne = 1,
	FormatTwo = 2,
	FormatThree = 3,
	FormatFour = 4,
	FormatFive = 5,
	FormatSix = 6
};

string ReadStringDate(string message)
{
	string Datestring;

	cout << message;
	getline(cin >> ws, Datestring);

	return Datestring;
}

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

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

sDate StringToDate(string DateToString)
{
	sDate Date;
	vector <string> vDate;

	vDate = SplitString(DateToString, "/");

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
	short Pos = S1.find(StringToReplace);

	while (Pos != std::string::npos)
	{
		S1 = S1.replace(Pos, StringToReplace.length(), sRepalceTo);
		Pos = S1.find(StringToReplace);
	}

	return S1;
}

string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormmatedDateToString = DateFormat;

	FormmatedDateToString = ReplaceWordInString(FormmatedDateToString, "dd", to_string(Date.Day));
	FormmatedDateToString = ReplaceWordInString(FormmatedDateToString, "mm", to_string(Date.Month));
	FormmatedDateToString = ReplaceWordInString(FormmatedDateToString, "yyyy", to_string(Date.Year));

	return FormmatedDateToString;
}

string FormmatedDate(const sDate& Date, enDateFormat DateFormat)
{
	switch (DateFormat)
	{
	case enDateFormat::FormatOne:
		return FormatDate(Date, "dd/mm/yyyy");

	case enDateFormat::FormatTwo:
		return FormatDate(Date, "yyyy/dd/mm");

	case enDateFormat::FormatThree:
		return FormatDate(Date, "mm/dd/yyyy");

	case enDateFormat::FormatFour:
		return FormatDate(Date, "mm-dd-yyyy");

	case enDateFormat::FormatFive:
		return FormatDate(Date, "dd-mm-yyyy");

	case enDateFormat::FormatSix:
		return FormatDate(Date, "Day:dd, Month:mm, Year:yyyy");

		default:
		return FormatDate(Date, "dd/mm/yyyy");
	}
}

enDateFormat ReadDateFormat()
{
	short Choice = 1;

	cout << "\nChoose Date Format:\n";
	cout << "[1] dd/mm/yyyy\n";
	cout << "[2] yyyy/dd/mm\n";
	cout << "[3] mm/dd/yyyy\n";
	cout << "[4] mm-dd-yyyy\n";
	cout << "[5] dd-mm-yyyy\n";
	cout << "[6] Day:dd, Month:mm, Year:yyyy\n";
	cout << "\nEnter format number [1-6]: ";
	cin >> Choice;

	while (Choice < 1 || Choice > 6)
	{
		cout << "Invalid choice, enter a number between 1 and 6: ";
		cin >> Choice;
	}

	return (enDateFormat)Choice;
}

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

	sDate Date = StringToDate(DateString);

	enDateFormat SelectedFormat = ReadDateFormat();

	cout << "\nFormatted Date: " << FormmatedDate(Date, SelectedFormat) << endl;

	return 0;
}