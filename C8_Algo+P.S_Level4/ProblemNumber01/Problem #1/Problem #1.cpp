/*
#include <iostream>
#include <limits>
using namespace std;

string NumberToText(long long Number)
{
	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string arr[] = { "","One","Two","Three","Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

		return arr[Number] + " ";
	}

	if (Number >= 20 && Number <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty",
			"Seventy","Eighty","Ninety" };

		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199)
	{
		return "One Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
	}
}

long long ReadNumber()
{
	long long Num;

	cout << "Please enter Number : ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter A Number ?? ";
		cin >> Num;
	}

	return Num;
}

int main()
{
	long long Number = 0;

	Number = ReadNumber();

	string Result = NumberToText(Number);

	cout << "\n" << Result << endl;

	system("pause");
}
*/

#include <iostream>
#include <limits>
using namespace std;

string NumberToText(long long Number)
{
	if (Number == 0)
		return "";

	string ones[] = { "","One","Two","Three","Four","Five","Six","Seven",
					  "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
					  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

	string tens[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty",
					  "Seventy","Eighty","Ninety" };

	if (Number < 20)
		return ones[Number] + " ";

	if (Number < 100)
		return tens[Number / 10] + " " + NumberToText(Number % 10);

	if (Number < 1000)
		return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);

	if (Number < 1000000)
		return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);

	if (Number < 1000000000)
		return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);

	return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
}

long long ReadNumber()
{
	long long Num;

	cout << "Please enter Number : ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter A Number ?? ";
		cin >> Num;
	}

	return Num;
}

int main()
{
	long long Number = ReadNumber();

	if (Number == 0)
		cout << "Zero";
	else
		cout << NumberToText(Number);

	cout << endl;
}
