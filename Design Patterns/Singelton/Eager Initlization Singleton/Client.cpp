#include <iostream>
#include "Logger.h"

using namespace std;

int main() {
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();

    cout << ((logger1 == logger2) ? "Both objects are same" : "Both objects are different") << "\n";

    return 0;
}