#include "iostream"
#include "match_making_service.h"

static vector<string> name_choices = {"Gigi", "Ionut", "Bogdan", "Isabella", "Luna", "Madara"};

static int get_random_number(int n, int seed) {
    srand(seed);
    return int(random() % n); // range 0 to n
}

MatchMakingService *MatchMakingService::instance = nullptr;
// Person *pointer; - analogy

MatchMakingService::MatchMakingService(unsigned int number_of_profiles) {
    for (int i = 0; i < number_of_profiles; i++) {
        this->add_new_random_profile(i);
    }
}

void MatchMakingService::add_new_random_profile(int seed) {
    int r = get_random_number(5, seed);
    string name = name_choices[r];
    Profile p(name, get_random_number(60, seed));

    profiles.push_back(p);
}

void MatchMakingService::show_all_profile_previews() {
    for (Profile profile: this->profiles) {
        cout << profile.get_profile_preview() << endl;
    }
}

MatchMakingService *MatchMakingService::get_instance(unsigned int number_of_profiles) {
    if (nullptr == instance) {
        instance = new MatchMakingService(number_of_profiles);
    }

    return MatchMakingService::instance;
}