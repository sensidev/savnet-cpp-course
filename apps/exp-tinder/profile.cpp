#include "profile.h"


Profile::Profile(string name, uint8_t age) {
    this->name = name;
    this->age = age;
}


void Profile::set_city(string city) {
    this->city = city;
}

void Profile::set_country(string country) {
    this->country = country;
}

void Profile::set_nickname(string nickname) {
    this->nickname = nickname;
}

void Profile::add_hobby(string hobby) {
    this->hobbies.push_back(hobby);
}

string Profile::get_profile() {
    string profile =
            "My name is " + this->name + "\n" + "I am " + to_string(this->age) + " years old. \n" +
            "My nickname is " + this->nickname + ". \n" +
            "I am from " + this->city + ", " + this->country + ".\n" +
            "And my hobbies are: ";

    for (const string& hobby: hobbies) {
        profile += hobby + " ";
    }

    return profile;
}