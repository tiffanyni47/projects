/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"
#include <vector>

//Ranger class must have the following type:
struct Arrows{
    std::string type_;      //A string for type of the arrows
    int quantity_;          //An integer for how many arrows left
}; 

class Ranger: public Character{
private:
    //Must have following private member variables
    std::vector<Arrows> arrows_;            //A vector of arrows
    std::vector<std::string> affinities_;   //A vector of affinities (strings)
    bool has_companion_;                    //A boolean for whether a character is able to recruit an animal companion
public:
    //Default Constructors
    Ranger();
    //Parameterized constructor, which contain: a const string for name, a const string for race, an integer for vitality, an integer for armor, an integer for level, a boolean for whether it is an enemy, a vector for arrows, a vector for affinities, and a boolean for whether the character is able to recruit an animal companion
    Ranger(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::vector<Arrows> arrows = std::vector<Arrows>(), std::vector<std::string> affinities = std::vector<std::string>(), bool has_companion = false);
    //Mutators and Accessors
    //For addArrows, there should be a reference to a string representing the type of arrows and an integer for the quantity of arrows @param
    bool addArrows(const std::string& type, const int& quantity);   //return true if the string and integer @param for arrow is valid, false otherwise
    std::vector<Arrows> getArrows() const;                          //For getArrow, it should return to a vector that stores in the private arrows_
    //For fireArrows, there should be a reference to a string representing an type of arrows @param
    bool fireArrow(const std::string& type);                        //return true if the string @param for arrow has enough quantity to fire one arrow and update the vector, false otherwise
    //For addAffinity, there should be a reference to a string representing an affinity @param
    bool addAffinity(const std::string& affinity);                  //return true if the string @param for affinity is valid to add, false otherwise
    std::vector<std::string> getAffinities() const;                 //For getAffinities, it should return to a vector that stores in the private affinities_
    //For setCompanion, there should be a reference to boolean that indicate if the character is able to recruit an animal companion @param
    void setCompanion(const bool& has_companion);                   //sets the private member has_companion_ to value of parameter
    bool getCompanion() const;                                      //return to the private member has_companion_ 
};

#endif