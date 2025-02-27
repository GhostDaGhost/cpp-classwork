#include <iostream>

// NAMESPACES
using namespace std;

// CLASS
class Cat : public Animal {
	public:
		virtual void makeSound() {
			cout << "The cat says: MEOW! Purr..." << endl;
		}

		virtual void eatFood() {
			cout << "The cat ate fish." << endl;
		}
};
