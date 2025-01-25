#include <iostream>

using namespace std;

int main(int argumentCount, char* arguments[]) {
	for (int i = 0; i < argumentCount; i++) {
		char* argument = arguments[i];
		if (i == 0) {
			cout << "Executable name is: " << argument << endl;
		} else {
			cout << "arg" << i << " is: " << argument << endl;
		}
	}
	return 0;
}
