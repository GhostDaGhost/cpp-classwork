#include <iostream>
#include "animal.h"

// NAMESPACES
using namespace std;

// CLASS
class Cat : public Animal {
	public:
		void makeSound() {
			cout << "The cat says: MEOW! Purr..." << endl;
		}
};
