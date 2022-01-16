#include <iostream>
using namespace std;

/*
Object Oriented programming is all about representing real life entites through code.
These real life entities are called Objects and the blueprint on which multiple objects
are made is called a class.

For Example:
An Animal class is a blueprint of animals like Cat, Dog, Horse etc. Because every animal
will be based on the same blueprint of Animal class. That means every animal will have a sound,
legs, running speed and more. Here the different object can be called objects.

*/

class Animal
{
public:
    string sound;
    float avgHeight;

    void makeSound()
    {
        cout << sound << " " << sound;
    }
};

int main()
{
    Animal Dog;
    Dog.sound = "Bark";
    Dog.makeSound();
}

/*
In the above code we created an Animal class to make a Dog Object.
We can set data members and functions of a class using the dot (.) operator.
The public keyword (line 18) is used to make the part of code available to
outside of the class.
*/