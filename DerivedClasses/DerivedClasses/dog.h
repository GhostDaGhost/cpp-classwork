#include <iostream>
#include "animal.h"

// NAMESPACES
using namespace std;

// CLASS
class Dog : public Animal {
	public:
		void makeSound() {
			cout << "The dog says: BARK! BARK!" << endl;
		}
};
