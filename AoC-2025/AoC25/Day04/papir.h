#ifndef PAPIR_H
#define PAPIR_H

#include <vector>
#include <string>

class Papir {
private:
    std::vector<std::vector<char>> grid;
    int rows;
    int cols;

    bool jeDostopna(int r, int c) const;

public:
    Papir(const std::string& imeDatoteke);

    int prestejDostopne() const;      // 1. stopnja
    int odstraniVseMozne();           // 2. stopnja
};

#endif
