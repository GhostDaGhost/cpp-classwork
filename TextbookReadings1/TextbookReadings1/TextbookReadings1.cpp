#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

string months[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

static void PerformTemperatureConversions() {
    cout << "------------------\n";
    cout << "Exercise 1.1\n";
    cout << "------------------\n";

    //////////////////////////////
    // FAHRENHEIT TO CELSIUS
    // ///////////////////////////
    // ORIGINAL TEMPERATURE AND THE FORMULA FROM THE TEXTBOOK
    int fahrenheitTempterature = 41;
    int newCelsiusTemperature = (fahrenheitTempterature - 32) * 5 / 9;

    // OUTPUT THE ORIGINAL TEMPERATURE AND THE CONVERSION BELOW IT.
    cout << "Temperature in Fahrenheit: " << fahrenheitTempterature << endl;
    cout << fahrenheitTempterature << " degrees Fahrenheit = " << newCelsiusTemperature << " degrees Celsius\n";

    // DIVIDER
    cout << "-\n";

    //////////////////////////////
    // CELSIUS TO FAHRENHEIT
    // ///////////////////////////
    // ORIGINAL TEMPERATURE AND THE FORMULA FROM THE TEXTBOOK
    int celsiusTemperature = 5;
    int newFahrenheitTemperature = (celsiusTemperature * 9 / 5) + 32;

    // OUTPUT THE ORIGINAL TEMPERATURE AND THE CONVERSION BELOW IT.
    cout << "Temperature in Celsius: " << celsiusTemperature << endl;
    cout << celsiusTemperature << " degrees Celsius = " << newFahrenheitTemperature << " degrees Fahrenheit\n";
}

static void Exercise2_7() {
    cout << "------------------\n";
    cout << "Exercise 2.7\n";
    cout << "------------------\n";

    double d = 2 * int(3.14);
    long k = 3.14 - 3;
    char c = 'a' + 2;
    char c2 = 'p' + 'A' - 'a';
    cout << "d: " << d << endl;
    cout << "k: " << k << endl;
    cout << "c: " << c << endl;
    cout << "c2: " << c2 << endl;
}

static void Exercise2_9() {
    cout << "------------------\n";
    cout << "Exercise 2.9\n";
    cout << "------------------\n";

    // INITIALIZE VARIABLES AND ASK FOR INPUT
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    // CHECK IF NUMBERS ARE SORTED
	cout << ((num1 <= num2 && num2 <= num3) ? "The three numbers ARE sorted." : "The three numbers are NOT sorted.") << endl;
}

static void Exercise3_11() {
    cout << "------------------\n";
    cout << "Exercise 3.11\n";
    cout << "------------------\n";

    int n = 20;
    if (n >= 0) {
        if (n < 10) {
            cout << "n is small\n";
        } else {
            cout << "n is negative\n";
        }
    }
}

static void Exercise3_12() {
    cout << "------------------\n";
    cout << "Exercise 3.12\n";
    cout << "------------------\n";

    // ASK FOR USER INPUT A DATE IN THE (DD/MM/YY) FORMAT
    string inputDate;
	cout << "Enter a date in the format (DD/MM/YY): ";
    cin >> inputDate;

    // INITIALIZE DAY, MONTH AND YEAR VARIABLES AND DO STRING STREAM
    unsigned int day, month, year;
    char delimiter;
    stringstream ss(inputDate);

	// OUTPUT THE DATE IN THE APPROPRIATE FORMAT
    ss >> day >> delimiter >> month >> delimiter >> year;
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

static void Exercise3_14() {
    cout << "------------------\n";
    cout << "Exercise 3.14\n";
    cout << "------------------\n";

    // ASK FOR USER INPUT (I WILL ADMIT THIS FUNCTION WAS HARD TO FIGURE OUT BUT I CAN'T GET THE ACTUAL OUTPUT RIGHT)
    string octalNumber;
    cout << "Input an octal number: ";
    cin >> octalNumber;

    // START CONVERTING OCTAL TO DECIMAL
    int decimalNumber = 0;
    for (char digit : octalNumber) {
        decimalNumber = decimalNumber * 8 + (digit - '0');
    }

    // OUTPUT FINAL MESSAGE
    cout << "Octal(" << octalNumber << ") = Decimal(" << decimalNumber << ")" << endl;
}

static void Exercise3_15() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
    }
}

int main() {
    PerformTemperatureConversions();
    cout << "------------------\n";
    cout << "Exercise 2.5\n";
    cout << "------------------\n";

    //////////////////////////////
    // Exercise 2.5
    // ///////////////////////////
    // 1.
    unsigned int n = 2;
    cout << ((n % 2 == 0) ? "n is even!" : "n is somehow odd!") << endl;
 
    // 2.
    char c = '5';
    cout << (isdigit(c) ? "c is a digit!" : "c is not a digit!") << endl;

    // 3.
    cout << (isalpha(c) ? "c is a letter!" : "c is not a letter!") << endl;

    // 4.
    if (n % 1 == 0 && n > 0) {
        cout << "n is odd and positive." << endl;
    } else if (n % 2 == 0 && n < 0) {
        cout << "n is even and negative." << endl;
    }

    // 5.
    long f = 0;
    f |= (1L << n);
    cout << "After setting the " << n << "-th bit: " << f << endl;

    // 6.
    f &= ~(1L << n);
    cout << "After resetting the " << n << "-th bit: " << f << endl;

    // 7.
    double n2 = -3.21;
    cout << "Absolute value of " << n2 << " is " << abs(n2) << endl;

    // 8.
    const char* testText = "Hello, World!";
	cout << "Number of characters in " << testText << " is " << strlen(testText) << endl;

    //////////////////////////////
    // Exercise 2.7
    // ///////////////////////////
	Exercise2_7();

    //////////////////////////////
    // Exercise 2.9
    // ///////////////////////////
    Exercise2_9();

    //////////////////////////////
    // Exercise 3.11
    // ///////////////////////////
    Exercise3_11();

    //////////////////////////////
    // Exercise 3.12
    // ///////////////////////////
    Exercise3_12();

    //////////////////////////////
    // Exercise 3.14
    // ///////////////////////////
    Exercise3_14();

    //////////////////////////////
    // Exercise 3.15
    // ///////////////////////////
    Exercise3_15();

    // FINISH PROGRAM OFF
    return 0;
}
