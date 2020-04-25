#include "iostream"
#include "profile.h"
#include "match_making_service.h"
#include "profile_database.h"

static Profile create_my_profile();

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
    ProfileDatabase database(100);
    database.show_all_profile_previews();

    MatchMakingService *service_pointer = MatchMakingService::get_instance(&database);

    Profile me = create_my_profile();

    vector<Profile> matches = service_pointer->match(me);

    cout << matches.size();
}

static Profile create_my_profile() {
    string name;
    unsigned int age;

    cout << "Name: ";
    cin >> name;

    cout << "Age: ";
    cin >> age;

    Profile my_profile(name, age);

    // todo: add more stuff

    return my_profile;
}
