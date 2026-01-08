#include <iostream>
#include <fstream>
#include <string>
#include "baterije.h"

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Error reading file.\n";
        return 1;
    }

    string line;
    getline(fin, line);

    // Objekt za stopnjo 1
    Baterije baterije1;
    baterije1.obdelajVrstico1(line);
    cout << "Skupna vsota (stopnja 1): " << baterije1.vsota() << "\n";

    // Objekt za stopnjo 2
    Baterije baterije2;
    baterije2.obdelajVrstico2(line);
    cout << "Skupna vsota (stopnja 2): " << baterije2.vsota() << "\n";

    return 0;
}
