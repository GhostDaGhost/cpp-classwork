#include <iostream>
#include <string>

using namespace std;

template<typename T>
T TemplateFunction(T var1, T var2) {
    return var1 + var2;
}

int main() {
    int x = 1;
    int y = 2;
    double x2 = 1.55;
    double y2 = 2.85;
    string x3 = "Hello";
    string y3 = " World";

    cout << "1: " << TemplateFunction(x, y) << endl;
    cout << "2: " << TemplateFunction(x2, y2) << endl;
    cout << "3: " << TemplateFunction(x3, y3) << endl;
}
