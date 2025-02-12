#include <iostream>
#include <string.h>

using namespace std;

char* reverseString(char* src) {
    int len = strlen(src);
    
    char* buf = new char[len + 1];
    char* srcPtr = src + len - 1;
    char* dstPtr = buf;

    for (int i = 0; i < len; i++) {
        *(dstPtr++) = *(srcPtr--);
    }

    *dstPtr = '\0'; // null terminator
    return buf;
}

int main(int argc, char *argv[]) {
    char* p = reverseString(argv[1]);
    cout << p << endl;

    delete[] p;
    p = nullptr;
}
