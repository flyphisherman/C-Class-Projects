/***********************
Name: Class introduction
Author: Zach Thompson
Version: 1.0 4/19/2019
Purpose: To practice using classes
Variables:
    name As String
    age As Int
    car As String
    speed As Int
************************/

#include <iostream>
#include <string>

using namespace std;
class Person
{
    public:
        string name;
        int age;
        // Your code here
        string car;
        int speed = 0;

};

void print(Person* person) {
    cout << person->name << " is " << person->age << " years old" << endl;
}

void getSpeed(Person* person) {
    cout << person->name << " is driving " << person->car << " at " << person->speed << " MPH" << endl;
}

void accelerate(Person* person) {
    person->speed += 5;
}

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    cout << "Meet " << person.name;
    print(&person);
    // Your code here
    person.car = "Bugoti Varon";
    accelerate(&person);
    getSpeed(&person);
    return 0;
}
