/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character{
private:
    //Barbarian class must have following private member 
    std::string main_weapon_;           //A string representing character's main weapon
    std::string secondary_weapon_;      //A string representing character's offhand weapon
    bool enraged_;                      //A boolean indicating if the character is enraged
public:
    //Default constructor
    Barbarian();
    //Parameterized constructor, which contain: a const string for name, a const string for race, an integer for vitality, an integer for armor, an integer for level, a boolean for whether it is an enemy, a const string for main weapon, a const string for offhand weapon, and a boolean for whether the character is enraged
    Barbarian(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& main_weapon = "NONE", const std::string& secondary_weapon = "NONE", bool enraged = false);
    //For setMainWeapon, there should be a reference to a string representing character's main weapon @param
    bool setMainWeapon(const std::string& main_weapon);                 //return true if the string @param for character's main weapon is valid, false otherwise
    std::string getMainWeapon() const;                                  //For getMainWeapon, it should return to a string that indicate character's main weapon that stores in the private member main_weapon_
    //For setSecondaryWeapon, there should be a reference to a string representing character's offhand weapon @param
    bool setSecondaryWeapon(const std::string& secondary_weapon);       //return true if the string @param for character's offhand weapon is valid, false otherwise
    std::string getSecondaryWeapon() const;                             //For getSecondaryWeapon, it should return to a string that indicate character's offhand weapon that stores in the private member secondary_weapon_
    //For setEnrage, there should be a reference to boolean that indicate whether the character is enraged @param
    void setEnrage(const bool& enraged);                                //sets the private member enraged_ to value of parameter
    bool getEnrage() const;                                             //return to the private member enraged_ 
    void toggleEnrage();                                                //sets the private member enraged_ to the opposite of what it is
};

#endif