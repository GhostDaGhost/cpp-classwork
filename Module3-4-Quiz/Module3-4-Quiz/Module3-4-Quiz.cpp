#include <iostream>

using namespace std;

void q1f(int& p1, int& p2) {
	int temp = p1;
	p1 = p2;
	p2 = temp;
}

void q1() {
	int x = 4;
	int y = 5;

	q1f(x, y);
	cout << x;
}

void main() {
    cout << "Hello World!\n";
	q1();
}
