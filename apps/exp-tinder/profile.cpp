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

bool Profile::is_same_city(Profile other) {
    return this->city == other.city;
}

bool Profile::is_same_country(Profile other) {
    return this->country == other.country;
}

bool Profile::is_age_close_to(Profile other, unsigned int delta) {
    return this->age - delta <= other.age <= this->age + delta;
}

bool Profile::has_same_hobbies(Profile other, unsigned int how_many) {
    return true;  // todo, figure out a way to match `how_many` hobbies.
}

void Profile::add_hobby(string hobby) {
    this->hobbies.push_back(hobby);
}

string Profile::get_profile_preview() {
    return this->name + " " + to_string(this->age);
}

string Profile::get_profile() {
    string profile =
            "My name is " + this->name + "\n" + "I am " + to_string(this->age) + " years old. \n" +
            "My nickname is " + this->nickname + ". \n" +
            "I am from " + this->city + ", " + this->country + ".\n" +
            "And my hobbies are: ";

    for (const string &hobby: hobbies) {
        profile += hobby + " ";
    }

    return profile;
}