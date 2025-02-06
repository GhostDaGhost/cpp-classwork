#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream SampleFile("sample.txt");

	// ITERATE THROUGH EACH LINE
	string fileText;
	for (int i = 9; i >= 0; i--) {
		cout << "Line " << i << ": " << fileText << endl;
	}

	// CLOSE FILE WHEN FINISHED
	SampleFile.close();
}
