/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 1
*/

#include "Character.hpp"

Character::Character(){      //Default constructor, Default-initializes all private members. 
    name_ = "NAMELESS";      //Set the default character name to be "NAMELESS"
    enemy_ = false;          //Set booleans to false
    race_ = NONE;            //Set the default enum to NONE
    vitality_ = 0;           //Set default vitality value to 0
    armor_ = 0;              //Set default armor value to 0
    level_ = 0;              //Set default level to 0
}
Character::Character(std::string name, std::string race, int vitality, int armor, int level, bool enemy){  //Parameterized constructor
    setName(name);                           //The name of the character
    setRace(race);                           //The race of the character
    setVitality(vitality);                   //Character's vitality, with default value 0
    setArmor(armor);                         //Character's max armor level, with default value 0
    setLevel(level);                         //Character's level, with default value 0
    if(enemy == true){                       //A flag indicating whether a character is enemy, default value false
        setEnemy();
    }
}

void Character::setName(const std::string& name){   //mutator for name of the character
    std::string new_name = "";                      //new string variable created to hold all uppercase letters in the input name
    char current_char;                              //create a Char variable to keep on track of each letter in the name of the input
    for (int i = 0; i < name.length(); i++){        //using a for loop to check each letter in the input of the name
        current_char = name[i];
        if(isalpha(current_char)){                  //check if the letter is an alphabet
            if(isupper(current_char)){              //check if the letter is Uppercase
                new_name = new_name + current_char; //if yes then add to the new string variable
            }
            else{
                current_char = toupper(current_char); //if not, change it to uppercase and then add the to new string variable
                new_name = new_name + current_char;
            }
        }
    }
    if (new_name == ""){
        new_name = "NAMELESS";
    }
    name_ = new_name;                                //private member name_ has been set
}

std::string Character::getName() const{             //Accessor for Character name
    return name_;                                   //return to the string stored in private member name_
}

void Character::setRace(const std::string& race){   //Mutators for Race
    if (race == "HUMAN"){                           //Sets the Character's race to the value of the parameter.
        race_ = HUMAN;                           
    }
    else if(race == "ELF"){
        race_ = ELF;                             
    }
    else if(race == "DWARF"){
        race_ = DWARF;
    }                           
    else if(race == "LIZARD"){
        race_ = LIZARD;                          
    }
    else if(race == "UNDEAD"){
        race_ = UNDEAD;                         
    }
    else{
        race_ = NONE;                              //If the given race was invalid or is NONE, set race_ to NONE.
    }
}

std::string Character::getRace() const{             //Accessor for Race
    if(race_ == NONE){                                 //Return the race of the Character in string instead of in enum value
        return "NONE";                              
    }
    else if(race_ == HUMAN){
        return "HUMAN";
    }
    else if(race_ == ELF){
        return "ELF";
    }
    else if(race_ == DWARF){
        return "DWARF";
    }
    else if(race_ == LIZARD){
        return "LIZARD";
    }
    else if(race_ == UNDEAD){
        return "UNDEAD";
    }
    else{
        return "NONE";
    }
}

void Character::setVitality(const int& vitality){  //Mutator for vitality
    if(vitality >= 0){                             //if the input vitality is greater than or equal to 0, the private member vitality_ will be set as the input vitality
        vitality_ = vitality;
    }                                              //else, do nothing
}

int Character::getVitality() const{                //Accessor for vitality
    return vitality_;                              //Just return the value stored in the private member vitality_
}

void Character::setArmor(const int& armor){        //Mutator for Max Armor level
    if(armor >= 0){                                //if the input armor is greater than or equal to 0, the private member armor_ will be set as the input armor
        armor_ = armor;                            
    }                                              //else, do nothing
}

int Character::getArmor() const{                  //Accessor for armor
    return armor_;                                //Just return the value stored in the private member armor_ 
}

void Character::setLevel(const int& level){       //Mutator for level
    if(level >= 0){                               //if the input level is greater than or equal to 0, the private member level_ will be set as the input vitality
        level_ = level;                           
    }                                             //else, do nothing

}

int Character::getLevel() const{                 //Accessor for level
    return level_;                               //Just return to the value stored in private member level_
}

void Character::setEnemy(){                     //Mutator to indicate whether the flag is enemy or not
    enemy_ = true;                              //set enemy flag to true
}

bool Character::isEnemy() const{                //Accessor for enemy
    return enemy_;                              //If enemy_ is true, return true. If enemy_ is false, return false.
}