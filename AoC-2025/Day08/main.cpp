#include <iostream>
#include <fstream>
#include <sstream>
#include "povezave.h"

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Napaka pri odpiranju input.txt\n";
        return 1;
    }

    Povezave povezave;
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        int x, y, z;
        char c;
        ss >> x >> c >> y >> c >> z;
        povezave.addPoint(x, y, z);
    }

    std::cout << "Part One: " << povezave.solvePartOne(1000) << std::endl;
    std::cout << "Part Two: " << povezave.solvePartTwo() << std::endl;

    return 0;
}
