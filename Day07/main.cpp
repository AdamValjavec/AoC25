#include "tuba.h"
#include <iostream>

int main() {
    Tuba t;
    if (!t.loadFromFile("input.txt")) {
        std::cerr << "Error reading input file!" << std::endl;
        return 1;
    }

    // del 1 
    t.simulate();
    std::cout << "Part One - št delitev: " << t.getSplits() << std::endl;

    // del 2
    long long timelines = t.simulateQuantum();
    std::cout << "Part Two - št. variant " << timelines << std::endl;

    return 0;
}
