#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(const string& name, float salary) : name(name), salary(salary) {}

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(const string& name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails() const override {
        Employee::displayDetails(); 
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter Manager Name: ";
    getline(cin, name); 

    cout << "Enter Manager Salary: ";
    cin >> salary;

    cout << "Enter Manager Bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);

    cout << "\nManager Details:\n";
    manager.displayDetails();

    return 0;
}