#include <iostream>
#include <string>

using namespace std;

class Human {
private:
    string name;
    int age;
    string status;

public:
    Human(string name, int age, string status)
        : name(name), age(age), status(status) {
    }

    friend std::ostream& operator<<(ostream& os, const Human& person) {
        os << "Name: " << person.name << endl;
        os << "Age: " << person.age << endl;
        os << "Status: " << person.status << endl;
        os << "--------------------------" << endl;
        return os;
    }

};

int main() {
    Human person1("Max", 10, "Programmer");
    Human person2("Marina", 25, "Teacher");
    Human person3("Katya", 19, "Student");

    cout << person1 << person2 << person3;

    return 0;
}
