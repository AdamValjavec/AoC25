#include "plosce.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cstdlib>

Plosce::Plosce()
    : max_povrsina_prvi(0),
      max_povrsina_drugi(0) {}

void Plosce::preberiInput(const std::string& imeDatoteke) {
    std::ifstream file(imeDatoteke);
    std::string vrstica;

    while (std::getline(file, vrstica)) {
        std::stringstream ss(vrstica);
        char vejica;
        Tocka t;

        ss >> t.x >> vejica >> t.y;
        tocke.push_back(t);
    }
}

void Plosce::resiPrviDel() {
    max_povrsina_prvi = 0;
    int n = (int)tocke.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = llabs(tocke[i].x - tocke[j].x);
            long long dy = llabs(tocke[i].y - tocke[j].y);

            long long povrsina = (dx + 1) * (dy + 1);
            if (povrsina > max_povrsina_prvi)
                max_povrsina_prvi = povrsina;
        }
    }
}

long long Plosce::vrniMaxPovrsinoPrviDel() const {
    return max_povrsina_prvi;
}

void Plosce::zgradiKompresijo() {
    xs.clear();
    ys.clear();
    x_id.clear();
    y_id.clear();

    for (size_t i = 0; i < tocke.size(); i++) {
        xs.push_back(tocke[i].x);
        ys.push_back(tocke[i].y);
    }

    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

    for (size_t i = 0; i < xs.size(); i++)
        x_id[xs[i]] = (int)i;

    for (size_t i = 0; i < ys.size(); i++)
        y_id[ys[i]] = (int)i;
}
void Plosce::zgradiMrezo() {
    int w = (int)xs.size();
    int h = (int)ys.size();
    mreza.assign(h, std::vector<Tip>(w, PRAZNO));
}

void Plosce::narisiRob() {
    int n = (int)tocke.size();

    for (int i = 0; i < n; i++) {
        Tocka a = tocke[i];
        Tocka b = tocke[(i + 1) % n];

        if (a.x == b.x) {
            int xi = x_id[a.x];
            int y1 = y_id[std::min(a.y, b.y)];
            int y2 = y_id[std::max(a.y, b.y)];
            for (int y = y1; y <= y2; y++)
                mreza[y][xi] = ZELENO;
        } else {
            int yi = y_id[a.y];
            int x1 = x_id[std::min(a.x, b.x)];
            int x2 = x_id[std::max(a.x, b.x)];
            for (int x = x1; x <= x2; x++)
                mreza[yi][x] = ZELENO;
        }
    }

    for (size_t i = 0; i < tocke.size(); i++) {
        mreza[y_id[tocke[i].y]][x_id[tocke[i].x]] = RDECE;
    }
}

void Plosce::zapolniNotranjost() {
    int h = (int)mreza.size();
    int w = (int)mreza[0].size();

    std::vector<std::vector<bool>> obiskano(h, std::vector<bool>(w, false));
    std::queue<std::pair<int, int>> q;

    for (int x = 0; x < w; x++) {
        q.push(std::make_pair(0, x));
        q.push(std::make_pair(h - 1, x));
    }
    for (int y = 0; y < h; y++) {
        q.push(std::make_pair(y, 0));
        q.push(std::make_pair(y, w - 1));
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y < 0 || y >= h || x < 0 || x >= w) continue;
        if (obiskano[y][x]) continue;
        if (mreza[y][x] != PRAZNO) continue;

        obiskano[y][x] = true;

        for (int i = 0; i < 4; i++)
            q.push(std::make_pair(y + dy[i], x + dx[i]));
    }

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (mreza[y][x] == PRAZNO && !obiskano[y][x])
                mreza[y][x] = ZELENO;
}

bool Plosce::pravokotnikVeljaven(const Tocka& a, const Tocka& b) {
    long long x1 = std::min(a.x, b.x);
    long long x2 = std::max(a.x, b.x);
    long long y1 = std::min(a.y, b.y);
    long long y2 = std::max(a.y, b.y);

    for (size_t iy = 0; iy < ys.size(); iy++) {
        if (ys[iy] < y1 || ys[iy] > y2) continue;
        for (size_t ix = 0; ix < xs.size(); ix++) {
            if (xs[ix] < x1 || xs[ix] > x2) continue;
            if (mreza[iy][ix] == PRAZNO)
                return false;
        }
    }
    return true;
}

void Plosce::resiDrugiDel() {
    max_povrsina_drugi = 0;

    zgradiKompresijo();
    zgradiMrezo();
    narisiRob();
    zapolniNotranjost();

    int n = (int)tocke.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pravokotnikVeljaven(tocke[i], tocke[j])) {
                long long dx = llabs(tocke[i].x - tocke[j].x);
                long long dy = llabs(tocke[i].y - tocke[j].y);
                long long pov = (dx + 1) * (dy + 1);

                if (pov > max_povrsina_drugi)
                    max_povrsina_drugi = pov;
            }
        }
    }
}

long long Plosce::vrniMaxPovrsinoDrugiDel() const {
    return max_povrsina_drugi;
}
