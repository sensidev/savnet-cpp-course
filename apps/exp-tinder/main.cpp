#include "iostream"
#include "profile.h"
#include "match_making_service.h"

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
    MatchMakingService *service_pointer = MatchMakingService::get_instance(10);
    cout << service_pointer << endl;

    service_pointer = MatchMakingService::get_instance(10);
    cout << service_pointer << " - You get the same instance because it is a singleton " << endl << endl;


    service_pointer->show_all_profile_previews();
}