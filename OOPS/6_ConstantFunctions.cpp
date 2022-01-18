#include <iostream>
using namespace std;

/*
Constant Funcitons are those functions that ensures the compiler that the
function won't change the values of the data members in the class.

A Constant Object (Line 31) won't run getNums() function unless we put a const
keyword in function signature.

*/

class ComplexNum
{
    int realNum;
    int imaginaryNum;

public:
    ComplexNum(int realNum, int imaginaryNum)
    {
        this->realNum = realNum;
        this->imaginaryNum = imaginaryNum;
    }
    void getNums() const
    {
        cout << realNum << " i" << imaginaryNum << endl;
    }
};
int main()
{
    ComplexNum C001(2, 5);
    ComplexNum const C002(6, 11);

    C001.getNums();
    C002.getNums();
}