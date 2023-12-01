#include <iostream>
#include <string>

using namespace std;

class Human {
private:
    string name;
    int age;
    bool sex;
    string status;
    string city;
    bool famStatus;
    string favMusicGenre;

public:
    Human(string name, int age, bool sex, string status, string city, bool married, string music)
        : name(name), age(age), sex(sex), status(status), city(city), famStatus(married), favMusicGenre(music) {
    }

    friend std::ostream& operator<<(ostream& os, const Human& person) {
        os << "Name: " << person.name << endl;
        os << "Age: " << person.age << endl;
        os << "Sex: " << (person.sex? "Male": "Female") << endl;
        os << "Status: " << person.status << endl;
        os << "City: " << person.city << endl;
        os << "Family status: " << (person.famStatus? "Married":"Single") << endl;
        os << "Favourite music genre: " << person.favMusicGenre << endl;
        os << "--------------------------" << endl;
        return os;
    }

    string getCity() const {
        return city;
    }

    void setCity(const string& newCity) {
        city = newCity;
    }

    string getSex() const {
        return sex? "Male":"Female";
    }

    bool getFamilyStatus() const {
        return famStatus;
    }

    void setFamilyStatus(const bool& newFamilyStatus) {
        famStatus = newFamilyStatus;
    }

    string getFavoriteMusicGenre() const {
        return favMusicGenre;
    }

    void setFavoriteMusicGenre(const string& newFavoriteMusicGenre) {
        favMusicGenre = newFavoriteMusicGenre;
    }

};

int main() {
    Human person1("Max", 10, true, "Programmer", "Ussuriisk", true, "Rock");
    Human person2("Marina", 25, false, "Teacher", "Ussuriisk", false, "Rap");
    Human person3("Katya", 19, false, "Student", "Ussuriisk", true, "Reggae");

    cout << person1 << person2 << person3;

    person2.setCity("Vladivostok");
    cout << person2.getCity() << endl;

    Human person4("Oleg", 53, true, "Unemployed", "Moscow", false, "Chanson");
    cout << person4;
    cout << person4.getSex();

    return 0;
}
