/***********************
Name: Class Practicer 2.0
Author: Zach Thompson
Version: 1.0 4/20/2019
Purpose: To practice working with classes
Variables:
    side As Double
    area As Double
    updated As Boolean
    side_changed As Boolean
************************/

#include <iostream>
#include <string>

using namespace std;

// Here is the class from the previous Lab
class Square {
    public:
        // Here are the functions
        Square(double side);
        set_side(double side);
        get_area();
        print();
    private:
        // Here is the data.  I have included a update status too
        double side = 0;
        double area = 0;
        bool updated = 1;
};

// This is the class Constructor
Square::Square(double side) {
    this->set_side(side);
    this->get_area();
}

// This is the function to set the side value
//  It also updates the update Boolean check
Square::set_side(double side) {
    if (side >= 0) {
        this->side = side;
        this->updated = 1;
    }
}

// This is the function to set the area value
//  It also updates the update Boolean check
Square::get_area() {
    if (updated) {
        this->area = this->side * this->side;
        this->updated = 0;
    }
}

// This is the function to print out the data
Square::print() {
    this->get_area();
    cout << "Square: side=" << this->side << " area=" << this->area << endl;
}

class AdHocSquare {
    public:
        // Here are the functions
        AdHocSquare(double side);
        set_side(double side);
        get_area();
    private:
        // Here is the data.
        double side;
};

// This is the class Constructor
AdHocSquare::AdHocSquare(double side) {
    this->set_side(side);
}

// This is the function to set the side value
AdHocSquare::set_side(double side) {
    if (side >= 0) {
        this->side = side;
    }
}

// This is the function to find the area print out the data
AdHocSquare::get_area() {
    int area = this->side * this->side;
    cout << "Square: side=" << this->side << " area=" << area << endl;
}

class LazySquare {
    public:
        // Here are the functions
        LazySquare(double side);
        set_side(double side);
        get_area();
        print();
    private:
        // Here is the data.  I have included a update status too
        double side;
        double area;
        bool side_changed;
};

// This is the class Constructor
LazySquare::LazySquare(double side) {
    this->set_side(side);
    this->get_area();
}

// This is the function to set the side value
//  It also updates the update Boolean check
LazySquare::set_side(double side) {
    if (side >= 0) {
        this->side = side;
        this->side_changed = 1;
    }
}

// This is the function to set the area value
//  It also updates the update Boolean check
LazySquare::get_area() {
    if (side_changed) {
        this->area = this->side * this->side;
        this->side_changed = 0;
    }
}

// This is the function to print out the data
LazySquare::print() {
    this->get_area();
    cout << "Square: side=" << this->side << " area=" << this->area << endl;
}

int main() {
    Square square(4);
    square.print();
    square.set_side(2.0);
    square.print();
    square.set_side(-33.0);
    square.print();
    LazySquare lazySquare(4);
    lazySquare.print();
    lazySquare.set_side(2.0);
    lazySquare.print();
    lazySquare.set_side(-33.0);
    lazySquare.print();
    AdHocSquare adhocSquare(4);
    adhocSquare.get_area();
    adhocSquare.set_side(2.0);
    adhocSquare.get_area();
    adhocSquare.set_side(-33.0);
    adhocSquare.get_area();
    return 0;
}
