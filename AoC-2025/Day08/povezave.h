#ifndef POVEZAVE_H
#define POVEZAVE_H

#include <vector>

class Povezave {
private:
    //tocka
    struct Tocka {
        int x, y, z;
        long long squaredDistance(const Tocka& other) const;
    };

    //povezava
    struct Edge {
        int a, b;
        long long dist;
        bool operator<(const Edge& other) const;
    };

    // union field
    struct DSU {
        std::vector<int> parent, size;
        int components;

        DSU(int n);
        int find(int x);
        bool unite(int a, int b);   
    };

    std::vector<Tocka> tocke;
    std::vector<Edge> edges;

    void buildEdges();

public:
    void addPoint(int x, int y, int z);

    long long solvePartOne(int connections); 
    long long solvePartTwo();                
};

#endif
