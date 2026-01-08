#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>

class MathSheet {
private:
    std::vector<std::vector<int>> numbers;   
    std::vector<char> operations;
    std::vector<std::string> rawLines;       

public:
    void readFile(const std::string& filename);

    long long computeTotal() const;          
    long long computeTotalPartTwo() const;   
};

#endif
