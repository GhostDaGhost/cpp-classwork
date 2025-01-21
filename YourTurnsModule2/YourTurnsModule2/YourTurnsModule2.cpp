#include <iostream>

using namespace std;

static int GetLengthOfCharacterArray(const char* characterArray) {
    unsigned int count = 0;
	while (characterArray[count] != '\0') {
        count++;
	}
    return count;
}

static void ArrayCopy() {
    int source[] = { 0, 1, 2, 3, 4 };
    int dest[5];

    // USE POINTERS TO COPY SOURCE TO DEST
    int* sp = source;
	int* dp = dest;

    // ITERATE THROUGH AMOUNT OF INDEXES THAT ARRAY HAS AND THEN COPY USING ARITHMETIC AND INCREMENTORS
	unsigned int lengthOfArray = sizeof(source) / sizeof(source[0]);
    for (int i = 0; i < lengthOfArray; i++) {
        *dp++ = *sp++;
    }

    // OUTPUT RESULTS
    for (int i = 0; i < lengthOfArray; i++) {
        cout << dest[i] << endl;
    }
}

static void SwapTwoNumbers(int* number1, int* number2) {
    int oldNumber1Pointer = *number1;
    *number1 = *number2;
	*number2 = oldNumber1Pointer;

	// OUTPUT RESULTS
	cout << "Number 1: " << *number1 << endl;
	cout << "Number 2: " << *number2 << endl;
}

int main() {
    int number1 = 2, number2 = 4;
    cout << "Your Turns From Module 2:" << endl;

    // LENGTH OF CHARACTER ARRAY
	cout << "Length of character array: " << GetLengthOfCharacterArray("Hello World!") << endl;

    // ARRAY COPY AND NUMBER SWAPPING
    ArrayCopy();
    SwapTwoNumbers(&number1, &number2);
    
    // END PROGRAM
    return 0;
}
