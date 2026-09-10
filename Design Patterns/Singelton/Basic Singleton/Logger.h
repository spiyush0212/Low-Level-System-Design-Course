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
        if (!instance)
            instance = new Logger();
        return instance;
    }
};

Logger* Logger::instance = nullptr;