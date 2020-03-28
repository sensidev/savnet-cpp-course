#include <iostream>
#include <iomanip>
#include <ctgmath>

using namespace std;

int main(void) {
    float x1 = 12.3;
    float x2 = 12.3;
    float x3 = 12.123456;
    float x4 = 12.123456;
    float x5 = 12.193456;

    cout << fixed << setprecision(1) << x1 << endl;
    cout << fixed << setprecision(2) << x2 << endl;
    cout << fixed << setprecision(6) << x3 << endl;
    cout << fixed << setprecision(2) << x4 << endl;
    cout << fixed << setprecision(1) << x5 << endl;

    // alternative
    cout << "Alternative x5 " << round(x5 * 10) / 10 << endl;

    return 0;
}