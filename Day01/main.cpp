#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ura.h"

int main() {
    std::ifstream input_file("input.txt");

    if (!input_file) {
        std::cerr << "Error reading file.\n";
        return 1;
    }

    Ura ura1;
    Ura ura2;

    std::string line;
    while (std::getline(input_file, line)) {
        if (line.empty()) continue;

        char smer = line[0];
        int razdalja = 0;

        std::stringstream(line.substr(1)) >> razdalja;

        // ZA 1. STOPNJO 
        ura1.rotacijaStopnja1(smer, razdalja);

        // ZA 2. STOPNJO
        ura2.rotacijaStopnja2(smer, razdalja);

       
    }

    std::cout << "geslo 1. stopnja: "
              << ura1.getStevec() << std::endl;

    std::cout << "geslo 2. stopnja: "
              << ura2.getStevec() << std::endl;

    return 0;
}
