#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "class.h"

// NAMESPACES
using namespace std;

// CHANGE THIS TO TRUE TO USE THE TEST CODE, FALSE TO USE ARGUMENTS FROM TERMINAL
bool debugMode = false;

// MAIN
int main(int countOfArguments, char* arguments[]) {
    if (!debugMode) {
        if (countOfArguments != 2) {
            cout << "ERROR: You have to include a single argument!";
            return 1;
        }

        // OPEN FILE
        string fileName = arguments[1];
        ifstream file(fileName);

        // ENSURE FILE OPENED SUCCESSFULLY
        if (!file.is_open()) {
            cout << "Error: Could not open file " << fileName << endl;
            return 1;
        }

        // GO THROUGH EACH LINE OF THE FILE
        GenericBinarySearchTree<string> tree;
        string word;

        // ADD EACH WORD TO THE TREE AND CLOSE THE FILE WHEN FINISHED
        while (getline(file, word)) {
            tree.AddItem(word);
        }
        file.close();

        // PRINT OUT PRE-ORDER AND IN-ORDER TRAVERSALS
        cout << "***** PreOrder: *****" << endl;
        tree.PreOrder();

        cout << "***** InOrder: *****" << endl;
        tree.InOrder();

        // ALLOW THE USER TO SEARCH FOR A WORD
        string query;
        while (true) {
            cout << "Enter word to search for, or 'q' to quit --> ";
            cin >> query;

            // SEARCH FOR THE WORD IN THE TREE AND IF IT IS FOUND, PRINT OUT A MESSAGE
            if (query != "q") {
                cout << query << (tree.FindItem(query) ? " is in the tree" : " is not in the tree") << endl;
            } else {
                break;
            }
        }

        // DELETE POST-ORDER NODES AND END PROGRAM
        tree.DeletePostOrderNodes();
    } else {
        vector<int> numbers(1000);
        for (int i = 0; i < 1000; i++) {
            numbers[i] = i;
        }

        // ASSIGN A RANDOMIZER SEED SO WE CAN CORRECTLY TEST, THEN SWAP VALUES IN THE ARRAY
        srand(100);
        for (int i = 0; i < 1000; i++) {
            swap(numbers[i], numbers[rand() % 1000]);
        }

        // CREATE A TREE BUT WITH AN INTEGER TEMPLATE AND THEN ADD NUMBERS
        GenericBinarySearchTree<int> tree;
        for (int num : numbers) {
            tree.AddItem(num);
        }

        // ENSURE THAT ALL NUMBERS EXIST BY TRYING TO FIND THEM IN THE TREE
        for (int i = 0; i < 1000; i++) {
            if (!tree.FindItem(i)) {
                cout << "Error: " << i << " not found!" << endl;
			} else {
				cout << "We found " << i << "!" << endl;
            }
        }

		// REMOVE 10 RANDOM NUMBERS AND THEN DO AN IN-ORDER TRAVERSAL TO VERIFY
        for (int i = 0; i < 10; i++) {
			int randomNumber = numbers[rand() % 1000];
            tree.RemoveItem(randomNumber);
			cout << "Removed " << randomNumber << " from node." << endl;
        }
        tree.InOrder();
    }
    return 0;
}
