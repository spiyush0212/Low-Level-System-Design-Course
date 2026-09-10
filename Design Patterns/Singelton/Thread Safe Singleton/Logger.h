#include <iostream>
#include <mutex>

using namespace std;

class Logger {
private:
    static Logger* instance;
    static mutex mtx; // Helps for locking and unlocking the critical section

    Logger() {
        cout << "Created new instance of Logger Class" << "\n";
    }

public:
    static Logger* getInstance() {        
        if (!instance) {
            lock_guard<mutex> lock(mtx); // Locking the critical section
            if (!instance) // Introducing double-checked locking to avoid multiple threads creating multiple instances
                instance = new Logger();
        }
        return instance;
    }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;