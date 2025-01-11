#include <iostream>

using namespace std;

int main() {
    cout << "Hello CSD 233! I'm Alex and I'm going to run a quick temperature conversion from Fahrenheit to Celsius.\n";

    // ORIGINAL TEMPERATURE AND THE FORMULA FROM THE TEXTBOOK
    int fahrenheitTempterature = 41;
    int convertedTemperature = (fahrenheitTempterature - 32) * 5 / 9;

    // OUTPUT THE ORIGINAL TEMPERATURE AND THE CONVERSION BELOW IT.
    cout << "Temperature in Fahrenheit: " << fahrenheitTempterature << endl;
    cout << fahrenheitTempterature << " degrees Fahrenheit = " << convertedTemperature << " degrees Celsius\n";
}
