#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ListNode {
    string data;
    ListNode* next;
    ListNode(string w) : data(w), next(nullptr) {};
};

static int getSizeOfNode(ListNode* myList) {
    if (myList == NULL) {
        return 0;
    }
    return 1 + getSizeOfNode(myList->next);
}

static void displayList(ListNode* myList) {
    if (myList != NULL) {
        cout << myList->data << " ";
        displayList(myList->next);
    }
}

static void displayReverseList(ListNode* myList) {
	if (myList != NULL) {
		displayReverseList(myList->next);
		cout << myList->data << " ";
	}
}

static void insertIntoSortedList(ListNode* &head, string word) {
    ListNode* newHead = new ListNode(word);
    if (!head || word < head->data) {
        newHead->next = head;
        head = newHead;
        return;
    }

    ListNode* currentHead = head;
    while (currentHead->next && currentHead->next->data < word) {
        currentHead = currentHead->next;
    }

    newHead->next = currentHead->next;
    currentHead->next = newHead;
}

int main(int argumentCount, char* arguments[]) {
	if (argumentCount != 2) {
		cout << "Usage: <filename>" << endl;
		return 1;
	}

    // OPEN FILE AND CATCH ANY ERRORS
    ifstream file(arguments[1]);
    if (!file) {
        cout << "There was an error opening this file!" << endl;
    }

    // CREATE EMPTY LIST
    ListNode* head = nullptr;
    string wordInList;

    // ITERATE THROUGH FILE'S WORDS
	cout << "Words in file: ";
    while (file >> wordInList) {
        cout << wordInList << " ";
        insertIntoSortedList(head, wordInList);
    }

    // CLOSE FILE
    file.close();

    // SHOW LIST IN ORDER
    cout << "\nSize of list: " << getSizeOfNode(head) << endl;
	cout << "List in ALPHABETICAL order: ";
    displayList(head);

    // SHOW LIST IN REVERSE ORDER
	cout << "\nList in REVERSE order: ";
	displayReverseList(head);
}
