#include <iostream>

// NAMESPACES
using namespace std;

// CLASS
class Bird : public Animal {
	public:
		virtual void makeSound() {
			cout << "The bird says: TWEET! CHIRP! TWEET!" << endl;
		}

		void fly() {
			cout << "The bird flew away." << endl;
		}

		virtual void eatFood() {
			cout << "The bird ate some seeds." << endl;
		}
};
