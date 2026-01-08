#include "ura.h"

Ura::Ura() : pozicija(50), stevec(0) {
    // začetna pozicija 50
}

// ===== 1. STOPNJA =====
void Ura::rotacijaStopnja1(char smer, int razdalja) {
    if (smer == 'R') {
        pozicija = (pozicija + razdalja) % 100;
    } 
    else if (smer == 'L') {
        pozicija = (pozicija - razdalja) % 100;
        if (pozicija < 0) pozicija += 100;
    }

    if (pozicija == 0) {
        stevec++;
    }
}

// ===== 2. STOPNJA =====
void Ura::rotacijaStopnja2(char smer, int razdalja) {
    if (smer == 'R') {
        for (int i = 0; i < razdalja; i++) {
            pozicija = (pozicija + 1) % 100;
            if (pozicija == 0) {
                stevec++;
            }
        }
    } 
    else if (smer == 'L') {
        for (int i = 0; i < razdalja; i++) {
            pozicija = (pozicija - 1 + 100) % 100;
            if (pozicija == 0) {
                stevec++;
            }
        }
    }
}

int Ura::getStevec() const {
    return stevec;
}
