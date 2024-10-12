/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#include "Scoundrel.hpp"

//Default Constructor
Scoundrel::Scoundrel(): Character(){    //initializes all private members, default character name, race, vitality, armor, level, and enemy
    dagger_ = WOOD;                     //Default dagger: WOOD
    faction_ = "NONE";                  //Default faction: "NONE"
    has_disguise_ = false;              //default-initialize boolean to false
}

//Parameterized constructor, default name, race, vitality, armor, level, and enemy use parameterized constructor in character.hpp
Scoundrel::Scoundrel(const std::string &name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string &dagger, const std::string &faction, bool has_disguise): Character(name, race, vitality, armor, level, enemy){
    setDagger(dagger);                          //Set character's type of dagger use the mutator setDagger with the const string given
    faction_ = "NONE"; setFaction(faction);     //Set default faction to "NONE", and determined if the faction given with the const string is vaild to set using the mutator function
    setDisguise(has_disguise);                  //Set the boolean given to the mutator to determine if the character has a disguise
}

void Scoundrel::setDagger(const std::string& dagger){    //mutator to set character's type of dagger
    std::string daggerUpper = "";                        //String variable is created to store the string input in uppercase
    for(int i = 0; i < dagger.size(); i++){              //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(dagger[i])){
            daggerUpper += toupper(dagger[i]);
        }
    }
    //After convert the input into uppercase, check if it is vaild to set as the character's type of dagger
    //If yes then private member dagger_ is set to the type of dagger that the input says
    if(daggerUpper == "BRONZE"){
        dagger_ = BRONZE;
    }
    else if(daggerUpper == "IRON"){
        dagger_ = IRON;
    }
    else if(daggerUpper == "STEEL"){
        dagger_ = STEEL;
    }
    else if(daggerUpper == "MITHRIL"){
        dagger_ = MITHRIL;
    }
    else if(daggerUpper == "ADAMANT"){
        dagger_ = ADAMANT;
    }
    else if(daggerUpper == "RUNE"){
        dagger_ = RUNE;
    }
    else{       //If the input is WOOD or something that is not vaild, the private member dagger_ should be set to WOOD
        dagger_ = WOOD;  
    }
}

std::string Scoundrel::getDagger() const{       //Accessor to get string for the character's type of dagger
    if (dagger_ == BRONZE){                     //return to the string that indicating the character's type of dagger
        return "BRONZE";
    }
    else if(dagger_ == IRON){
        return "IRON";
    }
    else if(dagger_ == STEEL){
        return "STEEL";
    }
    else if(dagger_ == MITHRIL){
        return "MITHRIL";
    }
    else if(dagger_ == ADAMANT){
        return "ADAMANT";
    }
    else if(dagger_ == RUNE){
        return "RUNE";
    }
    else{
        return "WOOD";
    }
}

bool Scoundrel::setFaction(const std::string& faction){     //Mutator to set character's faction 
    std::string factionUpper;                               //String variable is created to store the string input in uppercase
    for(int i = 0; i < faction.size(); i++){                //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(faction[i])){
            factionUpper += toupper(faction[i]);
        }
    }
    //After convert the input into uppercase, check if it is vaild to set as the character's faction
    //if uppercase input is [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], then set the private member variable to the uppercase input
    if(factionUpper == "NONE" || factionUpper == "CUTPURSE" || factionUpper == "SHADOWBLADE" || factionUpper == "SILVERTONGUE"){
        faction_ = factionUpper;
        return true;                        //setting the variable was successful, return true
    }
    else{
        return false;                       //setting the variable was not successful, return false
    }
}

std::string Scoundrel::getFaction() const{      //Accessor to get the string for character's faction
    return faction_;                            //return private member faction_ to get the string that indicating character's faction
}

void Scoundrel::setDisguise(const bool& has_disguise){      //Mutator to set whether the character has a disguise
    has_disguise_ = has_disguise;                           //set the private member variable to the input boolean
} 

bool Scoundrel::hasDisguise() const{                        //Accessor to get the disguise flag
    return has_disguise_;                                   //return to the private member variable has_disguise_ to get whether the character has a disguise
}