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
    // Constructor
    // - has the same name as the class
    // - auto-calls when you instantiate (create an object)
    Profile(string name, uint8_t age);

    void set_city(string city);

    void set_country(string country);

    void set_nickname(string nickname);

    bool is_same_city(Profile other);

    bool is_same_country(Profile country);

    bool is_age_close_to(Profile other, unsigned int delta);

    bool has_same_hobbies(Profile other, unsigned int how_many);

    void add_hobby(string hobby);

    string get_profile();

    string get_profile_preview();
};

#endif
