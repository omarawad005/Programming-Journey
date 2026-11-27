
#include <iostream>
using namespace std;


void PrintFibonacciSeries(int N)
{
  
    int First = 1;
    int Second = 1;

    cout << First << " " << Second << " ";

    for (int i = 3; i < N; i++)
    {
        int next = First + Second;
        cout << next << " ";
        First = Second;
        Second = next;
    }

}


int main()
{
    int Num;
    cout << "Enter Number of Fibonacci Series : ";
    cin >> Num;

    cout << "\n";
    PrintFibonacciSeries(Num);
    
    cout << "\n";
    system("pause> 0");
}

