#include <iostream>
#include "animal.h"

// NAMESPACES
using namespace std;

// CLASS
class Bird : public Animal {
	public:
		void makeSound() {
			cout << "The bird says: TWEET! CHIRP! TWEET!" << endl;
		}
};
