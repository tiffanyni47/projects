/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP

#include "Character.hpp"

//Scoundrel class must have the following type:
enum Dagger{WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel: public Character{
private:
    //Must have following private member variable
    Dagger dagger_;          //A dagger
    std::string faction_;    //A string that represents their Faction
    bool has_disguise_;      //A boolean indicating if they have disguise
public:
    //Default constructor
    Scoundrel();
    //Parameterized constructor, which contain: a const string for name, a const string for race, an integer for vitality, an integer for armor, an integer for level, a boolean for whether it is an enemy, a const string for dagger, a const string for faction, and a boolean for whether the character has a disguise, all set to default
    Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& dagger = "WOOD", const std::string& faction = "NONE", bool has_disguise = false);
    //Mutator and Accessor
    //For setDagger, there should be a reference to a string representing the type of dagger @param
    void setDagger(const std::string& dagger);      //set the string @param for the type of dagger if it is valid, if not vaild then set the variable to wood
    std::string getDagger() const;                  //For getDagger, it should return to a string that indicate type of dagger that stores in the private member dagger_
    //For setFaction, there should be a reference to a string representing the Faction of the character @param
    bool setFaction(const std::string& faction);    //return true if the string @param for character's faction is valid, false otherwise
    std::string getFaction() const;                 //For getFaction, it should return to a string that indicate character's faction that stores in the private member faction_
    //For setDisguise, there should be a reference to boolean that indicate if the character has a disguise @param
    void setDisguise(const bool& has_disguise);     //sets the private member has_disguise_ to value of parameter
    bool hasDisguise() const;                       //return to the private member has_disguise_ 
};

#endif