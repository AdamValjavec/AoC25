#include "baterije3.h"

// konstruktor: shrani vse cifre
Baterije3::Baterije3(const std::string& vrstica) {
    for (char c : vrstica) {
        cifre.push_back(c - '0');
    }
}

// --------------------
// 1. STOPNJA
// --------------------
int Baterije3::max_joltage_prva_st() const {
    int maxvrednost = 0;

    for (int i = 0; i < (int)cifre.size(); i++) {
        for (int j = i + 1; j < (int)cifre.size(); j++) {
            int vrednost = cifre[i] * 10 + cifre[j];
            if (vrednost > maxvrednost) {
                maxvrednost = vrednost;
            }
        }
    }
    return maxvrednost;
}

// --------------------
// 2. STOPNJA
// --------------------
long long Baterije3::max_joltage_druga_st() const {
    const int K = 12;
    int n = cifre.size();

    long long value = 0;
    int start = 0;

    for (int picked = 0; picked < K; picked++) {
        int maxDigit = -1;
        int maxPos   = -1;

        int end = n - (K - picked);

        for (int i = start; i <= end; i++) {
            if (cifre[i] > maxDigit) {
                maxDigit = cifre[i];
                maxPos   = i;
            }
        }

        value = value * 10 + maxDigit;
        start = maxPos + 1;
    }

    return value;
}
