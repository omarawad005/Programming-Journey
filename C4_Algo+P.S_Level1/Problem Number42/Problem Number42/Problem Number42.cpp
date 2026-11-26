
#include <iostream>

using namespace std;

struct stTaskDuration
{
	int Days, Hourses, Minuts, seconds;
};

int ReadNumber(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;

	} while (Num <= 0);
	return Num;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration ReadNumberOf;
	ReadNumberOf.Days = ReadNumber("Please enter Number Of Days    : ");
	ReadNumberOf.Hourses = ReadNumber("Please enter Number Of Hourses : ");
	ReadNumberOf.Minuts = ReadNumber("Please enter Number Of Minuts  : ");
	ReadNumberOf.seconds = ReadNumber("Please enter Number Of Seconds : ");

	return ReadNumberOf;

}

int TaskDurationInSecond(stTaskDuration TaskDuration)
{
	return ((TaskDuration.Days * 24 * 60 * 60) + (TaskDuration.Hourses * 60 * 60) + (TaskDuration.Minuts * 60) + TaskDuration.seconds);
}

int main()
{

	cout << "\n"  << TaskDurationInSecond(ReadTaskDuration()) << " Seconds" << endl;

	return 0;
}