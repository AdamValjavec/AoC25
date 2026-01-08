#include "list.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

/* ================= READ FILE ================= */

void MathSheet::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        rawLines.push_back(line);
    }

    // operatorji (zadnja vrstica)
    std::istringstream ops(rawLines.back());
    std::string tok;
    while (ops >> tok)
        operations.push_back(tok[0]);

    int problems = operations.size();
    numbers.resize(problems);

    // Part One številke
    for (int r = 0; r < rawLines.size() - 1; ++r) {
        std::istringstream ss(rawLines[r]);
        for (int c = 0; c < problems; ++c) {
            int v;
            ss >> v;
            numbers[c].push_back(v);
        }
    }
}

// 1. del

long long MathSheet::computeTotal() const {
    long long total = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        long long result = (operations[i] == '+') ? 0 : 1;

        for (int n : numbers[i]) {
            if (operations[i] == '+')
                result += n;
            else
                result *= n;
        }

        total += result;
    }

    return total;
}

// 2. del

long long MathSheet::computeTotalPartTwo() const {
    long long total = 0;

    int rows = rawLines.size() - 1;          
    int cols = rawLines[0].size();

 
    std::vector<int> problemStarts;
    bool inProblem = false;

    for (int c = 0; c < cols; ++c) {
        bool hasDigit = false;
        for (int r = 0; r < rows; ++r) {
            if (std::isdigit(rawLines[r][c])) {
                hasDigit = true;
                break;
            }
        }

        if (hasDigit && !inProblem) {
            problemStarts.push_back(c);
            inProblem = true;
        } else if (!hasDigit) {
            inProblem = false;
        }
    }

    /* vsak problem posebej */
    for (int p = 0; p < problemStarts.size(); ++p) {
        int start = problemStarts[p];
        int end = start;

        // poišči konec problema
        while (end < cols) {
            bool empty = true;
            for (int r = 0; r < rows; ++r) {
                if (std::isdigit(rawLines[r][end])) {
                    empty = false;
                    break;
                }
            }
            if (empty) break;
            ++end;
        }

        long long result = (operations[p] == '+') ? 0 : 1;

        // kolumne DESNO → LEVO
        for (int c = end - 1; c >= start; --c) {
            std::string number;

            // cifre ZGORAJ → DOL
            for (int r = 0; r < rows; ++r) {
                if (std::isdigit(rawLines[r][c]))
                    number.push_back(rawLines[r][c]);
            }

            if (number.empty()) continue;

            long long value = std::stoll(number);

            if (operations[p] == '+')
                result += value;
            else
                result *= value;
        }

        total += result;
    }

    return total;
}
