#include "povezave.h"
#include <algorithm>

//tocka
long long Povezave::Tocka::squaredDistance(const Tocka& other) const {
    long long dx = x - other.x;
    long long dy = y - other.y;
    long long dz = z - other.z;
    return dx*dx + dy*dy + dz*dz;
}

//edge
bool Povezave::Edge::operator<(const Edge& other) const {
    return dist < other.dist;
}

//DSU
Povezave::DSU::DSU(int n) : parent(n), size(n, 1), components(n) {
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

int Povezave::DSU::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool Povezave::DSU::unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;

    if (size[a] < size[b])
        std::swap(a, b);

    parent[b] = a;
    size[a] += size[b];
    components--;
    return true;
}

void Povezave::addPoint(int x, int y, int z) {
    tocke.push_back({x, y, z});
}

void Povezave::buildEdges() {
    edges.clear();
    int n = tocke.size();

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edges.push_back({i, j, tocke[i].squaredDistance(tocke[j])});

    std::sort(edges.begin(), edges.end());
}

// del 1.
long long Povezave::solvePartOne(int connections) {
    buildEdges();
    DSU dsu(tocke.size());

    for (int i = 0; i < connections && i < edges.size(); ++i)
        dsu.unite(edges[i].a, edges[i].b);

    std::vector<int> sizes;
    for (int i = 0; i < dsu.parent.size(); ++i)
        if (dsu.find(i) == i)
            sizes.push_back(dsu.size[i]);

    std::sort(sizes.begin(), sizes.end(), std::greater<int>());
    return 1LL * sizes[0] * sizes[1] * sizes[2];
}

// del 2.
long long Povezave::solvePartTwo() {
    buildEdges();
    DSU dsu(tocke.size());

    for (const auto& e : edges) {
        int before = dsu.components;
        bool merged = dsu.unite(e.a, e.b);

        if (merged && before == 2 && dsu.components == 1) {
            return 1LL * tocke[e.a].x * tocke[e.b].x;
        }
    }
    return -1;
}
