#include <iostream>

using namespace std;

class Person {
private:
    char *some_pointer;
    string name;
    int age;

    void do_something_private() {
        cout << " private ";
    }

public:
    string title;

    Person(string name, uint8_t age) {
        this->some_pointer = new char(100);

        this->title = "Miss";
        this->name = name;
        this->age = age;
    }

    ~Person() {
        // usually, this is the place where you cleanup other memory allocation, like this:
        delete this->some_pointer;
        cout << this->name << " - just die! " << endl;
    }

    void present_yourself() {
        cout << "My name is " << this->name << " age " << this->age;
        this->do_something_private();
        cout << endl;
    }
};

int main() {
    Person *pointer = NULL;

    pointer = new Person("Gigel", 32);  // a pointer getting a fresh address of a new instance (it's light)
    pointer->title = "Misterxxxxxxx";
    cout << (*pointer).title << endl;  // an instance (object) accessing field 'title'
    cout << pointer->title << endl;  // a pointer accessing field 'title'
    pointer->present_yourself();  // a pointer accessing a method
    cout << pointer << endl;
    delete pointer;
    cout << pointer << endl;

    Person person("Vasile", 31);  // a variable is instantiated (it's heavy)
    person.title = "Mrs";
    cout << person.title << endl;  // an instance (object) accessing field 'title'
    cout << (&person)->title << endl;  // a pointer accessing field 'title'
    person.present_yourself();  // an instance (object) accessing a method
    cout << &person << endl;

    pointer = &person;
    cout << pointer << endl;

    // You can't delete an instance that wasn't previously instantiated with `new` operator
//    delete pointer;
//    cout << pointer << endl;

    Person other_person("Isabella", 32);  // a variable is instantiated (it's heavy)
    other_person.title = "Misses";
    cout << other_person.title << endl;  // an instance (object) accessing field 'title'
    cout << (&other_person)->title << endl;  // a pointer accessing field 'title'
    other_person.present_yourself();  // an instance (object) accessing a method
    cout << &other_person << endl;

    // delete operator is called by default at the end of the main block.
    return 0;
}

