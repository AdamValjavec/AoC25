#ifndef PLOSCE_H
#define PLOSCE_H

#include <vector>
#include <string>
#include <map>

struct Tocka {
    long long x;
    long long y;
};

enum Tip {
    PRAZNO,
    RDECE,
    ZELENO
};

class Plosce {
private:
    std::vector<Tocka> tocke;


    long long max_povrsina_prvi;

    std::vector<long long> xs, ys;
    std::map<long long, int> x_id, y_id;
    std::vector<std::vector<Tip>> mreza;
    long long max_povrsina_drugi;

    void zgradiKompresijo();
    void zgradiMrezo();
    void narisiRob();
    void zapolniNotranjost();
    bool pravokotnikVeljaven(const Tocka& a, const Tocka& b);

public:
    Plosce();

    void preberiInput(const std::string& imeDatoteke);

    void resiPrviDel();
    void resiDrugiDel();

    long long vrniMaxPovrsinoPrviDel() const;
    long long vrniMaxPovrsinoDrugiDel() const;
};

#endif
