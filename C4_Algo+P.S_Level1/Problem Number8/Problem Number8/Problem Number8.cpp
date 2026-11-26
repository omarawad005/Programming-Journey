/*
	

    #include <iostream>
    using namespace std;

    void ReadMark(int& Mark)
    {

        cout << "Please enter your Mark : ";
        cin >> Mark;
    }

    string checkMark(float Mark)
    {
        if (Mark >= 50)
            return "Pass";
        else
            return "Fail";
    }

    void PrintResults(string Mark)
    {
        cout << "\nThe Result is : " << Mark << endl;
    }


    int main()
    {
        int Mark;
        ReadMark(Mark);
        PrintResults(checkMark(Mark));



        return 0;
    }



#include <iostream>
using namespace std;

enum enPassFail
{
    Pass = 1,
    Fail = 2
};

int ReadMark()
{
    int Mark;
    cout << "Please enter Mark : ";
    cin >> Mark;
    return Mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;

}

void PrintMark(int Mark)
{
    if (Mark == enPassFail::Pass)
        cout << "\nYou Passed !\n";
    else
        cout << "\n You Faild !\n";
}

int main()
{
    PrintMark(CheckMark(ReadMark()));

    return 0;
}*/
#include <iostream>
using namespace std;

enum enPassFail
{
    Pass = 1,
    Fail = 2

};

int ReadNumber()
{
    int Mark;
    cout << "Enter Your Mark : ";
    cin >> Mark;

    return Mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;

}

void PrintResult(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "Pass\n";
    else
        cout << "Fail\n";
}


int main()
{


    PrintResult(ReadNumber());

    return 0;
}
