#include <iostream>
#include <vector>

// NAMESPACES
using namespace std;

// STRUCTURES
struct TimeNode {
    double startTime;
    string day;
    int numberOfStudents;
    vector<string> names;

    // CONSTRUCTOR
    TimeNode* next;
    TimeNode(double time, string& d) : startTime(time), day(d), numberOfStudents(1), next(nullptr) {}
};
