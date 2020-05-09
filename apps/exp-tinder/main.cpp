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
    ProfileDatabase database(1000);
    database.show_all_profile_previews();

    MatchMakingService *service_pointer = MatchMakingService::get_instance(&database);

    Profile me = create_my_profile();

    vector<Profile> matches = service_pointer->match(me);

    for (Profile &profile:matches) {
        cout << profile.get_profile();
    }

    cout << "You have " << matches.size() << " matches" << endl;
}

static Profile create_my_profile() {
    string name;
    cout << "Name: ";
    cin >> name;

    unsigned int age;
    cout << "Age: ";
    cin >> age;

    Profile my_profile(name, age);

    string nickname;
    cout << "Nickname: ";
    cin >> nickname;
    my_profile.set_nickname(nickname);

    string country;
    cout << "Country: ";
    cin >> country;
    my_profile.set_country(country);

    string city;
    cout << "City: ";
    cin >> city;
    my_profile.set_city(city);

    unsigned int hobby_count = 0;
    cout << "How many hobbies do you have? " << endl;
    cin >> hobby_count;

    for (unsigned int hobby_index = 0; hobby_index < hobby_count; hobby_index++) {
        string hobby;
        cin >> hobby;
        my_profile.add_hobby(hobby);
    }
    return my_profile;
}
