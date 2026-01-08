#include <iostream>
#include "plosce.h"

int main() {
    Plosce p;

    p.preberiInput("input.txt");

    p.resiPrviDel();
    std::cout << "1. del: " << p.vrniMaxPovrsinoPrviDel() << std::endl;

    p.resiDrugiDel();
    std::cout << "2. del: " << p.vrniMaxPovrsinoDrugiDel() << std::endl;

    return 0;
}
