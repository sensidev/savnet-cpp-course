#include "profile_database.h"
#include "iostream"

static vector<string> name_choices = {
        "Gigi", "Ionut", "Bogdan", "Isabella", "Luna", "Madara", "Hagi", "Mirabela", "Suzana", "Lulu", "Diana"
};

static vector<string> hobbies_choices = {
        "Fotbal", "Tennis", "Squash", "Șah", "PingPong", "Trading", "Paintball", "Softball", "Climbing", "Gaming"
};

static vector<CountryCity> country_city_choices = {
        {"Romania", "Timișoara"},
        {"Romania", "Arad"},
        {"Romania", "Constanța"},
        {"Romania", "Craiova"},
        {"Romania", "Cluj"},
        {"Romania", "BăiCoi"},
        {"Romania", "Sculea"},
        {"Romania", "Suceava"},
        {"Romania", "Iași"},
        {"Ungaria", "Budapest"},
        {"Ungaria", "Szeged"},
        {"Ungaria", "Makó"},
        {"Austria", "Ischl"},
        {"Austria", "Viena"},
        {"Austria", "Linz"},
        {"Austria", "Graz"},
};


static unsigned int get_random_number(unsigned int from, unsigned int to, int seed) {
    srand(seed);
    return from + int(random() % (to - from + 1)); // range from - to
}

ProfileDatabase::ProfileDatabase(unsigned int number_of_profiles) {
    for (int i = 0; i < number_of_profiles; i++) {
        this->add_new_random_profile(i);
    }
}

void ProfileDatabase::add_new_random_profile(int seed) {
    unsigned int random_index;

    random_index = get_random_number(0, name_choices.size() - 1, ++seed);
    string random_name = name_choices[random_index];

    uint8_t random_age = get_random_number(16, 50, ++seed);

    Profile profile(random_name, random_age);

    random_index = get_random_number(0, country_city_choices.size() - 1, ++seed);
    profile.set_city(country_city_choices[random_index].city);
    profile.set_country(country_city_choices[random_index].country);

    unsigned int random_id = get_random_number(0, 99, ++seed);
    string random_nickname = random_name.substr(0, 3) + to_string(random_id);

    profile.set_nickname(random_nickname);

    unsigned int number_of_hobbies = get_random_number(1, 5, ++seed);
    for (int hobby_number = 0; hobby_number < number_of_hobbies; hobby_number++) {
        random_index = get_random_number(0, hobbies_choices.size() - 1, ++seed);
        profile.add_hobby(hobbies_choices[random_index]);
    }

    profiles.push_back(profile);

}

void ProfileDatabase::show_all_profile_previews() {
    for (Profile profile: this->profiles) {
        cout << profile.get_profile_preview() << endl;
    }
}

Profile ProfileDatabase::get_profile(unsigned int index) {
    return this->profiles[index];
}

unsigned int ProfileDatabase::get_count() {
    return this->profiles.size();
}
