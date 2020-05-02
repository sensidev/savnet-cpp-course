#include <iostream>

double divide(int a, int b);

using namespace std;

struct DivideByZeroException : public exception {
    const char *what() const throw() {
        return "Divide by zero - my personal exception";
    }
};

int main() {
    int a = 8, b = 0;
    double result = 0;

    cin >> b;

    try {
        result = divide(a, b);
    } catch (DivideByZeroException &klm) {
        cout << klm.what() << endl;
    }
    cout << result << endl;

    return 0;
}

double divide(int a, int b) {
    if (b == 0) {
        throw DivideByZeroException();
    }
    return (double) a / b;
}
