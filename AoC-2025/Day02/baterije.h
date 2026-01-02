#ifndef BATERIJE_H
#define BATERIJE_H

#include <string>
#include <vector>

class Baterije {
private:
    std::vector<long long> invalidIDs;

    // Stopnja 1
    bool podvojena1(long long n);

    // Stopnja 2
    bool podvojena2(long long n);

public:
    // Stopnja 1
    void obdelajVrstico1(const std::string& line);

    // Stopnja 2
    void obdelajVrstico2(const std::string& line);

    long long vsota() const;
};

#endif
