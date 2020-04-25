#include <iostream>

using namespace std;

struct Equipment {
    char ID[3];
    int level_array[3];
};

int main() {
    Equipment equipment[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            equipment[i].ID[j] = (char) ('0' + i + j);
//            equipment[i].ID[j] = (char) 48 + i + j;
            equipment[j].level_array[i] = i + j;
        }
    cout << equipment[0].ID[1] << equipment[1].level_array[2] << equipment[2].ID[0];

    cout << endl;

    cout << equipment[0].ID << endl;
    cout << equipment[1].ID << endl;
    cout << equipment[2].ID << endl;

    return 0;
}