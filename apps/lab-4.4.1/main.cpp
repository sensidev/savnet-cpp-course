#include <iostream>

using namespace std;

#define ALPHABET_LETTER_COUNT 26

static void experiment_with_string_vs_arrays();

static char get_letter_from(unsigned int index);

static unsigned int get_index_from(char letter);

int main() {
//  experiment_with_string_vs_arrays();
//  cout << (char) (7 + 'a') << endl;  // number to letter conversion
//  cout << 'g' - 'a' << endl; // letter to number conversion

    string input;

    getline(cin, input);

    unsigned int count_map[ALPHABET_LETTER_COUNT] = {};  // considering 'a' = 0 - index and 'z' = 34 - index

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (char &letter : input) {
        if ('a' <= letter && letter <= 'z') {
            unsigned int map_index = get_index_from(letter);
            count_map[map_index]++;
        }
    }

    bool is_pangram = true;

    for (unsigned int map_index = 0; map_index < ALPHABET_LETTER_COUNT; map_index++) {
        char letter = get_letter_from(map_index);
        cout << letter << " - " << count_map[map_index] << endl;

        if (count_map[map_index] == 0) {
            is_pangram = false;
        }
    }

    cout << (is_pangram ? "It is a pangram" : "it is NOT a pangram");

    return 0;
}

static char get_letter_from(unsigned int index) {
    return (char) (index + 'a');
}

static unsigned int get_index_from(char letter) {
    return letter - 'a';
}


static void experiment_with_string_vs_arrays() {
    string a_string = "Some string here to be placed";

    const char *a_char_array = "A char array";
    char another_array[20] = "Another char array";
    int an_int_array[10] = {1, 2, 3, 4, 5};

    cout << a_string[0] << endl;
    cout << "A string size: " << a_string.size() << endl;

    cout << a_char_array[0] << endl;
    cout << another_array[0] << endl;
    cout << an_int_array[0] << endl;
}