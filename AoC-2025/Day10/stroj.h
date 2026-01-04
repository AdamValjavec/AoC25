#ifndef STROJ_H
#define STROJ_H

#include <vector>
#include <string>

class Stroj {
public:
    Stroj(const std::string& diagram,
          const std::vector<std::vector<int>>& gumbi);

    int minimalPresses() const;

private:
    int nLights;
    int nButtons;

    std::vector<int> goal;                  // ciljna konfiguracija
    std::vector<std::vector<int>> buttons;  // gumbi
};

#endif
