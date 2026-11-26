

#include <iostream>

using namespace std;

enum enMonth
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	september = 9,
	Octobar = 10,
	November = 11,
	December = 12,
};

int ReadMonthInRange(string Message, short From, short To)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < From || Number > To);
	

	return Number;
}

enMonth CheckMonth()
{
	cout << "-------------Month--------------\n";
	cout << "(1) January" << endl;
	cout << "(2) February" << endl;
	cout << "(3) March" << endl;
	cout << "(4) April" << endl;
	cout << "(5) May" << endl;
	cout << "(6) June" << endl;
	cout << "(7) July" << endl;
	cout << "(8) August" << endl;
	cout << "(9) september" << endl;
	cout << "(10) Octobar" << endl;
	cout << "(11) November" << endl;
	cout << "(12) December" << endl;
	cout << "-----------------------------------\n";
	return enMonth(ReadMonthInRange("Please enter Positive Number Of Month : ", 1, 12));

}



string GetMonthOfYear(enMonth Month)
{
	switch (Month)
	{
	case January:
		return "\nJanuary";
	case February:
		return "\nFebruary";
	case March:
		return "\nMarch";
	case April:
		return "\nApril";
	case May:
		return "\nMay";
	case June:
		return "\nJune";
	case July:
		return "\nJuly";
	case August:
		return "\nAugust";
	case september:
		return "\nseptember";
	case Octobar:
		return "\nOctobar";
	case November:
		return "\nNovember";
	case December:
		return "\nDecember";
	default:
		return "\nWrong Month";
	}
}

	int main()
	{
		cout << GetMonthOfYear(CheckMonth()) << endl;

		return 0;
	}