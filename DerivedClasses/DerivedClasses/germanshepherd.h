#include <iostream>
#include "dog.h"

// NAMESPACES
using namespace std;

// CLASS
class GermanShepherd : public Dog {
	public:
		bool isGoodForGuarding() {
			return true;
		}
};
