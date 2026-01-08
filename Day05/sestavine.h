#ifndef SESTAVINE_H
#define SESTAVINE_H

#include <vector>
#include <string>

class Sestavine {
private:
    std::vector<std::vector<long long>> intervali; 
    std::vector<long long> ids;

    static std::string pocisti(const std::string& s);

public:
    void preberiVhod(const std::string& imeDatoteke);
    long long prestejSveze() const;              
    long long prestejSvezePart2() const;          
};

#endif
