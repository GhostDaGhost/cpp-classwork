#include <iostream>
#include "animal.h"
#include "bird.h"
#include "dog.h"
#include "cat.h"

// NAMESPACES
using namespace std;

// MAIN
int main() {
    Animal *animal = new Animal();
    animal->makeSound();
	animal->eatFood();
    delete animal;

    // DOG
    Dog *dog = new Dog();
    dog->makeSound();
    dog->lick();
    dog->eatFood();
    delete dog;

    // BIRD
    Bird *bird = new Bird();
    bird->makeSound();
    bird->eatFood();
	bird->fly();
    delete bird;

    // CAT
    Cat *cat = new Cat();
    cat->makeSound();
	cat->eatFood();
    delete cat;

    // END PROGRAM
    return 0;
}
