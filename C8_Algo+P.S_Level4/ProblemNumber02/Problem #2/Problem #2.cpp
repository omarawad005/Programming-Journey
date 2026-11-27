
#include <iostream>
using namespace std;

short ReadYear()
{
	short Year = 0;
	
	cout << "Enter the Year : ";
	cin >> Year;
	while (cin.fail() || Year <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::min(), '\n');

		cout << "Please enter Year :  ";
		cin >> Year;
	}
	return Year;

}

bool IsLeapYear(short Year)
{
	if (Year % 400 == 0)
		return true;
	else if (Year % 100 == 0)
		return false;
	else  if (Year % 4 ==0 )
		return true;
	else
		return false;
}

int main()
{
	char answer = 'Y';
	do
	{
		system("cls");
		short Year = ReadYear();
		if (IsLeapYear(Year))
			cout << "\nYes, Year [" << Year << "] Is A Leap Year";
		else
			cout << "\nNo, Year [" << Year << "] Is Not A Leap Year";

		cout << "\n\nDo you want check anthor year [y:n]\n";
		cin >> answer;

	} while (answer == 'Y' || answer == 'y');
	


	system("pause > 0");
}
