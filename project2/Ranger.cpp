/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 2
*/

#include "Ranger.hpp"

//Default constructor
Ranger::Ranger(): Character(){  //initializes all private members, default character name, race, vitality, armor, level, and enemy
    has_companion_ = false;     //default-initialize boolean to false
}

//Parameterized constructor, default name, race, vitality, armor, level, and enemy use parameterized constructor in character.hpp
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, std::vector<Arrows> arrows, std::vector<std::string> affinities, bool has_companion): Character(name, race, vitality, armor, level, enemy){
    if(arrows.empty()){                                         //If the a vector of arrow provide @param is an empty vector
        arrows_ = std::vector<Arrows>();                        //set the private member arrows_ to an empty vector
    }
    else{                                                       //Else, use a for loop to add all the vaild items in the vector into the character's arrows
        for(int i = 0; i < arrows.size(); i++){ 
            addArrows(arrows[i].type_, arrows[i].quantity_);
        }
    }
    if(affinities.empty()){                                     //If the vector of affinities provide @param is an empty vector
        affinities_ = std::vector<std::string>();               //set the private member affinities_ to an empty vector
    }
    else{
        for(int j = 0; j < affinities.size(); j++){             //Else, use a for loop to add all the vaild items in the vector into the character's affinities
            addAffinity(affinities[j]);
        }
    }
    setCompanion(has_companion);                                //Set the boolean given to the mutator to determine if the character is able to recruit an animal companion
}

bool Ranger::addArrows(const std::string& type, const int& quantity){       //Mutator to add types and/or quantity of the arrows
    if(quantity > 0){                                                       //Quantity of the arrows must be greater than 0 in order to be vaild
        std::string typeUpper = "";                                         //String variable is created to store the string input in uppercase
        for(int i = 0; i < type.size(); i++){                               //Use for loop to convert each alphabet of the input in uppercase
            if(std::isalpha(type[i])){
                typeUpper += toupper(type[i]);

            }
        }
        //After convert the input into uppercase, check if it is vaild to be add as an arrow
        //if uppercase input is [WOOD, FIRE, WATER, POISON, BLOOD], then it's vaild to add
        if(typeUpper == "WOOD" || typeUpper == "FIRE" || typeUpper == "WATER" || typeUpper == "POISON" || typeUpper == "BLOOD"){
            for(int j = 0; j < arrows_.size(); j++){                //Before add the arrow, check the arrow that the character currently had by using a for loop
                if(typeUpper == arrows_[j].type_){                  //If the character already has that type of arrow, then
                    arrows_[j].quantity_ += quantity;               //Update quantity
                    return true;                                    //arrows were added successfully, return true
                }
            }
            Arrows new_arrow;                                       //If the character currently does not have this type of arrow, arrows is add to the vector by creating a new item for the vector
            new_arrow.type_ = typeUpper;
            new_arrow.quantity_ = quantity;
            arrows_.push_back(new_arrow);
            return true;                                            //arrows were added successfully, return true
        }
        else{
            return false;                                           //arrows were not added successfully due to invaild type of arrow, return false
        }
    }
    else{
        return false;                                               //arrows were not added successfully due to invaild quantity, return false
    }
}

std::vector<Arrows> Ranger::getArrows() const{                      //Accessor to get the vector for arrows that character currently have
    return arrows_;                                                 //return to the private member arrows_ to get a vector of the character's arrow
}

bool Ranger::fireArrow(const std::string& type){                    //Mutator fires one arrow if the type of arrow has enough quantity
    std::string typeUpper = "";                                     //String variable is created to store the string input in uppercase
    for(int i = 0; i < type.size(); i++){                           //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(type[i])){
            typeUpper += toupper(type[i]);

        }
    }
    for(int j = 0; j < arrows_.size(); j++){                        //Use for loop to check if the character has the listed arrow
        if(typeUpper == arrows_[j].type_){
            if(arrows_[j].quantity_ > 0 ){                          //If the Character has the listed AND enough quantity to fire one
                arrows_[j].quantity_ -= 1;                          //quantity for that type of arrow is updated in vector
                return true;                                        //the character had the listed arrow AND enough arrows and the arrow was fired successfully, return true
            }
            else{
                return false;                                       //There is not enough arrows, return false
            }
        }
    }
    return false;                                                   //Character does not have the listed arrow, return false
}

bool Ranger::addAffinity(const std::string& affinity){              //Mutator to add affinity
    std::string affinityUpper = "";                                 //String variable is created to store the string input in uppercase
    for(int i = 0; i < affinity.size(); i++){                       //Use for loop to convert each alphabet of the input in uppercase
        if(std::isalpha(affinity[i])){
            affinityUpper += toupper(affinity[i]);

        }
    }
    //After convert the input into uppercase, check if it is vaild to be add as an affinity
    //if uppercase input is [FIRE, WATER, POISON, BLOOD], then it's vaild to add
    if(affinityUpper == "FIRE" || affinityUpper == "WATER" || affinityUpper == "POISON" || affinityUpper == "BLOOD"){
        for(int j = 0; j < affinities_.size(); j++){        //Before add, check if the affinity already exist in character's vector
            if(affinityUpper == affinities_[j]){            //The affinity was already exist
                return false;                               //There should be no duplicate affinities, affinity is not added sucessfully, return false
            }
        }
        affinities_.push_back(affinityUpper);               //affinity does not already exist in the vector, add it to the vector
        return true;                                        //affinity was added successfully, return true
    }
    else{
        return false;                                       //The affinity is invalid, return false
    }
}

std::vector<std::string> Ranger::getAffinities() const{     //Accessor to get the vector for affinities that the character currently have
    return affinities_;                                     //return the to private member affinities_ to get the vector of character's affinity
}

void Ranger::setCompanion(const bool& has_companion){       //Mutator to set whether the character is able to recruit an animal companion
    has_companion_ = has_companion;                         //set the private member variable to the input boolean
}

bool Ranger::getCompanion() const{                          //Accessor to get the boolean of whether the character is able to recruit an animal companion
    return has_companion_;                                  //return to the private member has_companion_ to get whether the character is able to recruit an animal companion
}