/***********************
Name: Drawing
Author: Zach Thompson
Version: 1.0 4/24/2019
Purpose: To draw ASCII art
Variables:
    drawing1 As Draw1
    drawing2 As Draw2
    drawing3 As Draw3
    ptrArray As Base Array
************************/

#include <iostream>

using namespace std;

// Here is my base class
class Base {
    public:
        virtual void draw();
};

// Here is the first of the subclasses
class Draw1: public Base {
    public:
        void draw();
};

// Here is the method for that class
void Draw1::draw() {
    cout << "Drawing 1:" << endl;
    cout << " /\\" << endl;
    cout << "//\\\\" << endl;
}

// Here is the second subclass
class Draw2: public Base {
    public:
        void draw();
};

// Here is the method for that class
void Draw2::draw() {
    cout << "Drawing 2:" << endl;
    cout << " /\\" << endl;
    cout << "/**\\" << endl;
}

// Here is the third and final subclass
class Draw3: public Base {
    public:
        void draw();
};

// Here is the method for that class
void Draw3::draw() {
    cout << "Drawing 3:" << endl;
    cout << " /\\" << endl;
    cout << "/++\\" << endl;
}

int main()
{
    // I create an array of pointers and then create my objects
    Base *ptrArray[3];
    Draw1 drawing1;
    ptrArray[0] = &drawing1;
    Draw2 drawing2;
    ptrArray[1] = &drawing2;
    Draw3 drawing3;
    ptrArray[2] = &drawing3;
    // Here we loop through to get the output
    for (int i = 0; i < 3; i++) {
        ptrArray[i]->draw();
    }
    return 0;
}
