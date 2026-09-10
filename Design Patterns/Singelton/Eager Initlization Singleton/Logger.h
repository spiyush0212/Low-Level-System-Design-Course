#include <iostream>

using namespace std;

class Logger {
private:
    static Logger* instance;

    Logger() {
        cout << "Created new instance of Logger Class" << "\n";
    }

public:
    static Logger* getInstance() {
        return instance;
    }
};

// Initializing the static member variable instance with a new instance of Logger class during the static initialization phase of the program. 
// This ensures that the instance is created before any thread accesses it, making it thread-safe without requiring additional synchronization mechanisms.
Logger* Logger::instance = new Logger();