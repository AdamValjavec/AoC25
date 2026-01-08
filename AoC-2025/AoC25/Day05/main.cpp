#include <iostream>
#include "sestavine.h"

int main() {
    Sestavine sestavine;

    sestavine.preberiVhod("input.txt");

    std::cout << "Part 1 - Stevilo svezih sestavin: "
              << sestavine.prestejSveze()
              << std::endl;

    std::cout << "Part 2 - Skupno stevilo svezih ID-jev: "
              << sestavine.prestejSvezePart2()
              << std::endl;

    return 0;
}
