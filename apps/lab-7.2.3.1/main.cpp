#include <iostream>

const int DivideByZero = 111;
using namespace std;

float internal_div(float arg1, float arg2) {
    if (0 == arg2)
        throw DivideByZero;
    return arg1 / arg2;
}

int main() {
    float r = 0.0, a, b;
    bool is_a_valid = false;

    do {
        cout << "a=";
        cin >> a;
        is_a_valid = a > 0;
        if (!is_a_valid) {
            cout << "Please give me a valid `a`" << endl;
        }
    } while (!is_a_valid);

    cout << "b=";
    cin >> b;

    try {
        r = internal_div(a, b);
        cout << "Div result: " << r << endl;
    } catch (...) {
        cout << "Are you kidding me?" << endl;
        cout << "Your input is not valid. You can't divide by zero." << endl;
    }
    return 0;
}