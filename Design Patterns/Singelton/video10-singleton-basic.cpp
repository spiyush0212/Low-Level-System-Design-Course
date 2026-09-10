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

int main() {
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();

    cout << ((logger1 == logger2) ? "Both objects are same" : "Both objects are different") << "\n";

    return 0;
}