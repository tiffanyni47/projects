/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

class Mage: public Character{
private: 
    //The Mage class must have the following private member
    std::string school_of_magic_;       //A string that represents their school of magic
    std::string weapon_;                //A string that represents their weapon
    bool can_summon_incarnate_;         //A boolean indicating if they are able to summon an incarnate
public:
    //Default constructor
    Mage();
    //Parameterized Constructor, which contain: a const string for name, a const string for race, an integer for vitality, an integer for armor, an integer for level, a boolean for whether it is an enemy, a const string for school of magic, a const string for weapon, and a boolean for whether the character is able to summon an incarnate, all set to default
    Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& school_of_magic = "NONE", const std::string& weapon = "NONE", bool can_summon_incarnate = false);
    //Mutator and Accessor
    //For setSchool, there should be a reference to a string representing the name of school of magic @param
    bool setSchool(const std::string& school_of_magic);         //return true if the string @param for name of school of magic is valid, false otherwise
    std::string getSchool() const;                              //For getSchool, it should return to a string that indicate character's school of magic that stores in the private member school_of_magic_
    //For setCastingWeapon, there should be a reference to a string representing the character's weapon @param
    bool setCastingWeapon(const std::string& weapon);           //return true if the string @param for weapon is vaild, false otherwise
    std::string getCastingWeapon() const;                       //For getCastingWeapon, it should return to a string that indicate character's weapon that stores in the private member weapon_
    //For setIncarnateSummon, there should be a reference to boolean that indicate if the character can summon a incarnate @param
    void setIncarnateSummon(const bool& can_summon_incarnate);  //sets the private member can_summon_incarnate_ to value of parameter
    bool hasIncarnateSummon() const;                            //return to the private member can_summon_incarnate_ 
};

#endif