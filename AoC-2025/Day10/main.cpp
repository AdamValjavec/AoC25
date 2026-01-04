#include <iostream>
#include <fstream>
#include <sstream>
#include "stroj.h"

int main() {
    std::ifstream in("input.txt");
    if (!in) {
        std::cerr << "Napaka pri odpiranju input.txt\n";
        return 1;
    }

    std::string line;
    int total = 0;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        // diagram
        int l = line.find('[');
        int r = line.find(']');
        std::string diagram = line.substr(l + 1, r - l - 1);

        // gumbi
        std::vector<std::vector<int>> buttons;
        size_t pos = r + 1;

        while ((pos = line.find('(', pos)) != std::string::npos) {
            size_t end = line.find(')', pos);
            std::string inside = line.substr(pos + 1, end - pos - 1);

            std::vector<int> b;
            std::stringstream ss(inside);
            std::string num;

            while (std::getline(ss, num, ',')) {
                b.push_back(std::stoi(num));
            }

            buttons.push_back(b);
            pos = end + 1;
        }

        Stroj s(diagram, buttons);
        total += s.minimalPresses();
    }

    std::cout << "Skupaj minimalnih pritiskov: " << total << "\n";
    return 0;
}
