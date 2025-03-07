#include <iostream>

using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    virtual void displayDetails() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() const override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device { 
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() const override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:

    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
        : Device(deviceID, status), SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() const override {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;

    cout << "Enter Device ID: ";
    cin >> deviceID;

    cout << "Enter Device Status (1 for On, 0 for Off): ";
    cin >> status;

    cout << "Enter Screen Size (inches): ";
    cin >> screenSize;

    cout << "Has Heart Rate Monitor? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;

    cout << "Enter Step Counter: ";
    cin >> stepCounter;

    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);

    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}