#include <iostream>
using namespace std;

/*
Constructors: These are the special functions in a class that runs
automaticallly as soon as the object gets created.

Destructors: These are the special functions in a class that runs
automatically as soon as the object goes out of scope (most of the time
when program finishes)

Both should have the function name same with their respective class name
Both should not have a return type
Both may or may not take nay arguments
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
    void makeSound()
    {
        cout << sound << " " << sound << endl;
    }
    void setSound(string sound)
    {
        this->sound = sound;
    }

    ~Animal()
    {
        cout << "Object Destroyed\n";
    }
};

int main()
{
    Animal Dog;
    Dog.setSound("Bark");
    Dog.makeSound();
}

/*
Output:


Object Created
Bark Bark
Object Destroyed


*/