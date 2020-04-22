#include <iostream>

using namespace std;

int main() {
    unsigned int len;
    // allocate array with size 3
    char other_array[3];

    // declare an array as a pointer, not knowing the size from beginning
    char *some_array;
    // ... do something
    cout << "Give me a length: ";
    cin >> len;
    // figure out that you need array with size 3, and allocate it.
    some_array = new char(len);  // allocate memory for `len` chars.

    for (int i = 0; i < len; i++) {
        char *pointer = some_array + i;  // use pointer to access each array item
        *pointer = (char) (65 + i);  // fill up the content where the `pointer` points

        // alternative, use indexes:
        // some_array[i] = (char) (65 + i);
    }

    // ... do something useful with this array, maybe?

    cout << endl;

    for (uint8_t i = 0; i < len; i++) {
        cout << some_array[i];
    }

    cout << endl;

    return 0;
}

