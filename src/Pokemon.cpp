#include "Pokemon.h"

Pokemon::Pokemon() {
    this->legend = false;

    this->weight = 0.0;
    this->height = 0.0;

    this->maleRatio = 0.0;
    this->femaleRatio = 0.0;

    this->happinessBase = 0;

    this->catchRate = 0;
    this->eggCycleCount = 0;
}

void Pokemon::set_name(const std::string& name) {
    this->name = name;
}

void Pokemon::set_classification(const std::string& classification) {
    this->classification = classification;
}

void Pokemon::set_altForm(const std::string& altForm) {
    this->altForm = altForm;
}

void Pokemon::set_legend() {
    this->legend = true;
}

void Pokemon::set_height(const double& height) {
    this->height = height;
}

void Pokemon::set_weight(const double& weight) {
    this->weight = weight;
}

void Pokemon::set_types(const std::string& primaryType, const std::string& secondaryType) {
    if (primaryType != "NULL") {
        this->primaryType = primaryType;
    }

    if (secondaryType != "NULL")
    this->secondaryType = secondaryType;
}

void Pokemon::set_abilities(const std::vector<std::string>& abilities) {
    this->abilities = abilities;
}

void Pokemon::set_gender_ratios(const double& maleRatio, const double& femaleRatio) {
    this->maleRatio = maleRatio;
    this->femaleRatio = femaleRatio;
}

void Pokemon::set_happiness_base(const int& happinessBase) {
    this->happinessBase = happinessBase;
}

void Pokemon::set_normal_stats(const std::vector<int>& stats) {
    this->normalStats = stats;
}

void Pokemon::set_EV_stats(const std::vector<int>& EVStats) {
    this->EVStats = EVStats;
}

void Pokemon::set_catch_rate(const int& catchRate) {
    this->catchRate = catchRate;
}

void Pokemon::set_experience(const std::string& experienceGrowth, const int& totalExperience) {
    this->experienceGrowthRate = experienceGrowth;
    this->totalExperience = totalExperience;
}

void Pokemon::set_egg_info(const std::string& primaryEgg, const std::string& secondaryEgg, const int& eggCycleCount) {
    this->primaryEgg = primaryEgg;
    this->secondaryEgg = secondaryEgg;
    this->eggCycleCount = eggCycleCount;
}

void Pokemon::set_evol_level(const std::string& evlLevel) {
    this->evoLevel = evlLevel;
}