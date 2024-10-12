/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#include "Mage.hpp"

//Default constructor
Mage::Mage(): Character(){          //initializes all private members, default character name, race, vitality, armor, level, and enemy
    school_of_magic_ = "NONE";      //default school of magic to "NONE"
    weapon_ = "NONE";               //default weapon to "NONE"
    can_summon_incarnate_ = false;  //default-initialize boolean to false
}

//Parameterized constructor, default name, race, vitality, armor, level, and enemy use parameterized constructor in character.hpp
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate): Character(name, race, vitality, armor, level, enemy){
    school_of_magic_ = "NONE"; setSchool(school_of_magic);  //Set default school of magic name to "NONE", and determined if the school name given with the const string is vaild to set using the mutator function
    weapon_ = "NONE"; setCastingWeapon(weapon);             //Set default weapon name to "NONE", and determined if the weapon name given with the const string is vaild to set using the mutator function
    setIncarnateSummon(can_summon_incarnate);               //Set the boolean given to the mutator to determine if the character is able to summon an incarnate
}

bool Mage::setSchool(const std::string& school_of_magic){  //mutator to set the character's school of magic 
    std::string schoolUpper = "";                          //String variable is created to store the string input in uppercase
    for(int i = 0; i < school_of_magic.size(); i++){       //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(school_of_magic[i])){
            schoolUpper += toupper(school_of_magic[i]);
        }
    }
    if(schoolUpper != ""){                                                                              //After convert the input into uppercase, check if it is vaild to set as the character's school
        if (schoolUpper == "ELEMENTAL" || schoolUpper == "NECROMANCY" || schoolUpper == "ILLUSION" ){   //if uppercase input is [ELEMENTAL, NECROMANCY, ILLUSION], then
            school_of_magic_ = schoolUpper;                                                             //sets the private member variable to the uppercase input 
            return true;                                                                                //setting the variable was successful, return true
        }
        else{
            return false;                                                                               //The uppercase is not one of the vaild string, setting the variable was not successful, return false
        }
    }
    else{
        return false;                                                                                   //The inputs does not contain any alphabet, setting the variable was not successful, return false
    }
}

std::string Mage::getSchool() const{     //Accessor to get the string for Character's school of magic
    return school_of_magic_;             //return to the private member school_of_magic_ to get the string indicating character's school of magic
}

bool Mage::setCastingWeapon(const std::string& weapon){         //Mutator to set Character's weapon
    std::string weaponUpper = "";                               //String variable is created to store the string input in uppercase
    for(int i = 0; i < weapon.size(); i++){                     //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(weapon[i])){
            weaponUpper += toupper(weapon[i]);
        }
    }
    if(weaponUpper != ""){                                      //After convert the input into uppercase, check if it is vaild to set as the character's weapon
        if(weaponUpper == "WAND" || weaponUpper == "STAFF"){    //if uppercase input is [WAND, STAFF], then
            weapon_ = weaponUpper;                              //sets the private member variable to the uppercase input 
            return true;                                        //setting the variable was successful, return true
        }
        else{
            return false;                                       //The uppercase is not one of the vaild string, setting the variable was not successful, return false
        }
    }
    else{
        return false;                                           //The inputs does not contain any alphabet, setting the variable was not successful, return false
    }
}

std::string Mage::getCastingWeapon() const{     //Accessor to get the string for Character's weapon
    return weapon_;                             //return to private member weapon_ to get the string indicating character's weapon
}

void Mage::setIncarnateSummon(const bool& can_summon_incarnate){    //mutator to set whether the character is able to summon an incarnate
    can_summon_incarnate_ = can_summon_incarnate;                   //set the private member variable to the input boolean
}

bool Mage::hasIncarnateSummon() const{      //Accessor to get the summon-incarnate flag
    return can_summon_incarnate_;           //return to the private member can_summon_incarnate_ to get whether the character is able to summon an incarnate
}