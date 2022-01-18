#include <iostream>
using namespace std;

/*
C++ has three types of constructors:
1) Default Constructor
Normal Contructor that do not take any arguments. Gets called by:
<ClassName> obj;

2) Parameterized Constructor
Contructor that takes arguments in thier function signature. Gets called by:
<ClassName> obj(DataType Argument, DataType Argument);

3) Copy Constructor
This constructor copies the values on one object to another Object of the same class.
<ClassName> obj;
<ClassName> obj2(obj);
*/
class Animal
{
private:
    string sound;
    float avgHeight;

public:
    Animal()
    {
        cout << "Object Created\n";
    }
    Animal(string sound, float avgHeight)
    {
        this->sound = sound;
        this->avgHeight = avgHeight;
    }
    void makeSound()
    {
        cout << sound << " " << sound << endl;
    }
    void setSound(string sound)
    {
        this->sound = sound;
    }
};
int main()
{
    // Default Constructor
    Animal obj;
    // Parameterized Constructor
    Animal obj_param("Meow", 18);
    // Copy Constructor
    Animal obj_copy(obj_param);

    cout << "Copy Constructor ";
    obj_copy.makeSound();
}