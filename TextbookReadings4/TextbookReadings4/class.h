#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    string data;
    ListNode* next;
    ListNode(string w) : data(w), next(nullptr) {};
};

class CaseInsensitiveStringsList {
    public:
		ListNode* head;

		void AddString(string str) {
			ListNode* newNode = new ListNode(str);
			if (head == NULL) {
				head = newNode;
			} else {
				ListNode* current = head;
				while (current->next) {
					current = current->next;
				}
				current->next = newNode;
			}
        };

        bool FindString(string str) {
            ListNode* current = head;
            while (current) {
                if (current->data == str) { // MATCH FOUND
                    return true;
                }

                // KEEP GOING THROUGH THE LIST
                current = current->next;
            }
            return false;
        };

        void DisplayStrings() {
			ListNode* current = head;
            if (current != NULL) {
                while (current) {
                    cout << current->data << endl;
                    current = current->next;
                }
            }
        };

		bool RemoveString(string str) {
			ListNode* current = head;
			ListNode* previous = NULL;

			while (current) {
				if (current->data == str) {
					if (previous == NULL) {
						head = current->next;
					} else {
						previous->next = current->next;
					}

					delete current;
					return true;
				}

				previous = current;
				current = current->next;
			}
			return false;
        };
};
