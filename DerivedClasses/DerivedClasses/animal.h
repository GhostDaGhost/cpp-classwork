#ifndef ANIMAL_H
#define ANIMAL_H

// PACKAGES
#include <iostream>

// NAMESPACES
using namespace std;

// CLASS
class Animal {
	public:
		void makeSound() {
			cout << "The animal made a sound." << endl;
		}

		void eatFood() {
			cout << "The animal ate food." << endl;
		}
};

#endif
