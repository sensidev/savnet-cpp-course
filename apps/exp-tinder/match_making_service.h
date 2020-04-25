#ifndef SAVNET_CPP_MATCH_MAKING_SERVICE_H
#define SAVNET_CPP_MATCH_MAKING_SERVICE_H

#include "profile.h"
#include "profile_database.h"

class MatchMakingService {
private:
    ProfileDatabase *database_pointer;

    /* Here will be the instance stored. */
    static MatchMakingService *instance;

    /* Private constructor to prevent instancing. */
    MatchMakingService(ProfileDatabase *database_pointer);

public:
    /* Static access method. */
    static MatchMakingService *get_instance(ProfileDatabase *database_pointer);

    vector<Profile> match(Profile profile);
};


#endif
