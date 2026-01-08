#include <iostream>
#include <fstream>
#include <string>
#include "baterije3.h"

int main() {
    using namespace std;

    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Napaka pri odpiranju input.txt\n";
        return 1;
    }

    string line;
    long long vsota_prva  = 0;
    long long vsota_druga = 0;

    while (getline(in, line)) {
        Baterije3 bank(line);

        // 1. stopnja
        vsota_prva += bank.max_joltage_prva_st();

        // 2. stopnja
        vsota_druga += bank.max_joltage_druga_st();
    }

    in.close();

    cout << "1. stopnja - skupna vsota = " << vsota_prva << endl;
    cout << "2. stopnja - skupna vsota = " << vsota_druga << endl;

    return 0;
}
