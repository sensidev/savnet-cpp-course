#include "iostream"
#include "profile.h"

/*
 * Dating app - Tinder in C++
 * https://pastebin.com/TLFT76Ls
 *
 *
 * Homework:
 *  - think about a predefined "database" of profiles
 *  - create a new profile from stdin
 *  - get a match:
 *      - No match.
 *      - You have # matches. (print profiles).
 *
 *  Algorithm:
 *  - if in the same city and country,
 *  - if in +/- 5 years old diff,
 *  - if has at least 2 hobbies in common.
 */
int main() {
    string city;


    cout << "City: ";
    cin >> city;

    Profile p("Gică", 14);

    p.set_city(city);
    p.set_country("Romania");
    p.set_nickname("Contra");

    p.add_hobby("Fishing");
    p.add_hobby("Ski");
    p.add_hobby("Snowboarding");

    cout << p.get_profile();
}