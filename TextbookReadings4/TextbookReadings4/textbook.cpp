#include <iostream>
#include <fstream>

using namespace std;

static void copyFile(string& sourceFileName, string& destinationFileName) {
    ifstream source(sourceFileName);
    if (source) {
        ofstream destination(destinationFileName);
        if (destination) {
            destination << source.rdbuf();
            cout << "File copied successfully from " << sourceFileName << " to " << destinationFileName << endl;
        }
    }
}

int main() {
    string sourceFileName;
    string destinationFileName;

    // ASK FOR SOURCE FILE NAME
    cout << "Enter the source file name: ";
	cin >> sourceFileName;

    // ASK FOR DESTINATION FILE NAME
    cout << "Enter the destination file name: ";
    cin >> destinationFileName;

	// COPY FILE
    copyFile(sourceFileName, destinationFileName);
}
