
#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enum enRandom
{
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharacter = 3,
	Digit = 4

};





char PrintResult(enRandom Random)
{
	switch (Random)
	{
	case enRandom::SmallLetter:
		return RandomNumber(97, 122);
		break;

	case enRandom::CapitalLetter:
		return RandomNumber(65, 90);
		break;

	case enRandom::SpecialCharacter:
		return RandomNumber(33, 47);
		break;

	case enRandom::Digit:
		return RandomNumber(48, 57);
		break;

		default:
			return RandomNumber(97, 122);

			break;
	}

}


int main()
{
	srand((unsigned)time(NULL));

	cout << "\n" << PrintResult(enRandom::SmallLetter) << endl;
	cout << PrintResult(enRandom::CapitalLetter) << endl;
	cout << PrintResult(enRandom::SpecialCharacter) << endl;
	cout << PrintResult(enRandom::Digit) << endl;

	return 0;
}