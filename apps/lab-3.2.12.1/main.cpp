#include "iostream"
#include "climits"

using namespace std;

int main() {
    int a[] = {3, -5, 7, 10, -4, -14, 5, 2, -13};
    int n = sizeof(a) / sizeof(int);

    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        int *p = a + i;

        if (*p < min) {
            min = *p;
        }
    }

    cout << min;

    return 0;
}