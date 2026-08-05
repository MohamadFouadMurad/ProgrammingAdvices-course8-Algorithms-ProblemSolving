#include <iostream>

using namespace std;

long long ReadNumber(string message)
{
	int Number = 0;
	cout << message << " : ";
	cin >> Number;
	return Number;
}

string NumberToText(long long Number)
{

	if (Number == 0)
	{
		return "";
	}
	else if (Number < 20)
	{
		string arr[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

		return arr[Number] + "";
	}
	else if (Number < 100)
	{
		string arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	else if (Number < 200)
	{
		return "One Hundred " + NumberToText(Number % 100);
	}
	else if (Number < 1000)
	{
		return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
	}
	else if (Number < 2000)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}
	else if (Number < 1000000)
	{
		return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
	}
	else if (Number < 2000000)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}
	else if (Number < 1000000000)
	{
		return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
	}
	else if(Number < 2000000000)
	{
		return "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
	}

}

int main()
{

	long long Number = ReadNumber("pls enter a number?");
	cout << endl;

	cout << NumberToText(Number) << endl;

	return 0;
}