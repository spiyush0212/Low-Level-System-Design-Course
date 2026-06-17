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

    virtual void accelerate() = 0; // Pure virtual function for acceleration
    virtual void applyBrakes() = 0; // Pure virtual function for applying brakes

    virtual ~Car() {};
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

    void accelerate() override {
        currentSpeed += 10;
        cout << "ManualCar: Accelerating!" << endl;
    }

    void applyBrakes() override {
        currentSpeed -= 10;
        cout << "ManualCar: Applying brakes!" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(const string& brand, const string& model) : Car(brand, model) {}

    void chargeBattery() {
        batteryLevel = 100;
        cout << "ElectricCar: Charging battery!" << endl;
    }

    void accelerate() override {
        currentSpeed += 15;
        cout << "ElectricCar: Accelerating!" << endl;
    }

    void applyBrakes() override {
        currentSpeed -= 15;
        cout << "ElectricCar: Applying brakes!" << endl;
    }
};

int main() {
    Car* manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->applyBrakes();
    manualCar->stopEngine();
    
    Car* electricCar = new ElectricCar("Tesla", "Model 3");
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->applyBrakes();
    electricCar->stopEngine();

    delete manualCar;
    delete electricCar;

    return 0;
}