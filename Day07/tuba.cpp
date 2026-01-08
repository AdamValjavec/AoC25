#include "tuba.h"
#include <fstream>
#include <iostream>
#include <vector>

Tuba::Tuba() : splits(0), startCol(-1) {}

bool Tuba::loadFromFile(const std::string &filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) return false;

    std::string line;
    grid.clear();
    startCol = -1;

    int rowNum = 0;
    while (std::getline(infile, line)) {
        grid.push_back(line);
        if (startCol == -1) {
            for (int c = 0; c < static_cast<int>(line.size()); ++c) {
                if (line[c] == 'S') {
                    startCol = c; // Shrani stolpec 'S'
                    break;
                }
            }
        }
        rowNum++;
    }

    infile.close();

    if (startCol == -1) {
        std::cerr << "S not found in input file!" << std::endl;
        return false;
    }

    return true;
}

// ----------------- Part One -----------------
void Tuba::simulate() {
    if (grid.empty()) return;
    if (startCol == -1) return;

    int rows = grid.size();
    int cols = grid[0].size();

    splits = 0;
    std::vector<std::vector<bool>> active(rows, std::vector<bool>(cols, false));
    std::vector<Beam> beams;
    beams.emplace_back(0, startCol);
    active[0][startCol] = true;

    std::vector<Beam> nextBeams;
    nextBeams.reserve(beams.size() * 2);

    while (!beams.empty()) {
        nextBeams.clear();

        for (Beam &b : beams) {
            int row = b.row;
            int col = b.col;

            if (row >= rows || col < 0 || col >= cols) continue;

            if (grid[row][col] == '^') {
                splits++;
                if (col > 0 && row + 1 < rows && !active[row + 1][col - 1]) {
                    nextBeams.emplace_back(row + 1, col - 1);
                    active[row + 1][col - 1] = true;
                }
                if (col < cols - 1 && row + 1 < rows && !active[row + 1][col + 1]) {
                    nextBeams.emplace_back(row + 1, col + 1);
                    active[row + 1][col + 1] = true;
                }
            } else {
                // Navpični žarek na '.'. S NE spreminjamo!
                if (grid[row][col] == '.')
                    grid[row][col] = '|';
                if (row + 1 < rows && !active[row + 1][col]) {
                    nextBeams.emplace_back(row + 1, col);
                    active[row + 1][col] = true;
                }
            }
        }

        beams.swap(nextBeams);
    }
}

// ----------------- Part Two -----------------
long long Tuba::simulateQuantum() {
    if (grid.empty()) return 0;
    if (startCol == -1) return 0;

    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<long long>> dp(rows, std::vector<long long>(cols, 0));

    // zadnja vrstica: vsaka celica = 1
    for (int c = 0; c < cols; ++c) dp[rows - 1][c] = 1;

    // Iteracija od spodaj navzgor
    for (int r = rows - 2; r >= 0; --r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '^') {
                long long left = (c > 0) ? dp[r + 1][c - 1] : 1;
                long long right = (c < cols - 1) ? dp[r + 1][c + 1] : 1;
                dp[r][c] = left + right;
            } else {
                dp[r][c] = dp[r + 1][c];
            }
        }
    }

    return dp[0][startCol];
}
