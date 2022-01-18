#include <iostream>
using namespace std;

// Initialisation List is used to initialize data members of a class. Initialisation list runs just before the constructor.
// A const value connot be changed or set by the constructor but we can set const value in a class using the initialisation list.
class Student
{
    string name;
    int const rollNumber;

public:
    Student(string name, int r) : rollNumber(r)
    {
        this->name = name;
    }

    void displayData()
    {
        cout << name << "\t" << rollNumber << endl;
    }
};

int main()
{
    Student S001("Jack", 22);
    Student S002("John", 23);
    S001.displayData();
    S002.displayData();
}