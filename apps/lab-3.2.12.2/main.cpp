#include <iostream>

using namespace std;

int main() {
    int matrix[10][10] = {};

    for (int lineIndex = 0; lineIndex < 10; lineIndex++) {
        int *linePointer = matrix[lineIndex];

        //continutul pointerului va fii setat cu lineIndex + 1
        *linePointer = lineIndex + 1;

        for (int colIndex = 0; colIndex < 9; colIndex++) {
            int *lineCurrItemPointer = linePointer + colIndex;
            int *lineNextItemPointer = linePointer + colIndex + 1;
            *lineNextItemPointer = *lineCurrItemPointer + *linePointer;

            if(linePointer == lineCurrItemPointer) {
                cout << "Match line with current item on line "<< lineIndex << " and col " <<colIndex << endl;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}