#include <iostream>

using namespace std;

//
// getWord()
//
// Purpose:
//    Prompt the user to enter a string
//    Return string via output pointer parameter
// 
// Parameters:
//    string *word -- pointer to a string that will contain the string the user entered
//
// Return:
//    void
//
void getWord(string* word)
{
    cout << "Enter a word: ";
    /* Add your code here that performs the cin and sets the word parameter */
    cin >> *word;
}

//
// convertStringCharArray()
//
// Purpose:
//    convert the given string into an dynamically allocated array of characters
// 
// Parameters:
//    string word -- the string that has all the letters that will be used to populate the dynamic char array
//    char **charArray -- (output) pointer to a pointer that refer to the newly allocated memory and upon return
//                        will contain all the letters from the string word parameter + null terminating character
// Returns:
//    Length of the string (not including null character)
// 
// Notes:
//    Caller is responsible for deleting memory allocated by this function  
//
int convertStringCharArray(string word, char** charArray)
{
    size_t len = word.length();

    //
    // Dynamically allocate memory to store all the letters from word
    // into a "new" array of chars
    // Be sure to allocate 1 extra byte for the '\0' null string character terminator
    //

    /* Add your code here that uses the new operator to create a dynamic array */
	char* newDynamicArray = new char[len + 1];
	char* tempPointer = newDynamicArray;

    // I MADE A "TEMP" POINTER BECAUSE IF I USE THE FIRST ONE, IT WILL CAUSE MEMORY ISSUES

    /* Add your code here that uses a for loop to copy all the letters from the word string variable */
    /* to the dynamically allocated array.  Note to get full points you must use a single statement */
    /* with the pointer increment operator (++) and the deference '*' operator */
    for (int i = 0; i < len; i++) {
        *(tempPointer++) = word[i];
    }

    /* Add your code here to add a '\0' string null terminator to the end of the dynamically allocated array*/
    *tempPointer = '\0';

    /* Add your code here to set the charArray output parameter */
    *charArray = newDynamicArray;
    return len;
}


//
// deallocateMemory()
//
// Purpose:
//    returns the memory used by the dynamic array produced by the convertStringCharArray function
// 
// Parameters:
//    char *arr -- pointer to the dynamically allocated array
// 
// Returns:
//    void
//
// remember you must use delete[] (not just delete) when deleting dynamic arrays
//
void deallocateMemory(char* arr)
{
    /* Add your code here the returns the memory referenced by the dyanamically allocated array */
    /* passed in as the (arr) parameter */

    // remember the delete[] operator (with the []) must be used to release memory allocated to a dynamic array
    delete[] arr;
}

//
// printCharArray()
//
// Purpose:
//    Demonstrate the use of pointer arithmetic to traverse the dynamically allocated
//    by printing all the characters in the array forward and backwards
// 
// Parameters:
//    char *arr -- pointer to the dynamically allocated array
// 
// Returns:
//    void
//
void printCharArray(char* arr)
{
    // note to receive credit for this part, your code cannot use the index [] operator

    // print the contents of the array in the forward direction
    char* p = arr;
    while (*p)
    {
        cout << *p++;
    }

    p--;   // move back to the last character (p was previously pointing to the null terminator)

    cout << endl;

    while (p != arr)
    {
        /* add your code here the prints out the characters in reverse order pointed by p */
        /* after printing the character pointed to by p, decrement p to move the previous character*/
        cout << *(p--);
    }
    cout << *p << endl;  // print the first character
}

int main()
{
    string s;
    char* charArray = nullptr;

    getWord(&s);
    convertStringCharArray(s, &charArray);
    printCharArray(charArray);
    deallocateMemory(charArray);
}
