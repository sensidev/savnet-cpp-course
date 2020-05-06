#include <iostream>
#include <fstream>

using namespace std;

#define MATRIX_MAX_SIZE 2

class MatrixContainer {
private:
    int matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE] = {};

    const char *in_path = "/tmp/savnet_in.txt";
    const char *out_path = "/tmp/savnet_out.txt";
public:
    MatrixContainer() {};

    void read_from_file() {
        string in;
        ifstream in_file;
        in_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            in_file.open(this->in_path, ios::in);

            for (unsigned int i = 0; i < MATRIX_MAX_SIZE; i++) {
                for (unsigned int j = 0; j < MATRIX_MAX_SIZE; j++) {
                    getline(in_file, in);
                    this->matrix[i][j] = stoi(in);
                }
            }
            in_file.close();
        } catch (ifstream::failure &e) {  // narrow exception
//        } catch (exception &e) {  // broad exception
            cout << "Could not read from file! Reason: " << e.what() << endl;
            throw e;
        }
    };

    void write_to_file() {
        ofstream out_file;
        out_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            out_file.open(this->out_path, ios::out);

            for (unsigned int i = 0; i < MATRIX_MAX_SIZE; i++) {
                for (unsigned int j = 0; j < MATRIX_MAX_SIZE; j++) {
                    // Alternative:
                    // out_file << this->matrix[i][j] << endl;
                    string s = to_string(this->matrix[i][j]) + '\n';
                    out_file.write(s.c_str(), 10);
                }
            }
            out_file.close();
        } catch (ofstream::failure &e) {
            cout << "Could not write to file! Reason: " << e.what() << endl;
            throw e;
        }
    };

    void print_matrix() {
        for (unsigned int i = 0; i < MATRIX_MAX_SIZE; i++) {
            for (unsigned int j = 0; j < MATRIX_MAX_SIZE; j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    MatrixContainer container;

    container.read_from_file();
    container.write_to_file();
    container.print_matrix();

    return 0;
}