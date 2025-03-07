#include <iostream>
#include <cstring>

using namespace std;

class Vehicle {
protected:
    char brand[50];
    int speed;

public:
    Vehicle(const char* brand, int speed) : speed(speed) {
        strcpy(this->brand, brand);
    }

    virtual void displayDetails() const {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(const char* brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(const char* brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails() {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    char brand[50];
    int speed, seats, batteryLife;

    cout << "Enter Electric Car Brand: ";
    cin.getline(brand, 50);

    cout << "Enter Electric Car Speed: ";
    cin >> speed;

    cout << "Enter Electric Car Seats: ";
    cin >> seats;

    cout << "Enter Electric Car Battery Life (hours): ";
    cin >> batteryLife;

    ElectricCar electricCar(brand, speed, seats, batteryLife);

    cout << endl;
    cout << "Electric Car Details:\n";
    electricCar.displayDetails();

    return 0;
}