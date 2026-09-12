#include <iostream>
#include "HardDisk.h"
#include "Ram.h"
#include "Cpu.h"


class ComputerFacade {
public:
    void run() {
        cout << "Starting Computer..." << "\n";
        cpu->runCpu();
        ram->runRam();
        hd->runHardDisk();
        cout << "Computer Started..." << "\n";
    }

private:
    HardDisk* hd = new HardDisk();
    Cpu* cpu = new Cpu();
    Ram* ram = new Ram();
};