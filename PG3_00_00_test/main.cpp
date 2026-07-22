#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
    Dog dog;
    Cat cat;

    Animal* animals[2] =
    {
        &dog,
        &cat
    };

    for (int i = 0; i < 2; i++)
    {
        animals[i]->MakeSound();
    }

    return 0;
}
