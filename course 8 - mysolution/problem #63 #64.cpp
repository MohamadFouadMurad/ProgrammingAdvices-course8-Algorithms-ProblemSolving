#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sDate
{
	int Day; int Month; int Year;
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

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

	sDate Date = StringToDate(DateString);

	cout << "\nDay:" << Date.Day << "\nMonth:" << Date.Month << "\nYear:" << Date.Year;

	string DateTostring = DateToString(Date);

	cout << "\n\nYou Entered: " << DateTostring << endl;
}