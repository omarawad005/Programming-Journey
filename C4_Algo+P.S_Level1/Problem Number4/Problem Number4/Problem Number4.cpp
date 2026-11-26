
/*
	/*
	
		void Readinfo(int &age, char &Driverlicense)
	{
		cout << "Please enter your age : ";
		cin >> age;
		cout << "Do you have a driver's license? (Y/N): ";
		cin >> Driverlicense;

	}

	string CheckAgeandDriverlicense(int age, char Driverlicense)
	{
		if (age > 21 && Driverlicense == 'Y')
			return "Hired";
		else
			return "Rejected";
	}

	void PrintResult(string Result)
	{
		cout << "\nThe Result is : " << Result << endl;
	}



	int main()
	{
		int age;
		char Driverlicense;

		Readinfo(age, Driverlicense);
		PrintResult(CheckAgeandDriverlicense(age, Driverlicense));





		return 0;
	}
	


#include <iostream>
using namespace std;


struct stInfo
{
	int Age;
	bool HasDrivingLicense;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please enter Your Age : ";
	cin >> Info.Age;
	cout << "Do you have a driver's license? (1/0):  ";
	cin >> Info.HasDrivingLicense;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.Age > 21 && Info.HasDrivingLicense);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired\n";
	else
		cout << "\n Rejected\n";
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}
*/

#include <iostream>

using namespace std;

struct stDriverInfo
{
	int Age;
	bool DriverLicense;
};

stDriverInfo ReadDriverInfo()
{
	stDriverInfo Info;
	cout << "Pleas enter Your Age : ";
	cin >> Info.Age;

	cout << "Did you have Driver License Y(1) / N(0) : ";
	cin >> Info.DriverLicense;

	return Info;

}

bool CheckInfo(stDriverInfo Info)
{
	return(Info.Age > 21 && Info.DriverLicense == true);
}

void PrintResult(stDriverInfo Info)
{
	if (CheckInfo(Info))
	{
		cout << "Hired\n";
	}
	else
	{
		cout << "Rejected\n";
	}
}


int main()
{
	stDriverInfo DriverInfo;
	
	PrintResult(ReadDriverInfo());

	return 0;
}