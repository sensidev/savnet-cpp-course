#include "iostream"
#include "match_making_service.h"

MatchMakingService *MatchMakingService::instance = nullptr;
// Person *pointer; - analogy

MatchMakingService::MatchMakingService(ProfileDatabase *database_pointer) {
    this->database_pointer = database_pointer;
}

MatchMakingService *MatchMakingService::get_instance(ProfileDatabase *database_pointer) {
    if (nullptr == instance) {
        instance = new MatchMakingService(database_pointer);
    }

    return MatchMakingService::instance;
}

/**
 *  Matching given profile with the profile database.
 *  Algorithm:
 *  - if in the same city and country,
 *  - if in +/- 5 years old diff,
 *  - if has at least 2 hobbies in common.
 * @param profile the profile to match
 * @return vector of matched profiles
 */
vector<Profile> MatchMakingService::match(Profile profile) {
    vector<Profile> matches = {};

    unsigned int number_of_profiles = this->database_pointer->get_count();

    for (int i = 0; i < number_of_profiles; i++) {
        Profile p = this->database_pointer->get_profile(i);

        if (!p.is_same_country(profile)) {
            break;
        }

        if (!p.is_same_city(profile)) {
            break;
        }

        if (!p.is_age_close_to(profile, 5)) {
            break;
        }

        if (!p.has_same_hobbies(profile, 2)) {
            break;
        }

        matches.push_back(p);
    }

    return matches;
}