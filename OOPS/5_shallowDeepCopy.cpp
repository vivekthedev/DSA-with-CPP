#include <iostream>
using namespace std;

class Student
{
    char *name;
    char *grades;

public:
    Student(char *name, char *grades)
    {
        this->name = name;
        this->grades = grades;
    }
    void displayData()
    {
        cout << name << "\t" << grades;
    }
};
int main()
{
    // Shallow Copy Because S_1 and S_2 takes adderess of grades and both vale will change if the grades is changed
    // Deep Copy means to make a new Copy of the grades and then storing it in the S_1 and S_2
    char *grades = "A++";
    Student S_1("John Doe", grades);
    grades[0] = 'B';
    Student S_2("Alex Broad", grades);

    S_1.displayData();
    S_2.displayData();
}