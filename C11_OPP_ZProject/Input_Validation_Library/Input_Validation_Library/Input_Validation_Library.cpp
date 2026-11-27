
#include <iostream>
#include "clsInputValidate.h"

using namespace std;


int main()
{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;
    
    cout << clsInputValidate::IsDateBetween(clsDate(), 
                                    clsDate(8, 2, 2026), 
                                    clsDate(31, 12, 2026)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
                                clsDate(31, 12, 2026),
                                clsDate(8, 8, 2026)) << endl;
    

    cout << "\nPlease enter a Number : ";
    int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again : ");
    cout << "x = " << x << endl;

    cout << "\nPlease enter a Number between 1 and 5 : ";
    int y = clsInputValidate::ReadIntNumberBetween(1,5,"Invalid Number, Enter again between 1 and 5 : ");
    cout << "y = " << y << endl;


    cout << "\nPlease enter a double Number : ";
    double z = clsInputValidate::ReadDoubleNumber("Invalid Number, Enter again : ");
    cout << "z = " << z << endl;

    cout << "\nPlease enter a double Number between 1.5 and 5.8 : ";
    double d = clsInputValidate::ReadDoubleNumberBetween(1.5,5.8,"Invalid Number, Enter again between 1.5 and 5.8 : ");
    cout << "d = " << d << endl;


    cout << clsInputValidate::IsValidDate(clsDate(35, 10, 2026));

    system("pause > 0");
    return 0; 
}
