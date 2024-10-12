/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 3
*/

#include "Tavern.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
**/
Tavern::Tavern(): ArrayBag<Character>()
{
    level_sum_ = 0;
    enemy_count_ = 0;
}

/** 
    @param: A const reference to a Character entering the Tavern
    @return: returns true if a Character was successfully added to the tavern (i.e. items_), false otherwise
    @post: adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& character){
    if(add(character)){                                         //if the character is added
        level_sum_ += character.getLevel();                     //update level sum by adding character's level to the current level sum
        if(character.isEnemy()){
            enemy_count_++;                                     //update enemy count if the character is an enemy by adding 1
        }
        return true;                                            //the character is being added successfully, return true
    }
    else{
        return false;                                           //the character is not be added successfully, return false
    }
}

/** 
    @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_), false otherwise
    @post: removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& character){
    if(remove(character)){                                      //if the character is being removed
        level_sum_ -= character.getLevel();                     //Update the level sum by subtracting character's level from the current level sum
        if(character.isEnemy()){
            enemy_count_--;                                     //Update the enemy count if the character is an enemy by subtracting 1
        }
        return true;                                            //the character is being removed successfully, return true
    }
    else{
        return false;                                           //the character is not being removed successfully, return false
    }
}

/** 
    @return:  The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum() const{
    return level_sum_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
**/
int Tavern::calculateAvgLevel() const{
    if(item_count_ == 0){                                                    //if item_count is 0, return to item count because you can't divided by 0 to get avg
        return item_count_;
    }
    else{
        double avglevel = (double)level_sum_ / (double)item_count_;         //to calculate avg level, use level sum (sum of all characters's level) to divided by item count (number of characters there are) to find avg
        int rounded_avglevel = round(avglevel);                             //I used double last step because you can round with double so that the final number can be rounded to nearest integer
        return rounded_avglevel;                                            //return to the rounded avg level 
    }
}

/** 
    @return:  The integer enemy count of the Tavern
**/
int Tavern::getEnemyCount() const{
    return enemy_count_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage() const
{
    if(item_count_ == 0){                         //if item_count is 0, return to item count because you can't divided by 0 to get percentage
        return 0.0;
    }
    else{
        double enemy_percentage = (double)enemy_count_ / item_count_;               //to find enemy_percentage, use enemy_count_ (how many enemy there are) to divided by item_count_ (how many character there are)
        double rounded_enemy_percentage = round(enemy_percentage*10000) / 100;      //to rounded up to 2 decimal places, first mutiply the original number by 10000, then round the number, and divided by 100, by that you can keep the number in 2 decimal place
        return rounded_enemy_percentage;                                            //return to rounded enemy percentage
    }
}

/** 
    @param:   A const reference to a string representing a character Race with value in ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
              If the argument string does not match one of the expected race values, the tally is zero. 
    Note: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Tavern::tallyRace(const std::string race) const{
    int tally = 0;                                                      //int variable is initialized to 0 so when the argument string does not matach with the expected race value, the tally will be zero
    for(int i = 0; i < item_count_; i++){                               //use for-loop to go through each characters
        if(items_[i].getRace() == race){                                //If the argument string matches the race that the character had
            tally++;                                                    //add 1 to the int variable
        }
    }
    return tally;                                                       //return to the int variable, which is the tally of the number of characters in the Tavern of the given race
}

    /**
    @post:  Outputs a report of the characters currently in the tavern in the form:
    "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n"
    Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal places.

    Example output: 
    Humans: 3
    Elves: 5
    Dwarves: 8
    Lizards: 6
    Undead: 0

    The average level is: 7
    46.67% are enemies.
    **/
void Tavern::tavernReport() const{
    std::cout << "Humans: " << tallyRace("HUMAN") << "\nElves: " << tallyRace("ELF") << "\nDwarves: " << tallyRace("DWARF") << "\nLizards: " << tallyRace("LIZARD") << "\nUndead: " << tallyRace("UNDEAD");
    std::cout << "\n\nThe average level is: " << calculateAvgLevel() << "\n" << calculateEnemyPercentage() << "% are enemies. \n";
}
