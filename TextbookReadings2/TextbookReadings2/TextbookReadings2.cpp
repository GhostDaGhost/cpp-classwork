#include <iostream>
#include <stdarg.h>

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

// ON INITIALIZATION
int main() {
    const Month numberOfMonth = Month::August;
    cout << "The month is: " << GetNameOfMonth(numberOfMonth) << " (" << numberOfMonth << ")" << endl;

	// SUM OF REAL VALUE LIST
	cout << "Sum of 1.0, 2.0, 3.0, 4.0, 5.5: " << Sum(5, 1.0, 2.0, 3.0, 4.0, 5.5) << endl;

    // END THE PROGRAM
    return 0;
}
