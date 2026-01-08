#include "baterije.h"
#include <sstream>
using namespace std;


// Stopnja 1

bool Baterije::podvojena1(long long n) {
    string s = to_string(n);
    int dolzina = s.size();
    
    int polovica = dolzina / 2;
    string a = s.substr(0, polovica);
    string b = s.substr(polovica);

    return a == b;
}

void Baterije::obdelajVrstico1(const string& line) {
    stringstream ss(line);
    string interval;

    while (getline(ss, interval, ',')) {
        if (interval.empty()) continue;

        size_t znak = interval.find('-');
        string left = interval.substr(0, znak);
        string right = interval.substr(znak + 1);

        long long a = stoll(left);
        long long b = stoll(right);

        for (long long i = a; i <= b; i++) {
            if (podvojena1(i)) invalidIDs.push_back(i);
        }
    }
}


// Stopnja 2

bool Baterije::podvojena2(long long n) {
    string s = to_string(n);
    int dolzina = s.size();

    for (int l = 1; l <= dolzina / 2; ++l) {
        string vzorec = s.substr(0, l);
        int ponovitev = dolzina / l;
        string c = "";
        for (int i = 0; i < ponovitev; ++i) c += vzorec;
        if (c == s && ponovitev >= 2) return true;
    }
    return false;
}

void Baterije::obdelajVrstico2(const string& line) {
    stringstream ss(line);
    string interval;

    while (getline(ss, interval, ',')) {
        if (interval.empty()) continue;

        size_t znak = interval.find('-');
        string left = interval.substr(0, znak);
        string right = interval.substr(znak + 1);

        long long a = stoll(left);
        long long b = stoll(right);

        for (long long i = a; i <= b; i++) {
            if (podvojena2(i)) invalidIDs.push_back(i);
        }
    }
}


// Vsota

long long Baterije::vsota() const {
    long long sum = 0;
    for (auto v : invalidIDs) sum += v;
    return sum;
}
