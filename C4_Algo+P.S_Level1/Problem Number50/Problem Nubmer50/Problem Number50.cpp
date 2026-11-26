
#include <iostream>

using namespace std;


int ReadPositveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

bool Logen()
{
	int Counter = 0;
	int PIN;
	do
	{
		PIN = ReadPositveNumber("Please enter Your PIN : ");
		if (PIN != 1234)
		{
			Counter++;
			system("color 4F");
			cout << "\nWorng PIN, ";
			cout << "You have " << 3 - Counter << " more tries ?\n";
			if (Counter == 3)
			{
				return false;
			}

		}

	} while (PIN != 1234);

	return true;

}

int main()
{

	if (Logen())
	{
		system("Color 2F");
		cout << "\nYour Balance is : 7500 \n\n";
	}
	else
	{
		cout << "\nLocked\n";
	}

	return 0;
}