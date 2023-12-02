#include <iostream>
#include <string>
#include <vector>

using namespace std;


class AbstractPerson {
public:
    virtual string speak() const =0;
    virtual ~AbstractPerson() = default;  
};

class Human: public AbstractPerson {
protected:
    string name;
    int age;
    bool sex;
    string city;

public:
    Human(string name, int age, bool sex, string city)
        : name(name), age(age), sex(sex), city(city) {
    }

    friend ostream& operator<<(ostream& os, const Human& Human);

    string speak()const override{
        return  "Hi, I'm Human";
    }

    string getCity() const {
        return city;
    }

    void setCity(const string& newCity) {
        city = newCity;
    }

    string getSex() const {
        return sex ? "Male" : "Female";
    }
};

ostream& operator<<(ostream& os, const Human& Human) {
    os << "Name: " << Human.name << endl;
    os << "Age: " << Human.age << endl;
    os << "Sex: " << (Human.sex ? "Male" : "Female") << endl;
    os << "City: " << Human.city << endl;
    os << "--------------------------" << endl;
    return os;
}

class Musician : public Human {
private:
    string nick;
    string mainInstrument;
    string musicGenre;
    vector<string> albums;

public:
    Musician(string name, int age, bool sex, string city, string nick, string instrument, string music)
        : Human(name, age, sex, city), nick(nick), mainInstrument(instrument), musicGenre(music) {
    }

    string speak()const override{
        return  "Hi, I'm Musician";
    }

    void addAlbum(const string& album) {
        albums.push_back(album);
    }

    vector<string> getAlbums() const {
        return albums;
    }

    string getGenre() const {
        return musicGenre;
    }

    void setInstrument(const string& newInstrument) {
        mainInstrument = newInstrument;
    }

    string getInstrument() {
        return mainInstrument;
    }

    friend ostream& operator<<(ostream& os, const Musician& musicHuman);
};

ostream& operator<<(ostream& os, const Musician& musicHuman) {
    os << static_cast<const Human&>(musicHuman); 
    os << "Nick: " << musicHuman.nick << endl;
    os << "Main Instrument: " << musicHuman.mainInstrument << endl;
    os << "Music Genre: " << musicHuman.musicGenre << endl;
    os << "--------------------------" << endl;
    return os;
}

class Student : public Human {
private:
    string studentID;
    string major;

public:
    Student(string name, int age, bool sex, string city, string studentID, string major)
        : Human(name, age, sex, city), studentID(studentID), major(major) {
    }

    string speak()const override{
        return  "Hi, I'm Student";
    }

    friend ostream& operator<<(ostream& os, const Student& student);
};

ostream& operator<<(ostream& os, const Student& student) {
    os << static_cast<const Human&>(student); // Output Human part
    os << "Student ID: " << student.studentID << endl;
    os << "Major: " << student.major << endl;
    os << "--------------------------" << endl;
    return os;
}

class Employee : public Human {
private:
    int employeeID;
    string department;

public:
    Employee(string name, int age, bool sex, string city, int employeeID, string department)
        : Human(name, age, sex, city), employeeID(employeeID), department(department) {
    }

    friend ostream& operator<<(ostream& os, const Employee& employee);

    string speak()const override{
        return  "Hi, I'm Employee";
    }

    void setDepartment(const string& newDepartment){
        department = newDepartment;
    }

    string getDepartment(){
        return department;
    }

    void setID(int newID){
        employeeID = newID;
    }

    int getID(){
        return employeeID;
    }
};

ostream& operator<<(ostream& os, const Employee& employee) {
    os << static_cast<const Human&>(employee); // Output Human part
    os << "Employee ID: " << employee.employeeID << endl;
    os << "Department: " << employee.department << endl;
    os << "--------------------------" << endl;
    return os;
}

class Teacher : public Employee {
private:
    string subject;

public:
    Teacher(string name, int age, bool sex, string city, int employeeID, string department, string subject)
        : Employee(name, age, sex, city, employeeID, department), subject(subject) {
    }


    string speak()const override{
        return  "Hi, I'm Teacher";
    }

    void setSubject(const string& newSubject){
        subject = newSubject;
    }

    string getSubject(){
        return subject;
    }

    friend ostream& operator<<(ostream& os, const Teacher& teacher);
};

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << static_cast<const Employee&>(teacher); 
    os << "Subject: " << teacher.subject << endl;
    os << "--------------------------" << endl;
    return os;
}

class Athlete : public Human {
private:
    string sport;

public:
    Athlete(string name, int age, bool sex, string city, string sport)
        : Human(name, age, sex, city), sport(sport) {
    }

    string speak()const override{
        return "Hi, I'm Athlete";
    }

    void setSport(const string& newSport){
        sport = newSport;
    }

    string getSport(){
        return sport;
    }

    friend ostream& operator<<(ostream& os, const Athlete& athlete);
};

ostream& operator<<(ostream& os, const Athlete& athlete) {
    os << static_cast<const Human&>(athlete); // Output Human part
    os << "Sport: " << athlete.sport << endl;
    os << "--------------------------" << endl;
    return os;
}


int main() {
    Human human("Alice", 22, false, "Moscow");
    cout << human.getCity() << endl;
    human.setCity("Ussuriisk");
    cout << human.getSex() << endl;
    cout << human << endl;


    Musician musician("Oleg", 19, true, "Vladivostok", "DrumHero", "Drums", "Rock");
    cout << musician.speak();
    cout << endl;
    cout << musician << endl;
    musician.addAlbum("Toxicity");
    musician.addAlbum("Rammstein");
    musician.setCity("Moscow");
    cout << musician.getInstrument() << endl;
    cout << endl;

    Student student("Aleksei", 20, true, "Rostov", "12345", "Computer Science");
    Employee employee("Andrew", 29, true, "St.Petersburg", 9876, "IT");
    employee.setDepartment("IMKT");
    employee.setCity("Ostrov Russkii");
    employee.setID(109872);
    Teacher teacher("Eva", 36, false, "Ostrov Russkii", 5432, "Education", "Math");
    teacher.setDepartment("Politex");
    teacher.setSubject("Geometry");
    Athlete athlete("Veronika", 28, false, "Rome", "Basketball");

    cout << student << endl;
    cout << employee << endl;
    cout << teacher << endl;
    cout << athlete.speak() << endl;
    cout << athlete;
    

    return 0;
}
