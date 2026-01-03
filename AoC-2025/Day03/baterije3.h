#ifndef BATERIJE3_H
#define BATERIJE3_H

#include <string>
#include <vector>

class Baterije3 {
private:
    std::vector<int> cifre;

public:
    // konstruktor
    Baterije3(const std::string& vrstica);

    // 1. stopnja: največje dvomestno število
    int max_joltage_prva_st() const;

    // 2. stopnja: največje 12-mestno število
    long long max_joltage_druga_st() const;
};

#endif
