#include "stroj.h"
#include <climits>

Stroj::Stroj(const std::string& diagram,
             const std::vector<std::vector<int>>& gumbi)
    : nLights(diagram.size()),
      nButtons(gumbi.size()),
      buttons(gumbi)
{
    goal.resize(nLights);
    for (int i = 0; i < nLights; ++i) {
        goal[i] = (diagram[i] == '#') ? 1 : 0;
    }
}

int Stroj::minimalPresses() const {
    int best = INT_MAX;

    int total = pow(2, nButtons);   


    for (int mask = 0; mask < total; ++mask) {
        std::vector<int> lights(nLights, 0);
        int presses = 0;

       
        for (int b = 0; b < nButtons; ++b) {
            if (mask & (1 << b)) {
                presses++;

                
                for (int idx : buttons[b]) {
                    lights[idx] = 1 - lights[idx];
                }
            }
        }

        // preverimo, ali smo zadeli cilj
        bool ok = true;
        for (int i = 0; i < nLights; ++i) {
            if (lights[i] != goal[i]) {
                ok = false;
                break;
            }
        }

        if (ok && presses < best) {
            best = presses;
        }
    }

    return best;
}
