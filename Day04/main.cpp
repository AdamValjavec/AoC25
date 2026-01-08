#include <iostream>
#include "papir.h"

int main() {
    // 1. stopnja
    Papir papir1("input.txt");
    std::cout << "1. stopnja - dostopne role: "
              << papir1.prestejDostopne() << std::endl;

    // 2. stopnja
    Papir papir2("input.txt");
    std::cout << "2. stopnja - skupaj odstranjenih rol: "
              << papir2.odstraniVseMozne() << std::endl;

    return 0;
}
