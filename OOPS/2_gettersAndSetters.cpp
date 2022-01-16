#include <iostream>
using namespace std;

/*
To protect the data members from getting modified by the outside code,
we use getters and setters. Since the code outside the class cannot access
the private code of the class so we use getters and setter funcitons to
use the data members. But the data members should be in public section of the class.
*/

class Animal
{
private:
    string sound;
    float avgHeight;

public:
    void setSound(string sound)
    {
        this->sound = sound;
    }

    void getSound()
    {
        cout << sound << " " << sound;
    }
};

int main()
{
    Animal Dog;
    Dog.setSound("Bark");
    Dog.getSound(); // Bark Bark
}
