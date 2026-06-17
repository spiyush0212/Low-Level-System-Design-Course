// OOPS - Abstraction

#include <iostream>
#include <string>

using namespace std;

class SportsCar {
private:
    string brand;
    string model;
    bool isEngineRunning;
    int currentGear;
    int currentSpeed;
    string tyre;
    
public:
    SportsCar(const string& brand, const string& model) {
        this->brand = brand;
        this->model = model;
        this->isEngineRunning = false;
        this->currentGear = 0;
        this->currentSpeed = 0;
        this->tyre = "Pirelli";
    }

    // Getter + No Setter
    int getCurrentSpeed() {
        return currentSpeed;
    }

    // Getter
    string getTyre() {
        return tyre;
    }

    // Setter
    void setTyre(const string& newTyre) {
        this->tyre = newTyre;
    }
        
    void startEngine() {
        isEngineRunning = true;
        cout << "SportsCar: Starting engine with a roar!" << endl;
    }

    void shiftGear() {
        currentGear++;
        cout << "SportsCar: Shifting to a higher gear for speed!" << endl;
    }

    void accelerate() {
        currentSpeed += 20;
        cout << "SportsCar: Accelerating rapidly!" << endl;
    }

    void applyBrakes() {
        currentSpeed -= 20;
        cout << "SportsCar: Applying brakes smoothly!" << endl;
    }

    void stopEngine() {
        isEngineRunning = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "SportsCar: Stopping engine with a cool down!" << endl;
    }
};

int main() {
    SportsCar* myCar = new SportsCar("Ford", "Mustang");
    
    myCar->startEngine();
    myCar->shiftGear();
    myCar->accelerate();
    myCar->applyBrakes();
    myCar->stopEngine();

    myCar->getCurrentSpeed();

    delete myCar; // Clean up memory

    return 0;
}