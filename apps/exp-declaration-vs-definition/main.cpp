#include <iostream>

using namespace std;

// declaration with parameters - "politician", "prototype".
void func(int x);

int main() {
    int x = 123;

    // x - argument.
    func(x);  // call the function func, before being defined.

    return 0;
}

// define with parameters
void func(int x) {
    cout << x;
}
