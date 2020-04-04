#include <iostream>

using namespace std;

int main() {
    unsigned long x;
    unsigned int bitCount = 0;

    cin >> x;

    cout << "Size of unsigned long: " << sizeof(x) << endl;

    for (unsigned int bits = 0; x != 0; bits++) {
        if (x & 1u) {
            bitCount += 1;
        }

        x = x >> 1u;
    }

    cout << "Bit count: " << bitCount;

    return 0;
}