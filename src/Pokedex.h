#ifndef POKEDEX_PROJECT_POKEDEX_H
#define POKEDEX_PROJECT_POKEDEX_H

#include <fstream>
#include <algorithm>

#include "Pokemon.h"

class Pokedex {
private:
    char* datapath;

public:
    explicit Pokedex();
    explicit Pokedex(char* filepath);

    void read_dataset();
    void string_cleaning(std::string& str);

};

#endif //POKEDEX_PROJECT_POKEDEX_H