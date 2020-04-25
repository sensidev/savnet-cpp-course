#ifndef SAVNET_CPP_PROFILE_DATABASE_H
#define SAVNET_CPP_PROFILE_DATABASE_H

#include "profile.h"

struct CountryCity {
    string country;
    string city;
};

class ProfileDatabase {
private:
    vector<Profile> profiles;
    void add_new_random_profile(int seed);

public:
    ProfileDatabase(unsigned int number_of_profiles);

    void show_all_profile_previews();
    unsigned int get_count();
    Profile get_profile(unsigned int index);
};


#endif
