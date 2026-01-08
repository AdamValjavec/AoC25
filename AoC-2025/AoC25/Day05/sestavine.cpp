#include "sestavine.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::string Sestavine::pocisti(const std::string& s) {
    std::string r = s;
    if (!r.empty() && r.back() == '\r') r.pop_back();
    return r;
}

void Sestavine::preberiVhod(const std::string& imeDatoteke) {
    std::ifstream file(imeDatoteke);
    std::string vrstica;

    while (std::getline(file, vrstica)) {
        vrstica = pocisti(vrstica);
        if (vrstica.empty()) break;

        std::stringstream ss(vrstica);
        std::string del;
        std::vector<long long> interval;

        while (std::getline(ss, del, '-')) {
            interval.push_back(std::stoll(del));
        }

        intervali.push_back(interval);
    }

    while (std::getline(file, vrstica)) {
        vrstica = pocisti(vrstica);
        if (!vrstica.empty()) ids.push_back(std::stoll(vrstica));
    }
}

long long Sestavine::prestejSveze() const {
    long long stevec = 0;
    for (long long id : ids) {
        for (const auto& interval : intervali) {
            if (id >= interval[0] && id <= interval[1]) {
                stevec++;
                break;
            }
        }
    }
    return stevec;
}

// Part 2
long long Sestavine::prestejSvezePart2() const {
    if (intervali.empty()) return 0;

   
    std::vector<std::vector<long long>> sortedIntervals = intervali;
    std::sort(sortedIntervals.begin(), sortedIntervals.end(),
              [](const std::vector<long long>& a, const std::vector<long long>& b){
                  return a[0] < b[0];
              });

    long long total = 0;
    long long currentStart = sortedIntervals[0][0];
    long long currentEnd   = sortedIntervals[0][1];

  
    for (size_t i = 1; i < sortedIntervals.size(); ++i) {
        long long start = sortedIntervals[i][0];
        long long end   = sortedIntervals[i][1];

        if (start <= currentEnd + 1) {
            // prekrivanje ali dotik → razširi currentEnd
            if (end > currentEnd) currentEnd = end;
        } else {
            // ni prekrivanja → dodaj dolžino prejšnjega intervala
            total += (currentEnd - currentStart + 1);
            currentStart = start;
            currentEnd   = end;
        }
    }

    // dodaj še zadnji interval
    total += (currentEnd - currentStart + 1);

    return total;
}
