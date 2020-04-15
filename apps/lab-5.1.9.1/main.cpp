#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:

    string title;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void check_this_out() {
        cout << this << endl;
    }

    string get_name() {
        return this->name;
    }

    int get_age() {
        return this->age;
    }

};

void print(Person *person) {
    person->title = "xxx";  // change on purpose.

    cout << person->title << " " <<
         person->get_name() << " is " << person->get_age() <<
         " years old" << endl;
}

int main() {
    Person person1("Harry", 23);
    Person person2("Tarry", 19);

    person1.title = "Mrs";
    person2.title = "Miss";

    cout << "Meet " << person1.get_name() << endl;
    cout << "Meet " << person2.get_name() << endl;

    print(&person1);
    print(&person2);

    // Demonstrate how objects passed by reference (address)
    // were affected by title change in print function.
    cout << "Title changed to " << person1.title << endl;
    cout << "Title changed to " << person2.title << endl;

    person1.check_this_out();
    person2.check_this_out();

    return 0;
}