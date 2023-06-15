#ifndef POKEDEX_PROJECT_POKEDEX_H
#define POKEDEX_PROJECT_POKEDEX_H

#include <fstream>
#include <algorithm>
#include <iomanip>

#include "Pokemon.h"

class Pokedex {
private:
    char* datapath;

    std::vector<Pokemon> pokemonList;

public:
    explicit Pokedex();
    explicit Pokedex(char* filepath);

    void read_dataset();
    void string_cleaning(std::string& str);
    void line_string(std::string& str);
    void get_ability(std::string& line, std::string& ability, std::string& description);
    void get_info(std::string& line, std::string& str);
};

#endif //POKEDEX_PROJECT_POKEDEX_H