#include <iostream>

using namespace std;

class MyCharString {
    private:
        char* bufP;
    public:
        MyCharString(string s) {
            bufP = new char[s.length() + 1];
            for (int i = 0; i <= s.length(); i++) {
                bufP[i] = s[i];
            }
        }

        MyCharString(const MyCharString &obj) {
            bufP = new char[strlen(obj.bufP) + 1];
            strcpy(bufP, obj.bufP);
            cout << "Copy constructor start" << endl;
            cout << "bufP: " << bufP << endl;
            cout << "obj.bufP: " << obj.bufP << endl;
            cout << "Copy constructor end" << endl;
        }

        MyCharString& operator=(const MyCharString &obj) {
            delete[] bufP;

            // MAKE A NEW BUFFER
            bufP = new char[strlen(obj.bufP) + 1];
            strcpy(bufP, obj.bufP);

            // OUTPUT AND RETURN OBJECT
            cout << "Assignment operator start" << endl;
            cout << "bufP: " << bufP << endl;
            cout << "obj.bufP: " << obj.bufP << endl;
            cout << "Assignment operator end" << endl;
            return *this;
        }

        ~MyCharString() {
            delete[] bufP;
            bufP = nullptr;
        }

        void display() {
            cout << bufP << endl;
        }
};

MyCharString f(string s) {
    MyCharString ms1(s);
    MyCharString ms2(ms1);
    return ms1;
}

int main() {
    string s = "Sandy";
    MyCharString v = f(s);
    v.display();

    MyCharString operatorStr("Hello");
    operatorStr = v;
    operatorStr.display();
}
