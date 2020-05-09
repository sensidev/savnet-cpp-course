#include "profile.h"


Profile::Profile(string name, uint8_t age) {
    this->name = name;
    this->age = age;
}

bool Profile::operator==(const Profile &right) {
    // this - left operator - profile from left.
    // right - right operator - profile from right.

    if (!this->is_same_country(right)) {
        return false;
    }

    if (!this->is_same_city(right)) {
        return false;
    }

    if (!this->is_age_close_to(right, 5)) {
        return false;
    }

    if (!this->has_same_hobbies(right, 2)) {
        return false;
    }

    return true;
}

bool Profile::operator!=(const Profile &right) {
    // this - left operator.
    // right - right operator.
    return !(*this == right);
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

bool Profile::is_same_city(const Profile &right) {
    return this->city == right.city;
}

bool Profile::is_same_country(const Profile &right) {
    return this->country == right.country;
}

bool Profile::is_age_close_to(const Profile &right, unsigned int delta) {
    return this->age - delta <= right.age && right.age <= this->age + delta;
}

bool Profile::has_same_hobbies(const Profile &right, unsigned int how_many) {
    unsigned int hobby_count = 0;

    for (int left_index = 0; left_index < this->hobbies.size(); left_index++) {
        for (int right_index = 0; right_index < right.hobbies.size(); right_index++) {
            if (this->hobbies[left_index] == right.hobbies[right_index])
                hobby_count++;
        }
    }

// Alternative - foreach.
//    for (const string &left_hobby: this->hobbies) {
//        for (const string &right_hobby: right.hobbies) {
//            if (left_hobby == right_hobby)
//                hobby_count++;
//        }
//    }

    return hobby_count >= how_many;
}

void Profile::add_hobby(const string &hobby) {
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

    profile += '\n';
    profile += "--------------------------------\n";

    return profile;
}