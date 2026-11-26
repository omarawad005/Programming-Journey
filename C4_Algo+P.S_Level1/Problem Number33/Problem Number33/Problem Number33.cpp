

#include <iostream>

using namespace std;


int ReadGrade(int From, int To)
{
	int Grade;

	do
	{

		cout << "Enter Your Grade : ";
		cin >> Grade;

	} while (!(Grade >= From && Grade <= To));

	return Grade;

}

char CheckGrade(int Grade)
{
    if (Grade >= 90)
        return 'A';
    else if (Grade >= 80)
        return 'B';
    else if (Grade >= 70)
        return 'C';
    else if (Grade >= 60)
        return 'D';
    else if (Grade >= 50)
        return 'E';
    else
        return 'F';
}

void PrintResult(int Grade)
{
    cout << "********************************\n";
    cout << "Your Grade is : " << CheckGrade(Grade) << endl;
    cout << "********************************\n";
}


int main()
{


    PrintResult(ReadGrade(1, 100));

	return 0;
}