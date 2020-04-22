#ifndef SAVNET_CPP_PROFILE_H
#define SAVNET_CPP_PROFILE_H

#include <string>
#include <vector>

using namespace std;

class Profile {
private:
    string name;
    uint8_t age;
    string city;
    string country;
    string nickname;
    vector<string> hobbies;

public:
    Profile(string name, uint8_t age);

    void set_city(string city);
    void set_country(string country);
    void set_nickname(string nickname);

    void add_hobby(string hobby);

    string get_profile();
    string get_profile_preview();
};

#endif
