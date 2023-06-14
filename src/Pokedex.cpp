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
            std::string ID;
            getline(inFS, ID, ',');

            std::string num;
            getline(inFS, num, ',');

            std::string name;
            getline(inFS, name, ',');
            this->string_cleaning(name);

            std::string classification;
            getline(inFS, classification, ',');
            this->string_cleaning(classification);

            std::string altForm;
            getline(inFS, altForm, ',');
            this->string_cleaning(altForm);

            std::string orgID;
            getline(inFS, orgID, ',');

            std::string legend;
            getline(inFS, legend, ',');

            std::string height;
            getline(inFS, height, ',');
            std::string weight;
            getline(inFS, weight, ',');

            // element type
            std::string primary;
            getline(inFS, primary, ',');
            this->string_cleaning(primary);
            std::string secondary;
            getline(inFS, secondary, ',');
            this->string_cleaning(secondary);

            // abilities
            std::string primAbility;
            getline(inFS, primAbility, ',');
            this->string_cleaning(primAbility);

            std::string primDescript;
            getline(inFS, primDescript, ',');
            this->string_cleaning(primDescript);

            std::string secAbility;
            getline(inFS, secAbility, ',');
            this->string_cleaning(secAbility);
            std::string secDescript;
            getline(inFS, secDescript, ',');
            this->string_cleaning(secDescript);

            std::string hidAbility;
            getline(inFS, hidAbility, ',');
            this->string_cleaning(hidAbility);
            std::string hidDescript;
            getline(inFS, hidDescript, ',');
            this->string_cleaning(hidDescript);

            std::string specAbility;
            getline(inFS, specAbility, ',');
            this->string_cleaning(specAbility);
            std::string specDescript;
            getline(inFS, specDescript, ',');
            this->string_cleaning(specDescript);

            // gender
            std::string maleRatio;
            getline(inFS, maleRatio, ',');
            std::string femRatio;
            getline(inFS, femRatio, ',');

            std::string baseHappy;
            getline(inFS, baseHappy, ',');
            std::string orgGame;
            getline(inFS, orgGame, ',');
            this->string_cleaning(orgGame);

            // stats
            std::vector<std::string> stats;
            std::string stat;
            for (int i = 0; i < 7; i++) {
                getline(inFS, stat, ',');
                stats.push_back(stat);
            }

            // EV stats
            std::vector<std::string> evStats;
            std::string evStat;
            for (int i = 0; i < 7; i++) {
                getline(inFS, evStat, ',');
                evStats.push_back(evStat);
            }

            std::string catchRate;
            getline(inFS, catchRate, ',');

            std::string expGrowth;
            getline(inFS, expGrowth, ',');
            this->string_cleaning(expGrowth);
            std::string expGrowthTotal;
            getline(inFS, expGrowthTotal, ',');

            // egg numbers
            std::string primEggGroup;
            getline(inFS, primEggGroup, ',');
            this->string_cleaning(primEggGroup);
            std::string secEggGroup;
            getline(inFS, secEggGroup, ',');
            this->string_cleaning(secEggGroup);
            std::string eggCycleCount;
            getline(inFS, eggCycleCount, ',');

            // evolution
            std::string prevEvlID;
            getline(inFS, prevEvlID, ',');
            std::string evlvl;
            getline(inFS, evlvl, ',');
            this->string_cleaning(evlvl);
        }
    } else {
        std::cout << "File is not open!" << std::endl;
    }
}

void Pokedex::string_cleaning(std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\"' || str[i] == '\\') {
            str.erase(str.begin() + i);
        }
    }
}