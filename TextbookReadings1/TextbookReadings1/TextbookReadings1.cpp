#include <iostream>

using namespace std;

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
        cout << "n is odd and positive.";
    } else if (n % 2 == 0 && n < 0) {
        cout << "n is even and negative.";
    }

    // 5.
    long f = 5;

    // 6.

    // 7.

    // 8.

    // FINISH PROGRAM OFF
    return 0;
}
