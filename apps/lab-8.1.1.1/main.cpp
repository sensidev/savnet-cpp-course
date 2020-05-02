#include "iostream"

using namespace std;

#define MAX_STACK_LENGTH 100
#define MAX_MATRIX_LENGTH 2

typedef struct MatrixIndex {
    int row;
    int col;
} MatrixIndex_t;

/**
 * Last in, first out - stack type. LIFO.
 */
class ContainerStack {
private:
    int stack[MAX_STACK_LENGTH];
    int next_index = 0;

public:
    ContainerStack() {
    }

    void operator<<(int value) {
        this->stack[next_index] = value;
        next_index++;
    }

    void operator>>(int &value) {
        value = this->stack[next_index - 1];
        next_index--;
    }
};

class ContainerMatrix {
private:
    int matrix[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH] = {};
    MatrixIndex_t next_index = {0, 0};

public:
    ContainerMatrix() {
    }

    void operator<<(int value) {
        this->matrix[next_index.row][next_index.col] = value;

        // Small algorithm - think about an old writing machine.
        next_index.col++;
        if (MAX_MATRIX_LENGTH <= next_index.col) {
            next_index.col = 0;
            next_index.row++;
        }
    }

    void operator>>(string &value) {
        for (int row = 0; row < MAX_MATRIX_LENGTH; row++) {
            for (int col = 0; col < MAX_MATRIX_LENGTH; col++) {
                value += to_string(this->matrix[row][col]) + " ";
            }
            value += "\n";
        }
    }
};

int main() {
    int input;
    string output;

    ContainerMatrix container;

    int step = 0;
    do {
        cin >> input;
        container << input;

        step++;
    } while (MAX_MATRIX_LENGTH * MAX_MATRIX_LENGTH > step);

    container >> output;
    cout << output << endl;

    return 0;
}