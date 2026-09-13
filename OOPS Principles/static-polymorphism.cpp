#include <iostream>
#include <string>

using namespace std;

class ManualCar {
private:
    string brand;
    string model;
    bool isEngineRunning;
    int currentSpeed;
    int currentGear;

public:
    ManualCar(const string& brand, const string& model) {   
        this->brand = brand;
        this->model = model;
        this->isEngineRunning = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }   

    void startEngine() {
        isEngineRunning = true;
        cout << "ManualCar: Starting engine!" << endl;
    }

    void stopEngine() {
        isEngineRunning = false;
        cout << "ManualCar: Stopping engine!" << endl;
    }

    void accelerate() {
        currentSpeed += 10;
        cout << "ManualCar: Accelerating!" << endl;
    }

    void accelerate(int increment) {
        currentSpeed += increment;
        cout << "ManualCar: Accelerating by " << increment << "!" << endl;
    }

    void brake() {
        currentSpeed -= 10;
        cout << "ManualCar: Applying brakes!" << endl;
    }

    void shiftGear() {
        currentGear++;
        cout << "ManualCar: Shifting to gear " << currentGear << "!" << endl;
    }
};

int main() {
    ManualCar* car = new ManualCar("Toyota", "Corolla");
    
    car->startEngine();
    car->accelerate();
    car->accelerate(20);
    car->brake();
    car->shiftGear();
    car->stopEngine();

    delete car;

    return 0;
}