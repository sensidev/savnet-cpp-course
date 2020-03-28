#include <iostream>

using namespace std;

int main() {
    int year = 0;

    cout << "Enter a year: ";
    cin >> year;

    bool isCommonYear = year % 4 != 0;

    if (isCommonYear) {
        cout << "It is a common year";
    } else {
        bool isLeapYear = year % 100 != 0;

        if (isLeapYear) {
            cout << "It is a leap year";
        } else {
            isCommonYear = year % 400 != 0;

            if (isCommonYear) {
                cout << "It is a common year";
            } else {
                cout << "It is a leap year";
            }
        }
    };

    return 0;
}