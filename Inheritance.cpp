#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
protected:
    string name;
    int age;
    bool sex;
    string city;

public:
    Human(string name, int age, bool sex, string city)
        : name(name), age(age), sex(sex), city(city) {
    }

    friend std::ostream& operator<<(ostream& os, const Human& Human);

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

std::ostream& operator<<(ostream& os, const Human& Human) {
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

    friend std::ostream& operator<<(ostream& os, const Musician& musicHuman);
};

std::ostream& operator<<(ostream& os, const Musician& musicHuman) {
    os << static_cast<const Human&>(musicHuman); 
    os << "Nick: " << musicHuman.nick << endl;
    os << "Main Instrument: " << musicHuman.mainInstrument << endl;
    os << "Music Genre: " << musicHuman.musicGenre << endl;
    os << "--------------------------" << endl;
    return os;
}



int main() {
    Human human("Alice", 22, false, "Moscow");
    cout << human.getCity() << endl;
    human.setCity("Ussuriisk");
    cout << human.getSex() << endl;
    cout << human;


    Musician musician("Oleg", 19, true, "Vladivostok", "GuitarHero", "Guitar", "Rock");
    cout << musician << endl;
    musician.addAlbum("Toxicity");
    musician.addAlbum("Rammstein");
    musician.setCity("Moscow");
    cout << musician.getInstrument() << endl;

    return 0;
}
