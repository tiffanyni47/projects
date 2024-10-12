/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 6
modify the given Character.cpp
*/

#include "Character.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default enum value: NONE. 
    Default Vitality, Max Armor, and Level: 0.
*/
Character::Character():name_{"NAMELESS"},race_{NONE},vitality_{0},armor_{0},level_{0},enemy_{false}
{
}

/**
Parameterized constructor.
    @param      : The name of the character (a string in UPPERCASE)
    @param      : The race of the character (a string)
    @param      : The character's vitality (a non-negative integer) , with default value 0
    @param      : The character's max armor level (a non-negative integer), with default value 0
    @param      : The character's level (a non-negative integer), with default value 0
    @param      : A flag indicating whether the character is an enemy, with default value false
    @post       : The private members are set to the values of the corresponding parameters. 
                Hint: Notice the default arguments in the parameterized constructor.
                If the given parameters are invalid, the default values are used instead.
*/
Character::Character(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy) : Character()
{
    setName(name); // checks valid name
    setRace(race); // checks valid race
    (vitality >= 0) ? vitality_ = vitality: vitality_ = 0;
    (armor >= 0) ? armor_ = armor: armor_ = 0;
    (level >= 0) ? level_ = level: level_ = 0;
    enemy_ = enemy; 
}

 /**
    @param  : the name of the Character
    @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed. For example, attempting to create a character named "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
    : If the given parameter does not have any valid alphabetical characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string& name)
{
    std::string nameUpper = "";
    for(int i = 0; i<name.size();i++)
    {
        if(std::isalpha(name[i]))
        {
            nameUpper+= toupper(name[i]);
        }
    }
    if(nameUpper != "")
    {
        name_ = nameUpper;
    }
    else
    {
        name_ = "NAMELESS";
    }
}


/**
    @return : the name of the Character
*/
std::string Character::getName() const
{
    return name_;
}


/**
    @param  : the race of the Character (a string)
    @post   : sets the Character's race to the value of the parameter. Valid races: [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
            : If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string& race)
{
    
    if(race == "HUMAN")
    {
        race_ = HUMAN;
    }
    else if(race == "ELF")
    {
        race_ = ELF;
    }
    else if(race == "DWARF")
    {
        race_ = DWARF;
    }
    else if(race == "LIZARD")
    {
        race_ = LIZARD;
    }
    else if(race == "UNDEAD")
    {
        race_ = UNDEAD;
    }
    else
    {
        race_ = NONE;
    }
}


/**
    @return : the race of the Character (a string)
*/
std::string Character::getRace() const
{
    if (race_ == Race::HUMAN)
    {
        return "HUMAN";
    }
    else if (race_ == Race::ELF)
    {
        return "ELF";
    }
    else if (race_ == Race::DWARF)
    {
        return "DWARF";
    }
    else if (race_ == Race::LIZARD)
    {
        return "LIZARD";
    }
    else if (race_ == Race::UNDEAD)
    {
        return "UNDEAD";
    }
    else
    {
        return "NONE";
    }

}


/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
void Character::setVitality(const int& vitality)
{
    if (vitality >= 0)
    {
        vitality_ = vitality;
    }
}


/**
    @return : the value stored in vitality_
*/
int Character::getVitality() const
{
    return vitality_;
}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
void Character::setArmor(const int& armor)
{
    if (armor >= 0)
    {
        armor_ = armor;
    }
}


