#include <iostream>
using namespace std;
/*
Static members of a class are those data that do not resent their value for every object.
Every object of the class share the static variable value and keep track of it.
Static variable cannot be initialised inside the class.
*/
class Student
{
    string name;
    static int total_students;

public:
    Student(string name)
    {
        total_students++;
        this->name = name;
    }
    int get_total_students()
    {
        return total_students;
    }
};

int Student ::total_students = 0;

int main()
{
    Student S01("Alex");
    Student S02("John");
    cout << S01.get_total_students() << endl;
    cout << S02.get_total_students();
}
/*
Output:
2
2

Both objects have same values because they both are accessing same memory location.
*/