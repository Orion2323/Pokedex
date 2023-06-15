#include "Pokedex.h"

Pokedex::Pokedex() {
    this->datapath = nullptr;
}

Pokedex::Pokedex(char* filepath) {
    this->datapath = filepath;
}

void Pokedex::read_dataset() {
    if (this->datapath == nullptr) {
        throw std::runtime_error("Database has not been passed in!");
    }

    // open file
    std::ifstream inFS(this->datapath);
    if (inFS.is_open()) {
        std::string headers;
        getline(inFS, headers, '\n');

        while (!inFS.eof()) {
            std::string line;
            getline(inFS, line, '\n');
            this->line_string(line);
            Pokemon newPokemon;

            /** Pokedex ID **/
            std::string ID = line.substr(0, line.find(','));
            line.erase(0, ID.size() + 1);

            /** Pokedex Number **/
            std::string num = line.substr(0, line.find(','));
            line.erase(0, num.size() + 1);

            /** Name **/
            std::string name;
            this->get_info(line, name);
            newPokemon.set_name(name);

            /** Classification **/
            std::string classification;
            this->get_info(line, classification);
            newPokemon.set_classification(classification);

            /** Alternative Form **/
            std::string altForm;
            this->get_info(line, altForm);
            newPokemon.set_altForm(altForm);

            /** Original ID **/
            std::string orgID = line.substr(0, line.find(','));
            line.erase(0, orgID.size() + 1);

            /** Legendary Status **/
            std::string legend = line.substr(0, line.find(','));
            line.erase(0, legend.size() + 1);
            if (legend != "NULL") {
                newPokemon.set_legend();
            }

            /** Height **/
            std::string height = line.substr(0, line.find(','));
            line.erase(0, height.size() + 1);
            newPokemon.set_height(std::stod(height));

            /** Weight **/
            std::string weight = line.substr(0, line.find(','));
            line.erase(0, weight.size() + 1);
            newPokemon.set_height(std::stod(weight));

            /** Primary type **/
            std::string primary;
            this->get_info(line, primary);

            /** Secondary Type **/
            std::string secondary;
            this->get_info(line, secondary);
            newPokemon.set_types(primary, secondary);

            /** Abilities **/
            std::vector<std::string> abilities;

            /** Primary Ability and Description **/
            std::string primAbility;
            std::string primDescript;
            this->get_ability(line, primAbility, primDescript);
            abilities.push_back(primAbility);

            /** Secondary Ability and Description **/
            std::string secAbility;
            std::string secDescript;
            this->get_ability(line, secAbility, secDescript);
            abilities.push_back(secAbility);

            /** Hidden Ability and Description **/
            std::string hidAbility;
            std::string hidDescript;
            this->get_ability(line, hidAbility, hidDescript);
            abilities.push_back(hidAbility);

            /** Special Event Ability and Description **/
            std::string specAbility;
            std::string specDescript;
            this->get_ability(line, specAbility, specDescript);
            abilities.push_back(specAbility);

            newPokemon.set_abilities(abilities);

            /** Gender Ratio **/
            std::string maleRatio = line.substr(0, line.find(','));
            line.erase(0, maleRatio.size() + 1);

            std::string femRatio = line.substr(0, line.find(','));
            line.erase(0, femRatio.size() + 1);
            newPokemon.set_gender_ratios(std::stod(maleRatio), std::stod(femRatio));

            /** Happiness Base **/
            std::string baseHappy = line.substr(0, line.find(','));
            line.erase(0, baseHappy.size() + 1);
            newPokemon.set_happiness_base(std::stoi(baseHappy));

            /** Origin Game **/
            std::string orgGame;
            this->get_info(line, orgGame);

            /** Normal Stats **/
            std::vector<int> stats;
            std::string stat;
            for (int i = 0; i < 7; i++) {
                stat = line.substr(0, line.find(','));
                line.erase(0, stat.size() + 1);
                stats.push_back(std::stoi(stat));
            }
            newPokemon.set_normal_stats(stats);

            /** EV Stats **/
            std::vector<int> evStats;
            std::string evStat;
            for (int i = 0; i < 7; i++) {
                evStat = line.substr(0, line.find(','));
                line.erase(0, evStat.size() + 1);
                evStats.push_back(std::stoi(evStat));
            }
            newPokemon.set_EV_stats(evStats);

            /** Catch Rate **/
            std::string catchRate = line.substr(0, line.find(','));
            line.erase(0, catchRate.size() + 1);
            newPokemon.set_catch_rate(std::stoi(catchRate));

            /** Growth Rate **/
            std::string expGrowth;
            this->get_info(line, expGrowth);

            /** Total Experience **/
            std::string expGrowthTotal;
            this->get_info(line, expGrowthTotal);
            newPokemon.set_experience(expGrowth, std::stoi(expGrowthTotal));

            /** Primary Egg Group **/
            std::string primEggGroup;
            this->get_info(line, primEggGroup);

            /** Secondary Egg Group **/
            std::string secEggGroup;
            this->get_info(line, secEggGroup);

            /** Egg Cycle Count **/
            std::string eggCycleCount = line.substr(0, line.find(','));
            line.erase(0, eggCycleCount.size() + 1);
            newPokemon.set_egg_info(primEggGroup, secEggGroup, std::stoi(eggCycleCount));

            /** Previous Evolution ID **/
            std::string prevEvlID = line.substr(0, line.find(','));
            line.erase(0, prevEvlID.size() + 1);

            /** Evolution Level **/
            std::string evlvl = line.substr(0, line.find('\r'));
            line.erase(0, evlvl.size() + 1);
            this->string_cleaning(evlvl);

            this->pokemonList.push_back(newPokemon);
        }
    } else {
        std::cout << "File is not open!" << std::endl;
    }

    std::cout << this->pokemonList.size() << std::endl;
}

void Pokedex::string_cleaning(std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\"' || str[i] == '\\') {
            str.erase(str.begin() + i);
        }
    }
}

void Pokedex::line_string(std::string& line) {
    int counter = 0;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '\"'  && counter < 2) {
            line.erase(line.begin() + i);
            counter++;
        }

        if (counter >= 2) {
            counter = 0;
        }
    }
}

void Pokedex::get_info(std::string& line, std::string& str) {
    str = line.substr(0, line.find(','));
    line.erase(0, str.size() + 1);
    this->string_cleaning(str);
}

void Pokedex::get_ability(std::string& line, std::string& ability, std::string& description) {
    if (line.substr(0,4) != "NULL") {
        line.erase(0,1);
        ability = line.substr(0, line.find('\"'));
        line.erase(0, ability.size() + 3);

        description = line.substr(0, line.find('\"'));
        line.erase(0, description.size() + 2);
    } else {
        ability = line.substr(0, line.find(','));
        line.erase(0, ability.size() + 1);

        description = line.substr(0, line.find(','));
        line.erase(0, description.size() + 1);
    }

    this->string_cleaning(ability);
    this->string_cleaning(description);
}