/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#include "Barbarian.hpp"

//Default constructor
Barbarian::Barbarian(): Character(){    //initializes all private members, default character name, race, vitality, armor, level, and enemy
    main_weapon_ = "NONE";              //Default Weapons: "NONE"
    secondary_weapon_ = "NONE";
    enraged_ = false;                   //default-initialize boolean to false
}

//Parameterized constructor, default name, race, vitality, armor, level, and enemy use parameterized constructor in character.hpp
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, bool enraged): Character(name, race, vitality, armor, level, enemy){
    main_weapon_ = "NONE"; setMainWeapon(main_weapon);                      //Set default main weapon name to "NONE", and determined if the main weapon name given with the const string is vaild to set using the mutator function
    secondary_weapon_ = "NONE"; setSecondaryWeapon(secondary_weapon);       //Set default offhand weapon name to "NONE", and determined if the offhand weapon name given with the const string is vaild to set using the mutator function
    setEnrage(enraged);                                                     //Set the boolean given to the mutator to determine if the character is enraged
}

bool Barbarian::setMainWeapon(const std::string& main_weapon){      //Mutator to set Character's main weapon
    std::string main_weapon_upper;                                  //String variable is created to store the string input in uppercase
    for(int i = 0; i < main_weapon.size(); i++){                    //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(main_weapon[i])){
            main_weapon_upper += toupper(main_weapon[i]);
        }
        else{
            return false;                                           //Only alphabetical characters are allowed, setting the variable was not successful, return false
        }
    }
    if(main_weapon_upper != ""){                                    //If every letter was convert to uppercase for the input, then it is a vaild input
        main_weapon_ = main_weapon_upper;                           //set the private member main_weapon_ to the uppercase input
        return true;                                                //setting the variable was successful, return true
    }
    else{
        return false;                                               //If the input after converted to uppercase was empty, then it is not a vaild input, setting the variable was not successful, return false
    }
}

std::string Barbarian::getMainWeapon() const{                       //Accessor to get the string for Character's main weapon
    return main_weapon_;                                            //return to private member main_weapon_ to get the string indicating character's main weapon
}

bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon){       //Mutator to set Character's offhand weapon
    std::string secondary_weapon_upper;                                        //String variable is created to store the string input in uppercase
    for(int i = 0; i < secondary_weapon.size(); i++){                          //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(secondary_weapon[i])){
            secondary_weapon_upper += toupper(secondary_weapon[i]);
        }
        else{
            return false;                                                      //Only alphabetical characters are allowed, setting the variable was not successful, return false
        }
    }
    if(secondary_weapon_upper != ""){                                          //If every letter was convert to uppercase for the input, then it is a vaild input
        secondary_weapon_ = secondary_weapon_upper;                            //set the private member secondary_weapon_ to the uppercase input
        return true;                                                           //setting the variable was successful, return true
    }
    else{
        return false;                                                          //If the input after converted to uppercase was empty, then it is not a vaild input, setting the variable was not successful, return false
    }
}

std::string Barbarian::getSecondaryWeapon() const{                             //Accessor to get the string for Character's offhand weapon
    return secondary_weapon_;                                                  //return to private member secondary_weapon_ to get the string indicating character's offhand weapon
}

void Barbarian::setEnrage(const bool& enraged){                                //Mutator to set the whether the character is enraged
    enraged_ = enraged;                                                        //set the private member variable to the input boolean
}

bool Barbarian::getEnrage() const{                                             //Accessor to get whether the character is enraged
    return enraged_;                                                           //return to the private member enraged_ to get whether the character is enraged
}

void Barbarian::toggleEnrage(){                                                //Mutator to set the enraged variable to opposite of what it is 
    if(enraged_ == true){
        enraged_ = false; 
    }
    else{
        enraged_ = true;
    }
}