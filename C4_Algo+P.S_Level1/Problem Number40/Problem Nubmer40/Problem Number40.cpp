

#include <iostream>
using namespace std;

float ReadBillValue(string Message)
{
    float Number;
    do
    {
        cout << Message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

float CalcualteServices(float Nubmer)
{

    return Nubmer * 0.10;

}

float CalcualteSalesTax(float Nubmer, float Service)
{
    return (Nubmer + Service) * 0.16;
}

float CalculateTotalBiallValue(float BillVaule, float Service ,float SalesTax)
{
    return BillVaule + Service +SalesTax;
}

void PrintTotalBillValue(float Toatal)
{
    cout << "Total Bill After Serivice Fee and Sales Tax : " << Toatal << endl;
}

int main()
{
    float TotalBillValue = ReadBillValue("Please enter Positive Number : ");

    cout << endl;

    cout << "Total Bill = " << TotalBillValue << endl;


    PrintTotalBillValue(CalculateTotalBiallValue
    (TotalBillValue, CalcualteServices(TotalBillValue), CalcualteSalesTax(TotalBillValue, CalcualteServices(TotalBillValue))));

    return 0;
}