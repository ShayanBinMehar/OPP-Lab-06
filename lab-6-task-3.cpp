#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;

public:
    Teacher(const string& name, int age, const string& subject) : Person(name, age), subject(subject) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Person {
protected:
    string researchArea;

public:
    Researcher(const string& name, int age, const string& researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(const string& name, int age, const string& subject, const string& researchArea, int publications)
        : Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() const override {
        Teacher::displayDetails(); 
        Researcher::displayDetails(); 
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter Professor Name: ";
    getline(cin, name);

    cout << "Enter Professor Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Professor Subject: ";
    getline(cin, subject);

    cout << "Enter Professor Research Area: ";
    getline(cin, researchArea);

    cout << "Enter Professor Publications: ";
    cin >> publications;

    Professor professor(name, age, subject, researchArea, publications);

    cout << "\nProfessor Details:\n";
    professor.displayDetails();

    return 0;
}