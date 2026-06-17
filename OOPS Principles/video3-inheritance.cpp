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

    void startEngine() {
        isEngineRunning = true;
        cout << "Car: Starting engine!" << endl;
    }

    void stopEngine() {
        isEngineRunning = false;
        cout << "Car: Stopping engine!" << endl;
    }

    void accelerate() {
        currentSpeed += 10;
        cout << "Car: Accelerating!" << endl;
    }

    void applyBrakes() {
        currentSpeed -= 10;
        cout << "Car: Applying brakes!" << endl;
    }

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
};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(const string& brand, const string& model) : Car(brand, model) {
        this->batteryLevel = 100;
    }

    void chargeBattery() {
        batteryLevel = 100;
        cout << "ElectricCar: Charging battery to 100%!" << endl;
    }
};

int main() {
    ManualCar myManualCar("Toyota", "Corolla");
    myManualCar.startEngine();
    myManualCar.accelerate();
    myManualCar.shiftGear();
    myManualCar.applyBrakes();
    myManualCar.stopEngine();

    cout << endl;

    ElectricCar myElectricCar("Tesla", "Model 3");
    myElectricCar.startEngine();
    myElectricCar.accelerate();
    myElectricCar.chargeBattery();
    myElectricCar.applyBrakes();
    myElectricCar.stopEngine();

    return 0;
}