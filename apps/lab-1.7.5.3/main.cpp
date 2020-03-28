#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main(void) {
    int value;

    unsigned short int ip[4];

    for (int i = 0; i < 4; i++) {
        // cin >> value;

        // alternative
        srand(i + time(NULL));
        value = 1 + rand() % 255; // range 1 - 255.

        if (0 < value && value < 255) {
            ip[i] = value;
        } else {
            cout << "Wrong number!";
            return 1;
        }
    }

    cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];

    return 0;
}