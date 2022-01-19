#include <iostream>
using namespace std;

/*
Operator Overloading allows us to define out own functions whenever any
operation is done in our class.

Below program we are creator (+) operator overloading to add two fraction.
We assume that the denominators of the operands are same.

*/

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // For binary operators
    Fraction operator+(Fraction &f)
    {
        int num = this->numerator + f.numerator;
        Fraction F(num, this->denominator);
        return F;
    }

    // For unary operators
    // Pre-Increment
    Fraction operator++()
    {
        this->numerator = this->numerator + this->denominator;
        return *this;
    }

    // Post-Increment
    Fraction operator++(int)
    {
        Fraction F(this->numerator, this->denominator);
        this->numerator = this->numerator + this->denominator;
        return F;
    }
    void printFraction()
    {
        cout << numerator << " / " << denominator << endl;
    }
};

int main()
{
    Fraction F01(5, 17);
    Fraction F02(13, 17);

    F01.printFraction();
    F02.printFraction();

    Fraction F03 = F01 + F02;
    F03.printFraction();

    Fraction F04 = ++F01;
    F04.printFraction();

    Fraction F05 = F02++;
    F05.printFraction();
    F02.printFraction();
}
/*
Output:
5 / 17
13 / 17
18 / 17
22 / 17
13 / 17
30 / 17
*/