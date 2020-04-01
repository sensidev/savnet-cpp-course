#include <iostream>

using namespace std;

bool isMatrixSymmetric(double matrix[4][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    bool isSymmetric = true;
    double matrix[4][4] = {
            {1, 2, 3, 4},
            {2, 2, 5, 1},
            {3, 5, 3, 2},
            {4, 1, 2, 4}
    };

    int n = 4;

    isSymmetric = isMatrixSymmetric(matrix, n);

    for (int line = 0; line < n; line++) {
        for (int column = 0; column < n; column++) {
            cout << matrix[line][column] << " ";
        }
        cout << endl;
    }

    cout << (isSymmetric ? "It is a symmetric matrix" : "It is not a symmetric matrix");

    return 0;

}


