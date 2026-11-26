/*
	
	#include <iostream>
	using namespace std;

	int GetAge()
	{
		int Age;

		cout << "Please enter Your Age : ";
		cin >> Age;

		return Age;
	}

	bool isValidAge(int Age)
	{
		return (Age >= 18 && Age <= 45);
	}

	void PrintResult(bool Valid)
	{
		if (Valid)
			cout << "Valid Age " << endl;
		else
			cout << "InValid Age " << endl;
	}




	int main()
	{
		int UserAge = GetAge();

		while (!isValidAge(UserAge))
		{
			PrintResult(false);
			UserAge = GetAge();
		}
		PrintResult(true);

		return 0;
	}
*/
/*
		#include <iostream>
	using namespace std;

	int ReadAge()
	{
		int Age;

		cout << "Please enter your Age : ";
		cin >> Age;

		return Age;
	}

	bool ValidateNumberInRange(int Number , int From , int To)
	{
		return (Number >= From && Number <= To);
	}

	int ReadUntilAgeBetween(int From, int To)
	{
		int Age = 0;
		do
		{
			Age = ReadAge();
		} while (!ValidateNumberInRange(Age, From, To));

		return Age;
	}

	void PrintResult(int Age)
	{
		cout << endl << Age << " is a Validate Age \n" ;
	}


	int main()
	{
	
		PrintResult(ReadUntilAgeBetween(18, 45));

		return 0;
	}
*/

#include <iostream>

using namespace std;

bool IsValideAge(int age, int From, int To)
{
	return (age >= From && age <= To);
}

int ReadAge()
{
	int Age;

	do
	{
		cout << "Enter Your Age : ";
		cin >> Age;

	} while (!(IsValideAge(Age, 18, 45)));
	

	return Age;

}



void PrintResult(int Age)
{
	if (IsValideAge(Age, 18, 45))
		cout << "\nValid Age ^-^  \n";
	else
		cout << "\nInValid Age ^+^  \n";

}




int main()
{


	PrintResult(ReadAge());

	return 0;
}

