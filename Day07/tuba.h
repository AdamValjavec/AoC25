#ifndef TUBA_H
#define TUBA_H

#include <vector>
#include <string>

class Tuba {
private:
    std::vector<std::string> grid; // 2D grid
    int splits;                     // števec razcepov (Part One)
    int startCol;                   // stolpec začetka 'S'

public:
    Tuba();
    bool loadFromFile(const std::string &filename);

    // Part One
    void simulate();
    int getSplits() const { return splits; }

    // Part Two
    long long simulateQuantum();

private:
    struct Beam {
        int row;
        int col;
        Beam(int r, int c) : row(r), col(c) {}
    };
};

#endif
