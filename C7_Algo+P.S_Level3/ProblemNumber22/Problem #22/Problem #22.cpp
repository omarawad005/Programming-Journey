#include <iostream>
using namespace std;

void PrintFibonacciSeries(int Num, int Prev1, int Prev2)
{
    int NextNumber;

    if (Num > 0)
    {
        NextNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = NextNumber;
        cout << NextNumber << "  ";
        PrintFibonacciSeries(Num - 1, Prev1, Prev2);

    }

}

int main() 
{
  


    PrintFibonacciSeries(10, 1, 0);

    cout << endl;
    return 0;
}
