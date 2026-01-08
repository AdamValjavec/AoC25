#include "list.h"
#include <iostream>

int main() {
    MathSheet sheet;
    sheet.readFile("input.txt");

    std::cout << "Part 1: " << sheet.computeTotal() << '\n';
    std::cout << "Part 2: " << sheet.computeTotalPartTwo() << '\n';

    return 0;
}
