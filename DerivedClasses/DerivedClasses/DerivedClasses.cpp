#include <iostream>
#include "animal.h"
#include "bird.h"
#include "dog.h"
#include "cat.h"

// NAMESPACES
using namespace std;

// MAIN
int main() {
    cout << "Hello World!\n";
    Animal animal;
    animal.makeSound();

    // DOG
    Dog dog;
    dog.makeSound();

    // BIRD
    Bird bird;
    bird.makeSound();

    // CAT
    Cat cat;
    cat.makeSound();
    return 0;
}
