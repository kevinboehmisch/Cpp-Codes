/*Aufgabenstellung:

Für eine Bibliotheksanwendung benötigen Sie verschiedene Benutzergruppen, Dozenten (Klasse 'Lecturer') und Studenten (Klasse 'Student'). 
Diese sollen von einer gemeinsamen Basisklasse 'Person' erben. Die Ausleihdauer soll für Dozenten 90 Tage und für Studenten 30 Tage betragen. 
Ergänzen Sie die Vererbungshierarchie und implementieren Sie die angegebenen Methoden. 
Verwenden Sie Delegation, um den Konstruktor der Basisklasse aufzurufen und nutzen Sie in den print()-Methoden von Dozent und Student die print()-Methode der Basisklasse.

Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen:

Ausgabe:

smith, Matrikelnummer 12345678
Ausleihdauer: 30 Tage(e)
miller, Prüfernummer 98
Ausleihdauer: 90 Tage(e)*/




#include <string>
#include <iostream>
using namespace std;

//Klasse Person
class Person {
	string _name;
	int _check_out_duration;

public:
	Person(string name, int check_out_duration = 0);
	int get_check_out_duration() const;
	void print() const;
};

Person::Person(string name, int check_out_duration) : _name(name), _check_out_duration(check_out_duration) {
}

int Person::get_check_out_duration() const {
    return _check_out_duration;
}

void Person::print() const {
    cout << _name << ", ";
}

//Klasse Lecturer
class Lecturer : public Person {
	int _examiner_id;

public:
	Lecturer(string name, int examiner_id);
	void print() const;
};

Lecturer::Lecturer(string name, int examiner_id): Person(name, 90), _examiner_id(examiner_id){
}

void Lecturer::print() const {
    Person::print(); 
    cout << "Prüfernummer " << _examiner_id << endl;
}

//Klasse Person
class Student: public Person
{
	int _matriculation_number;

public:
	Student(string name, int matriculation_number);
	void print() const;
};
Student::Student(string name, int matriculation_number): Person(name, 30), _matriculation_number(matriculation_number){
	}
void Student::print()const {
    Person::print(); 
    cout << "Matrikelnummer " << _matriculation_number << endl;
}


//main Programm
int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

