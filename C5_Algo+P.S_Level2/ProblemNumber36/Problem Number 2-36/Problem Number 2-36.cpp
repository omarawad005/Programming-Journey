
    
#include <iostream>
using namespace std;


int ReadNumber()
{
    int Num = 0;
    cout << "Please enter Number ? ";
    cin >> Num;
    return Num;
}

void AddArrayElement(int Number, int arr[100], int& arrlength)
{
    arrlength++;
    arr[arrlength - 1] = Number;
}

void InputUserInArray(int arr[100], int &arrlength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), arr, arrlength);
        cout << "Do you want To Add More ? Yes[1], No[0] ? ";
        cin >> AddMore;
        cout << endl;

    } while (AddMore);

}

void PrintArrayElement(int arr[100], int arrlength)
{
    cout << "Array Element : ";
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main()
{
    
    int Arr[100], Length = 0;

    InputUserInArray(Arr, Length);
    cout << "Array Length : " << Length << endl;
    PrintArrayElement(Arr, Length);


    return 0;
}