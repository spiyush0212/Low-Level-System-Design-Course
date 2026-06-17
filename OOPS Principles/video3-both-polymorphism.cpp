#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string brand;
    string model;
    bool isEngineRunning;
    int currentSpeed;

public:
    Car(const string& brand, const string& model) {
        this->brand = brand;
        this->model = model;
        this->isEngineRunning = false;
        this->currentSpeed = 0;
    }

    virtual void startEngine() {
        isEngineRunning = true;
        cout << "Car: Starting engine!" << endl;
    }

    virtual void stopEngine() {
        isEngineRunning = false;
        cout << "Car: Stopping engine!" << endl;
    }

    virtual void accelerate() = 0;

    virtual void accelerate(int increment) = 0;

    virtual void applyBrakes() = 0; 

    virtual ~Car() {
        cout << "Car: Destructor called!" << endl;
    }
};

class ManualCar : public Car {
private:
    int currentGear;
public:
    ManualCar(const string& brand, const string& model) : Car(brand, model) {
        this->currentGear = 0;
    } 

    void shiftGear() {
        currentGear++;
        cout << "ManualCar: Shifting to gear " << currentGear << "!" << endl;
    }

    void accelerate() {
        currentSpeed += 10;
        cout << "ManualCar: Accelerating!" << endl;
    }

    void accelerate(int increment) {
        currentSpeed += increment;
        cout << "ManualCar: Accelerating by " << increment << "!" << endl;
    }

    void applyBrakes() {
        currentSpeed -= 10;
        cout << "ManualCar: Applying brakes!" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLevel;
public:
    ElectricCar(const string& brand, const string& model) : Car(brand, model) {
        this->batteryLevel = 100; // Assume battery starts fully charged
    }

    void chargeBattery() {
        batteryLevel = 100;
        cout << "ElectricCar: Charging battery!" << endl;
    }

    void accelerate() {
        currentSpeed += 15; // Electric cars can accelerate faster
        cout << "ElectricCar: Accelerating!" << endl;
    }

    void accelerate(int increment) {
        currentSpeed += increment;
        cout << "ElectricCar: Accelerating by " << increment << "!" << endl;
    }

    void applyBrakes() {
        currentSpeed -= 15; // Electric cars can decelerate faster
        cout << "ElectricCar: Applying brakes!" << endl;
    }
};  

int main() {
    Car* car1 = new ManualCar("Toyota", "Corolla");
    Car* car2 = new ElectricCar("Honda", "CivicEV");

    car1->startEngine();
    car1->accelerate();
    car1->applyBrakes();    
    car1->stopEngine();

    car2->startEngine();
    car2->accelerate();
    car2->applyBrakes();
    car2->stopEngine();

    delete car1;
    delete car2;

    return 0;
}
