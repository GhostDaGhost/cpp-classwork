#include <iostream>
#include <sstream>
#include <fstream>

#include "structs.h"
#include <string>
#include <vector>

// NAMESPACES
using namespace std;

// LINKED LIST INITIALIZATION
TimeNode* head[30] = { nullptr };

// LINKED LIST INSERTION
static TimeNode* insertIntoList(double startTime, string& day, string& studentName, TimeNode*& head) {
	//cout << "Reading " << studentName << " for day " << day << " at " << startTime << endl;
    TimeNode* current = head;
    while (current) {
        if (current->startTime == startTime && current->day == day) {
            //cout << "Time and day already made - Adding " << studentName << " to day " << day << " at " << startTime << endl;
            current->names.push_back(studentName);
            current->numberOfStudents++;
            return current;
        }
        current = current->next;
    }

    // CREATE NEW NODE
	//cout << "Adding " << studentName << " to day " << day << " at " << startTime << endl;
    TimeNode* newNode = new TimeNode(startTime, day);
    newNode->names.push_back(studentName);
    newNode->next = head;
    head = newNode;

    // RETURN NODE
    return newNode;
}

void displayList(int minimumStudents, TimeNode* head) {
    TimeNode* current = head;
    while (current) {
        if (current->numberOfStudents >= minimumStudents) {
            cout << "day " << current->day << " at " << current->startTime << " was chosen by ";
            for (string& student : current->names) {
                cout << student << " ";
            }
            cout << endl;
        }
        current = current->next;
    }
}

int main() {
    while (true) {
        string userInput;
        cout << "Enter the file name to read or e to end --> ";
        cin >> userInput;

        // EITHER READ FILE OR END PROGRAM
        if (userInput == "e" || userInput == "E") {
            int minimumStudents;
            cout << "Enter the mininum number of students that must have chosen the same start time or 0 to exit --> ";
            cin >> minimumStudents;

			// EXIT PROGRAM IF USER INPUT IS INVALID
			if (minimumStudents <= 0) {
                cerr << "Error: minimum students is or below zero." << endl;
                return 1;
			}

            // DISPLAY LIST
            for (int i = 0; i < 15; ++i) {
                displayList(minimumStudents, head[i]);
            }
        } else {
            ifstream file(userInput);
            if (!file) {
                cerr << "Error: opening file " << userInput << endl;
                return 1;
            } else {
                string line;

                // GO THROUGH LINES OF FILE
                while (getline(file, line)) {
                    istringstream stream(line);
                    string day, temp;
                    vector<double> times;

                    // SOME FILES MIGHT HAVE SOME WEIRD SPACINGS, FIX IT HERE (THIS WAS REALLY CONFUSING AND HAD ME WONDERING WHY THE PROGRAM STALLED)
                    getline(stream, day, ':');
                    while (getline(stream, temp, ',')) {
                        temp.erase(0, temp.find_first_not_of(" \t\n\r"));
                        temp.erase(temp.find_last_not_of(" \t\n\r") + 1);
                        if (!temp.empty()) {
                            times.push_back(stod(temp));
                        }
                    }

                    // ITERATE THROUGH TIME SLOTS
                    for (double time : times) {
                        int dayIndex = -1;
                        if (day == "sun") dayIndex = 0;
                        else if (day == "mon") dayIndex = 1;
                        else if (day == "tue") dayIndex = 2;
                        else if (day == "wed") dayIndex = 3;
                        else if (day == "thu") dayIndex = 4;
                        else if (day == "fri") dayIndex = 5;
                        else if (day == "sat") dayIndex = 6;

                        // INSERT INTO THE LINKED LIST BELONGING TO THE DAY
                        if (dayIndex != -1) {
                            insertIntoList(time, day, userInput, head[dayIndex]);
                        }
                    }
                }

                // CLOSE FILE
                file.close();
            }
		}
    }
}
