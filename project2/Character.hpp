/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 1
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include <cctype>

class Character{
private:
    std::string name_;
    enum Race{NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;
public:
    //Constructors
    Character();
    //Parameterized constructor
    Character(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
    // Mutators and Accessors
    void setName(const std::string& name);
    std::string getName() const;
    void setRace(const std::string& race);
    std::string getRace() const;
    void setVitality(const int& vitality);
    int getVitality() const;
    void setArmor(const int& armor);
    int getArmor() const;
    void setLevel(const int& level);
    int getLevel() const;
    void setEnemy();
    bool isEnemy()const;
};

#endif