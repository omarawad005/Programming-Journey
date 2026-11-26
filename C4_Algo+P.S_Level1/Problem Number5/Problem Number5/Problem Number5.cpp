
/*
	/*
	#include <iostream>
	using namespace std;




	void Readinfo(int& age, char& Driverlicense,char &Recommendation )
	{
		cout << "Do You have a Recommendation? (Y/N) : ";
		cin >> Recommendation;
		cout << "Please enter your age : ";
		cin >> age;
		cout << "Do you have a driver's license? (Y/N): ";
		cin >> Driverlicense;

	}

	string CheckAgeandDriverlicense(int age, char Driverlicense, char Recommendation)
	{
		if (Recommendation == 'Y')
			return "Hired";
		else if (age > 21 && Driverlicense == 'Y')
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
		char Recommendation;
		int age;
		char Driverlicense;
		Readinfo(age, Driverlicense,Recommendation);
		PrintResult(CheckAgeandDriverlicense(age, Driverlicense, Recommendation));





		return 0;
	}

#include <iostream>
using namespace std;


struct stInfo
{
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please enter Your Age : ";
	cin >> Info.Age;

	cout << "Do you have a driver's license? (1/0):  ";
	cin >> Info.HasDrivingLicense;

	cout << "Do you have a Recommendation? (1/0):  ";
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
		return true;
	else
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
	bool HasRecomendation;
};

stDriverInfo ReadDriverInfo()
{
	stDriverInfo Info;
	cout << "Pleas enter Your Age : ";
	cin >> Info.Age;

	cout << "Did you have Driver License Y(1) / N(0) : ";
	cin >> Info.DriverLicense;

	cout << "Did you have Recomendation  Y(1) / N(0) : ";
	cin >> Info.HasRecomendation;

	return Info;

}

bool CheckInfo(stDriverInfo Info)
{

	if (Info.HasRecomendation)
		return true;
	else
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