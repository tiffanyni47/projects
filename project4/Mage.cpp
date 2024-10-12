/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 4
*/

#include "Mage.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default school of magic and weapon: "NONE". 
*/
Mage::Mage() : Character(), school_of_magic_{"NONE"}, weapon_{"NONE"}, can_summon_incarnate_{false}
{
}

/**
    Parameterized constructor.
    @param      : The name of the character (a string)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer)
    @param      : The character's max armor level (an integer)
    @param      : The character's level (an integer)
    @param      : A flag indicating whether the character is an enemy
    @param      : The character's school of magic (a string). Valid schools: [ELEMENTAL, NECROMANCY, ILLUSION]. 
                 String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                 If the school name is invalid, set it to "NONE"
    @param      : The character's choice of weapon (a string). Valid weapons: [WAND, STAFF]
                  String inputs can be in lowercase, but must be converted to 
				  uppercase when setting the variable.
				  If the weapon is invalid, set it to "NONE"
    @param      : A flag indicating whether the character is able to summon an incarnate
    @post       : The private members are set to the values of the corresponding parameters.
                  If the school of magic or weapon is not provided or valid, the variables should be set to "NONE". 
*/
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate) 
: Character(name, race, vitality, armor, level, enemy), can_summon_incarnate_{can_summon_incarnate}
{
    if (!setSchool(school_of_magic))
    {
        school_of_magic_ = "NONE";
    }
    if(!setCastingWeapon(weapon))
    {
        weapon_ = "NONE";
    }
}

/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. 
              If the provided school of magic is not one of the following: [ELEMENTAL, NECROMANCY, ILLUSION], 
              do nothing and return false.
              String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string& school_of_magic)
{
    std::string school_upper = school_of_magic;
    for(int i = 0;i<school_of_magic.size();i++)
    {
        if(isalpha(school_of_magic[i]))
        {
            school_upper[i] = toupper(school_of_magic[i]); 
        }
    }
    if(school_upper == "ELEMENTAL" || school_upper == "NECROMANCY" || school_upper == "ILLUSION")
    {
        school_of_magic_ = school_upper;
        return true;
    }
    else
    {
        return false;
    }
}


/**
    @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const
{
    return school_of_magic_;
}


/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter. 
              String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
              If the provided weapon is not one of the following: [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon)
{
    std::string weapon_upper = weapon;
    for(int i = 0;i<weapon.size();i++)
    {
        if(isalpha(weapon[i]))
        {
            weapon_upper[i] = toupper(weapon[i]); 
        }
    }
    if(weapon_upper == "WAND" || weapon_upper == "STAFF")
    {
        weapon_ = weapon_upper;
        return true;
    }
    else
    {
        return false;
    }
}


/**
    @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const
{
    return weapon_;
}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character can summon an incarnate
**/
void Mage::setIncarnateSummon(const bool& can_summon_incarnate)
{
    can_summon_incarnate_ = can_summon_incarnate;
}

/**
    @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const
{
    return can_summon_incarnate_;
}

/**
    @post     : displays Mage data in the form:
    "[NAME] is a Level [LEVEL] [RACE] MAGE.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nSchool of Magic: [SCHOOL]
    \nWeapon: [WEAPON]
    \nThey [can/cannot] summon an Incarnate.
    \n\n"
    
    Example:
    SPYNACH is a Level 4 ELF MAGE.
    Vitality: 6
    Armor: 4
    They are not an enemy.
    School of Magic: ILLUSION
    Weapon: WAND
    They can summon an Incarnate.
*/
void Mage::display() 
{
    std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " MAGE." 
    << "\nVitality: " << getVitality() 
    << "\nArmor: " << getArmor()
    << "\nThey are " << (isEnemy() ? "an enemy." : "not an enemy.")
    << "\nSchool of Magic: " << getSchool()
    << "\nWeapon: " << getCastingWeapon()
    << "\nThey " << (can_summon_incarnate_ ? "can" : "cannot" ) << " summon an Incarnate."
    << "\n\n";
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
    
    If the character is NOT UNDEAD, Vitality is set to 1. 
    In addition, as a Mage: 
    If the character is equipped with a wand or staff, they cast a healing ritual and recover vitality points – 2 points with a wand, 3 with a staff.
    If they can summon an incarnate, the emotional support allows the character to recover 1 Vitality point.
*/
void Mage::eatTaintedStew() 
{
    int current_vitality = getVitality();       //get the character's current vitality
    if(getRace() == "UNDEAD"){                  //If the character is undead
        current_vitality += 3;                  //Add 3 to current vitality, nothing else happens
    }
    else{
        current_vitality = 1;                   //If the character is not undead, set the vitality current to 1
        if(getCastingWeapon() == "WAND"){           //If the character is equipped with a Wand, they recover 2 vitality points
            current_vitality += 2;                  //Add 2 to current vitality
        }
        if(getCastingWeapon() == "STAFF"){     //If the character is equipped with a staff, they recover 3 vitality points
            current_vitality += 3;                  //Add 3 to current vitality
        }
        if(can_summon_incarnate_ == true){           //If character can summon an incarnate, they recover 1 vitality points
            current_vitality++;                     //Add 1 to current vitality
        }
    }
    setVitality(current_vitality);              //Set the result current vitality to character's vitality
}
