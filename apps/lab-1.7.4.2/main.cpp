#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main(void) {
    int i1, i2;

    double x1;
    double x2;

    cout << "i1 = ";
    cin >> i1;

    cout << "i2 = ";
    cin >> i2;

    x1 = 1.0 / (double) i1;
    x2 = 1.0 / (double) i2;

    bool areFloatsEqual = fabs(x1 - x2) < 0.00001;

    if (areFloatsEqual) {
        cout << "Results are equal (by 0.000001 epsilon)" << endl;
    } else {
        cout << "Results NOT are equal (by 0.000001 epsilon)" << endl;
    }

    // alternative
    if (x1 * 1000000 == x2 * 1000000) {
        cout << "ALTERNATIVE Results are equal (by 0.000001 epsilon)" << endl;
    } else {
        cout << "ALTERNATIVE Results NOT are equal (by 0.000001 epsilon)" << endl;
    }

    return 0;
}