#ifndef POKEDEX_PROJECT_POKEMON_H
#define POKEDEX_PROJECT_POKEMON_H

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <iomanip>

class Pokemon {
private:
    std::string name;
    std::string classification;
    std::string altForm;
    bool legend;

    double weight;
    double height;

    // types
    std::string primaryType;
    std::string secondaryType;

    // abilities
    std::vector<std::string> abilities;

    // gender ratio
    double maleRatio;
    double femaleRatio;

    int happinessBase;

    // stats
    std::vector<int> normalStats;
    std::vector<int> EVStats;

    // growth
    int catchRate;
    std::string experienceGrowthRate;
    std::string totalExperience;

    // egg group
    std::string primaryEgg;
    std::string secondaryEgg;
    int eggCycleCount;

    // evolution
    std::string evoLevel;

public:
    explicit Pokemon();

    /** Overloaded equality operator
     * Method that determines whether the passed variable and the Pokemon
     * object are the same
     *
     * @param pokemon variable to be compared
     * @return boolean that returns whether variables are the same
     */
    bool operator==(const Pokemon& pokemon);
    bool operator==(const std::string& pokemon);

    /** Overloaded less than operator
     * Method that determines whether the passed variable is less than
     * the Pokemon object
     *
     * @param pokemon variable to be compared
     * @return boolean that returns whether passed in variable is less than the Pokemon variable
     */
    bool operator<(const Pokemon& pokemon);
    bool operator<(const std::string& pokemon);

    /** Overloaded greater than operator
     * Method that determines whether the passed variable is greater than
     * the Pokemon object
     *
     * @param pokemon variable to be compared
     * @return boolean that returns whether passed in variable is greater than the Pokemon variable
     */
    bool operator>(const Pokemon& pokemon);
    bool operator>(const std::string& pokemon);

    /** set_name method
     * Sets name of Pokemon
     *
     * @param name
     */
    void set_name(const std::string& name);

    /** get_name method
     * Returns name of Pokemon
     *
     * @return string that holds name of Pokemon
     */
    std::string& get_name();

    /** set_classification method
     * Sets classification type of Pokemon
     *
     * @param classification
     */
    void set_classification(const std::string& classification);

    /** set_altForm method
     * Sets alternative form of Pokemon
     *
     * @param altForm
     */
    void set_altForm(const std::string& altForm);

    /** set_legend method
     * Sets legendary status of Pokemon
     */
    void set_legend();

    /** set_height method
     * Set hieght of Pokemon
     *
     * @param height
     */
    void set_height(const double& height);

    /** set_weight method
     * Set weight of Pokemin
     *
     * @param weight
     */
    void set_weight(const double& weight);

    /** set_types method
     * Set primary and secondary types of Pokemon
     *
     * @param primaryTypes
     * @param secondaryTypes
     */
    void set_types(const std::string& primaryAbility, const std::string& secondaryAbility);

    /** set_abilities method
     * Sets abilities of Pokemon
     *
     * @param abilities string vector holding the primary, secondary, hidden, and special event abilities of Pokemon
     */
    void set_abilities(const std::vector<std::string>& abilities);

    /** set_gender_ratio method
     * Sets male and female ratio of Pokemon
     *
     * @param maleRatio
     * @param femaleRatio
     */
    void set_gender_ratios(const double& maleRatio, const double& femaleRatio);

    /** set_happiness_base method
     * Set happiness base level of Pokemon
     *
     * @param happinessBase
     */
    void set_happiness_base(const int& happinessBase);

    /** set_normal_stats method
     * Set normal stats of Pokemon
     *
     * @param stats a integer vector that holds the following stats:
     * Health, Attack, Defense, Special Attack, Special Defense, Speed, Base Total
     */
    void set_normal_stats(const std::vector<int>& stats);

    /** set_EV_stats
     * Set EV stats of Pokemon
     *
     * @param EVStats a integer vector that holds the following stats:
     * Health EV, Attack EV, Defense EV, Special Attack EV, Special Defense EV, Speed EV, EV Total Yield
     */
    void set_EV_stats(const std::vector<int>& EVStats);

    /** set_catch_rate method
     * Set catch rate of Pokemon
     *
     * @param catchRate
     */
    void set_catch_rate(const int& catchRate);

    /** set_experience method
     * Set experience growth rate and total experience of Pokemon
     *
     * @param experienceGrowth
     * @param totalExperience
     */
    void set_experience(const std::string& experienceGrowth, const int& totalExperience);

    /** set_egg_info method
     * Set primary and secondary egg group and egg cycle count of Pokemon
     *
     * @param primaryEgg string that holds primary egg group of Pokemon
     * @param secondaryEgg string that holds prinmary egg group of Pokemon
     * @param eggCycleCount integer that holds number of steps needed for Pokemon egg to hatch
     */
    void set_egg_info(const std::string& primaryEgg, const std::string& secondaryEgg, const int& eggCycleCount);

    /** set_evol_level method
     * Set evolution level of Pokemon
     *
     * @param evlLevel
     */
    void set_evol_level(const std::string& evlLevel);

    friend std::ostream& operator<<(std::ostream& inOS, const Pokemon& pokemon);
};

#endif //POKEDEX_PROJECT_POKEMON_H