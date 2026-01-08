#include "papir.h"
#include <fstream>

Papir::Papir(const std::string& imeDatoteke) {
    std::ifstream file(imeDatoteke);
    std::string vrstica;

    while (std::getline(file, vrstica)) {
        std::vector<char> row;
        for (char c : vrstica) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    rows = grid.size();
    cols = grid[0].size();
}

bool Papir::jeDostopna(int r, int c) const {
    int sosednjeRole = 0;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;

            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (grid[nr][nc] == '@') {
                    sosednjeRole++;
                }
            }
        }
    }

    return sosednjeRole < 4;
}

int Papir::prestejDostopne() const {
    int stevec = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '@' && jeDostopna(r, c)) {
                stevec++;
            }
        }
    }

    return stevec;
}


int Papir::odstraniVseMozne() {
    int skupajOdstranjenih = 0;

    while (true) {
        std::vector<std::pair<int, int>> zaOdstraniti;

        // 1. korak: poišči vse trenutno dostopne role
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '@' && jeDostopna(r, c)) {
                    zaOdstraniti.push_back({r, c});
                }
            }
        }

        // 2. korak: če ni ničesar več za odstraniti → konec
        if (zaOdstraniti.empty()) {
            break;
        }

        // 3. korak: odstrani vse najdene role
        for (const auto& p : zaOdstraniti) {
            grid[p.first][p.second] = '.';
        }

        // 4. korak: prištej
        skupajOdstranjenih += zaOdstraniti.size();
    }

    return skupajOdstranjenih;
}