/**
    @return : the value stored in armor_
*/
int Character::getArmor() const
{
    return armor_;
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/
void Character::setLevel(const int& level)
{
    if (level >= 0)
    {
        level_ = level;
    }
}


/**
    @return : the value stored in level_
*/
int Character::getLevel() const
{
    return level_;
}

/**
    @post   : sets the enemy flag to true
*/
void Character::setEnemy()
{
    enemy_ = true;
}

/**
    @return true if the character is an enemy, false otherwise

Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
*/
bool Character::isEnemy() const
{
    return enemy_;
}



/**
        @param     	: A reference to the right hand side of the == operator.
        @return     : Returns true if the right hand side character is "equal", false otherwise. 									
                     Two characters are equal if they have the same name, same race, same level 									
                     and are either both an enemy or not.

        Note: By this definition, only some of the character's attributes must be equal for two characters to be deemed "equal".

        Example: In order for character1 to be == to character2 we only need:
        - The same name
        - The same race
         - The same level
        - They must either be both an enemy or not
*/
bool Character::operator==(const Character& rhs) const
{
    return(name_ == rhs.getName() && getRace() == rhs.getRace() && level_ == rhs.getLevel() && enemy_ == rhs.isEnemy());
}

/**
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
*/
bool Character::operator!=(const Character& rhs) const
{
    return(!(*this == rhs));
}

/**
 @post     : displays Character data in the form:
"[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
*/
void Character::display() const
{
    std::cout<<name_<<" is a Level "<<level_<<" "<<getRace()<<
    ". \nVitality: "<<vitality_<<
    "\nMax Armor: "<<armor_<<" \n"<<
    (enemy_ ? "They are an enemy.\n" : "They are not an enemy.\n");
}

/**
@pre: This function is called to execute the Action BUFF_Heal
@post: Increases the character's vitality by 2
*/
void Character::heal()
{
    vitality_+=2;

}

/**
@pre: This function is called to execute the Action BUFF_MendMetal
@post: Increases the character's armor by 2
*/
void Character::mendMetal()
{
    armor_+=2;
}

/**
@pre: This function is called to execute the Action ATT_Strike
@param: A pointer to a character target
@post: Deals 2 points of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they lose 1 vitality point.
*/
void Character::strike(Character* target)
{
    if(target->armor_ >= 2){                //if target has greater than or equal to 2 armor point, the armor will absorb the damage and depleted by 2
        target->armor_ -=2;
    }
    else if(target->armor_ == 1){           //else if target only has 1 armor point, the armor will depleted by 1 and vitality will also depleted by 1 (since armor is 0 after it absorb 1 points of damage)
        target->armor_ --;
        target->vitality_ --;
    }
    else{
        target->vitality_ -=2;              //else target does not have armor point at all, then vitality will depleted by 2
        if(target->getVitality() < 0){      //if target ended up have vitality less than 0, set the vitality back to 0
            target->setVitality(0);
        }
    }

}

/**
@pre: This function is called to execute the Action ATT_ThrowTomato
@param: A pointer to a character target
@post: Deals 1 point of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they don't lose any vitality points. Your character gains 1 vitality point (as laughter is the best medicine).
*/
void Character::throwTomato(Character* target)
{
    if(target->armor_ >= 1){        //if target has a armor greater or equal to 1, it will absorbs the damage and depleted by 1
        target->armor_ --;
    }
    else{
        target->vitality_ --;       //with no armor, target will lose 1 vitality point
    }
    vitality_ ++;                   //character who throws the tomato will gain 1 vitality point, as laughter is the best medicine
}
/**
 * Helper mutator
 * @post add action to action queue of the Character, if the action is a buff then add the correspond buff to the buff stack
 * @param action 
 */
void Character::setActionQueue(Action action)
{
    if(action == BUFF_Heal){
        action_queue_.push(0);              // 0 correspond to the Buff_Heal of enum Action
    }
    else if(action == BUFF_MendMetal){
        action_queue_.push(1);              // 1 correspond to the Buff_MendMetal of enum Action
    }
    else if(action == ATT_Strike){
        action_queue_.push(2);              // 2 correspond to the ATT_Strike of enum Action
    }
    else if(action == ATT_ThrowTomato){
        action_queue_.push(3);              // 3 correspond to the ATT_ThrowTomato of enum Action
    }
}

/**
 * Helper mutator
   @post pop out the first item in the action_queue_
 */
void Character::popActionQueue()
{
    action_queue_.pop();
}

/**
 * Helper mutator
 * @post pop out the first item in the buff_stack_
 */
void Character::popBuffStack()
{
    buff_stack_.pop();
}

/**
 * Helper mutator
 * @post decrement the turn of the first item of buff_stack_ by one
 */
void Character::decrementTurnsinBuff()
{
    buff_stack_.top().turns_--;
}

/**
   Helper getter
   @return to the private member action_queue_
 */
std::queue<int> Character::getActionQueue()
{
    return action_queue_;
}

/**
   Helper getter
   @return to the private member buff_stack_
 */
std::stack<Buff> Character::getBuffStack()
{
    return buff_stack_;
}
