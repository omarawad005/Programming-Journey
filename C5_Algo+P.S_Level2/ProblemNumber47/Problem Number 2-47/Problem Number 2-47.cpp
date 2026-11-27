#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Num = 0;
    cout << "Please enter Number : ";
    cin >> Num;
    return Num;
}

float GetFractionPart(float Num)
{
    if (Num >= 0)
        return float(Num - int(Num));
    else
        return float(Num - int(Num)) * -1;
}

int MyRoundFunction(float Number)
{
    float FractionPart = GetFractionPart(Number);

    if (Number >= 0)
    {
        if (FractionPart >= 0.5)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
    {
        if (FractionPart >= 0.5)
            return int(Number) - 1;
        else
            return int(Number);
    }
}

int main()
{
    float Number = ReadNumber();

    cout << "My  Round Result : " << MyRoundFunction(Number) << endl;
    cout << "C++ Round Result : " << round(Number) << endl;

    return 0;
}
