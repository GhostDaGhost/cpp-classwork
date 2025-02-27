#include <iostream>

// NAMESPACES
using namespace std;

// CLASS
class Dog : public Animal {
	public:
		virtual void makeSound() {
			cout << "The dog says: BARK! BARK!" << endl;
		}

		void lick() {
			cout << "The dog licked you." << endl;
		}

		virtual void eatFood() {
			cout << "The dog ate some chicken and licked the bone." << endl;
		}
};
