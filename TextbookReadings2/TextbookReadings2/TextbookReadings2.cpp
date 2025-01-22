#include <iostream>
#include <stdarg.h>
#include <cstring>

using namespace std;

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

// MONTH NAME GETTER
static const string GetNameOfMonth(const Month month = Month::August) {
    switch (month) {
        case Month::January:
            return "January";
        case Month::February:
            return "February";
        case Month::March:
            return "March";
        case Month::April:
            return "April";
        case Month::May:
            return "May";
        case Month::June:
            return "June";
        case Month::July:
            return "July";
        case Month::August:
            return "August";
        case Month::September:
            return "September";
        case Month::October:
            return "October";
        case Month::November:
            return "November";
        case Month::December:
            return "December";
        default:
            return "Invalid month! Please check input again.";
    }
}

// SUM OF REAL VALUE LIST GETTER
static const double Sum(int n, double val ...) {
    va_list args;
    va_start(args, val);

    // ITERATE THROUGH ARGUMENTS TO CALCULATE SUM
    double sumOfArguments = 0.0;
	for (int i = 0; i < n; i++) {
		sumOfArguments += va_arg(args, double);
	}

	// END ARGUMENT RUNTIME AND RETURN SUM
	va_end(args);
	return sumOfArguments;
}

// SHORTCUT FUNCTION FOR NAMES (REDUCES CODE :))
static void ProcessNames(char* names[], const int size, string type = "Read") {
	for (int i = 0; i < size; i++) {
		if (type == "Read") {
            cout << names[i] << endl;
		} else if (type == "Write") {
            char temp[100];

            // ASK FOR USER INPUT
            cout << "Enter name " << i + 1 << ": ";
            cin >> temp;

            // ALLOCATE MEMORY
            names[i] = new char[strlen(temp) + 1];
            strcpy_s(names[i], sizeof(names[i]), temp);
		}
	}
}

// READ NAMES
static void ReadNames(char* names[], const int size) {
    ProcessNames(names, size, "Read");
}

// WRITE NAMES
static void WriteNames(char* names[], const int size) {
	ProcessNames(names, size, "Write");
}

// BUBBLE SORT
static void BubbleSort(char* names[], const int size) {
    bool sorted = true;
    while (sorted) {
        sorted = false;
        for (int i = 0; i < size - 1; i++) {
            if (strcmp(names[i], names[i + 1]) > 0) {
                char* temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                sorted = true;
            }
        }
    }
}

// 5.28
static char* ReverseString(char* str) {
    size_t len = strlen(str);
    char* result = new char[len + 1];
    char* start = result;

    char* end = str + len - 1;
    while (end >= str) {
        *start++ = *end--;
    }

    *start = '\0';
    return result;
}

// BUBBLE SORT 5.29
static void RewrittenBubbleSort(char* names[], const int size, int (*compare)(const char*, const char*)) {
    bool sorted = true;
    while (sorted) {
        sorted = false;
        for (int i = 0; i < size - 1; i++) {
            if (compare(names[i], names[i + 1]) > 0) {
                char* temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                sorted = true;
            }
        }
    }
}

// ON INITIALIZATION
int main() {
    const Month numberOfMonth = Month::August;
    cout << "The month is: " << GetNameOfMonth(numberOfMonth) << " (" << numberOfMonth << ")" << endl;

	// SUM OF REAL VALUE LIST
	cout << "Sum of 1.0, 2.0, 3.0, 4.0, 5.5: " << Sum(5, 1.0, 2.0, 3.0, 4.0, 5.5) << endl;

    // END THE PROGRAM
    return 0;
}
