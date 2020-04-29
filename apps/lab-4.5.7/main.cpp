#include <string>
#include <iostream>

using namespace std;

#define CORRECT 0b00000u
#define LENGTH_ERROR 0b00001u
#define NO_UPPERCASE_ERROR 0b00010u
#define NO_LOWERCASE_ERROR 0b00100u
#define NO_DIGIT_ERROR 0b01000u
#define NO_SPECIAL_ERROR 0b10000u


string valid_special_chars = "~!@#$%^&*()_+=<>";

static unsigned int validate(const string &password);

/**
 * be eight characters long;
 * have at least one upper-case letter;
 * have at least one lower-case letter;
 * have at least one digit;
 * have at least one special character.
 * @return
 */
int main() {
    unsigned int error;

    string password;
    std::getline(cin, password);

    error = validate(password);

    if (error & LENGTH_ERROR) {
        cout << "The password is not 8 chars long. It is " << password.size() << endl;
    }

    if (error & NO_UPPERCASE_ERROR) {
        cout << "The password does not have an uppercase" << endl;
    }

    if (error & NO_LOWERCASE_ERROR) {
        cout << "The password does not have a lowercase" << endl;
    }

    if (error & NO_DIGIT_ERROR) {
        cout << "The password does not have a digit" << endl;
    }

    if (error & NO_SPECIAL_ERROR) {
        cout << "The password does not have a special char" << endl;
    }

    if (error == CORRECT) {
        cout << "The password is correct :) " << endl;
    }


    return 0;
}

static unsigned int validate(const string &password) {
    unsigned int ret_error = CORRECT;

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    if (password.size() != 8) {
        ret_error |= LENGTH_ERROR;
    }

    for (const char &letter:password) {
        if (isupper(letter)) {
            has_upper = true;
        }

        if (islower(letter)) {
            has_lower = true;
        }

        if (isdigit(letter)) {
            has_digit = true;
        }

        if (string::npos != valid_special_chars.find(letter)) {
            has_special = true;
        }
    }

    if (!has_upper) {
        ret_error |= NO_UPPERCASE_ERROR;
    }

    if (!has_lower) {
        ret_error |= NO_LOWERCASE_ERROR;
    }

    if (!has_digit) {
        ret_error |= NO_DIGIT_ERROR;
    }

    if (!has_special) {
        ret_error |= NO_SPECIAL_ERROR;
    }

    return ret_error;
}
