#ifndef SAVNET_CPP_MATCH_MAKING_SERVICE_H
#define SAVNET_CPP_MATCH_MAKING_SERVICE_H

#include "profile.h"

class MatchMakingService {
private:
    vector<Profile> profiles;

    /* Here will be the instance stored. */
    static MatchMakingService *instance;

    /* Private constructor to prevent instancing. */
    MatchMakingService(unsigned int number_of_profiles);

    void add_new_random_profile(int seed);

public:
    /* Static access method. */
    static MatchMakingService *get_instance(unsigned int number_of_profiles);

    void show_all_profile_previews();
};


#endif
