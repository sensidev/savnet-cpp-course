#include <iostream>

using namespace std;

/**
 * On the fly calculation. - ad hoc
 */
class AdHocSquare {
public:
    AdHocSquare(double side) {
        set_side(side);
    }

    void set_side(double side) {
        this->side = side;
    }

    double get_area() {
        return this->side * this->side;
    }

private:
    double side;
};

/**
 * Lazy calculation - caching
 */
class LazySquare {
public:
    LazySquare(double side) {
        set_side(side);
    }

    void set_side(double side) {
        this->side = side;
        this->is_side_changed = true;
    }

    double get_area() {
        if (this->is_side_changed) {
            this->area = this->side * this->side;
            this->is_side_changed = false;
        }
        return this->area;
    }

private:
    double side;
    double area;
    bool is_side_changed;
};


int main() {
    LazySquare lazy_square_object(5.0);
    cout << lazy_square_object.get_area() << endl;

    lazy_square_object.set_side(10);
    cout << lazy_square_object.get_area() << endl;

    cout << "lazy: " << lazy_square_object.get_area() << endl;
    cout << "lazy: " << lazy_square_object.get_area() << endl;
    cout << "lazy: " << lazy_square_object.get_area() << endl;

    AdHocSquare ad_hoc_square_object(10);
    cout << "ad_hoc: " << ad_hoc_square_object.get_area() << endl;

    ad_hoc_square_object.set_side(11);
    cout << "ad_hoc: " << ad_hoc_square_object.get_area() << endl;

    cout << "ad_hoc: " << ad_hoc_square_object.get_area() << endl;
    cout << "ad_hoc: " << ad_hoc_square_object.get_area() << endl;
    cout << "ad_hoc: " << ad_hoc_square_object.get_area() << endl;

    return 0;
}