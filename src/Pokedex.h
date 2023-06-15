#ifndef POKEDEX_PROJECT_POKEDEX_H
#define POKEDEX_PROJECT_POKEDEX_H

#include <fstream>
#include <algorithm>
#include <map>

#include "Pokemon.h"

class Pokedex {
private:
    char* datapath;

    std::vector<Pokemon> pokemonList;
    std::map<std::string,std::string> abilityMap;

public:
    /** Constructors
     *
     * first: default
     * second:
     * @param filePath a char* that holds the file path to dataset
     */
    explicit Pokedex();
    explicit Pokedex(char* filepath);

    /** read_dataset method
     *  Reads data from dataset file
     */
    void read_dataset();

    /** string_cleaning method
     * Cleans up the passed string variable
     *
     * @param str
     */
    void string_cleaning(std::string& str);

    /** line_cleaning method
     * Cleans up the passed string variable holding a line of data
     *
     * @param str
     */
    void line_cleaning(std::string& str);

    /** get_ability method
     * A method specific to reading abilities from dataset file
     *
     * @param line
     * @param ability a string variable to hold name of ability
     * @param description a string variable to hold description of ability
     */
    void get_ability(std::string& line, std::string& ability, std::string& description);

    /** get_info method
     *  A generic method for reading information from dataset file
     *
     * @param line
     * @param str
     */
    void get_info(std::string& line, std::string& str);
};

#endif //POKEDEX_PROJECT_POKEDEX_H