#ifndef URA_H
#define URA_H

class Ura {
private:
    int pozicija;
    int stevec;

public:
    Ura();  // konstruktor

    // 1. stopnja – šteje samo, če je kazalec na 0 PO rotaciji
    void rotacijaStopnja1(char smer, int razdalja);

    // 2. stopnja – šteje vsak klik, ki pristane na 0
    void rotacijaStopnja2(char smer, int razdalja);

    int getStevec() const;
};

#endif
