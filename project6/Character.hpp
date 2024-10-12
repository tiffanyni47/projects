/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 6
modify the given Character.hpp 
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <algorithm>

enum Race
{
    NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD
};

enum Action 
{
    BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato
};

struct Buff
{
    std::string name_;
    int turns_; //the number of turns this Buff will last for
};

class Character
{
    public:
        /**
            Default constructor.
            Default-initializes all private members. 
            Default character name: "NAMELESS". 
            Booleans are default-initialized to False. 
            Default enum value: NONE. 
            Default Vitality, Max Armor, and Level: 0.
        */
        Character();

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
        */
        Character(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);

        virtual ~Character() = default;

        /**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed.
        */
        void setName(const std::string& name);


        /**
            @return : the name of the Character
        */
        std::string getName() const;


        /**
            @param  : the race of the Character (a string)
            @post   : sets the Character's race to the value of the parameter
                    : If the given race was invalid, set race_ to NONE.
        */
        void setRace(const std::string& race);


        /**
            @return : the race of the Character (a string)
        */
        std::string getRace() const;


        /**
            @param  : an integer vitality
            @pre    : vitality >= 0 : Characters cannot have negative health
            @post   : sets the vitality private member to the value of the parameter
        */
        void setVitality(const int& vitality);


        /**
            @return : the value stored in vitality_
        */
        int getVitality() const;

        /**
            @param  : an integer armor level
            @pre    : armor >= 0 : Characters cannot have negative armor
            @post   : sets the armor private member to the value of the parameter\
        */
        void setArmor(const int& armor);


        /**
            @return : the value stored in armor_
        */
        int getArmor() const;

        /**
            @param  : an integer level
            @pre    : level >= 0 : Characters cannot have a negative
            @post   : sets the level private member to the value of the parameter
        */
        void setLevel(const int& level);


        /**
            @return : the value stored in level_
        */
        int getLevel() const;

        /**
            @post   : sets the enemy flag to true
        */
        void setEnemy();

        /**
            @return true if the character is an enemy, false otherwise

        Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
        */
        bool isEnemy() const;


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
        bool operator==(const Character& rhs) const;

        /**
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
        */
        bool operator!=(const Character& rhs) const;

        /**
         @post     : displays Character data in the form:
        "[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
        */
        void display() const;

        /**
        @pre: This function is called to execute the Action BUFF_Heal
        @post: Increases the character's vitality by 2
        */
        void heal();

        /**
        @pre: This function is called to execute the Action BUFF_MendMetal
        @post: Increases the character's armor by 2
        */
        void mendMetal();

        /**
        @pre: This function is called to execute the Action ATT_Strike
        @param: A pointer to a character target
        @post: Deals 2 points of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they lose 1 vitality point.
        */
        void strike(Character* target);

        /**
        @pre: This function is called to  execute the Action ATT_ThrowTomato
        @param: A pointer to a character target
        @post: Deals 1 point of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they don't lose any vitality points. Your character gains 1 vitality point (as laughter is the best medicine).
        */
        void throwTomato(Character* target);

        /**
         * @post helper mutator that adds actions to character's action queue
         * @param action 
         */
        void setActionQueue(Action action);

        /**
         * @post helper mutator that pop the action out of the action queue
         */
        void popActionQueue();

        /**
         * @post helper mutator that pop the action out of the buff stack
         */
        void popBuffStack();

        /**
         * @post helper mutator that decrements the turns of the first buff in the buff stack
         */
        void decrementTurnsinBuff();

        /**
        helper getter to get the private member action_queue_
         * @return private member std::queue<int> action_queue_
         */
        std::queue<int> getActionQueue();

        /**
        helper getter to get the private member buff_stack_
         * @return private member std::stack<Buff> buff_stack_
         */
        std::stack<Buff> getBuffStack();

    private:
        //The name of the character (a string in UPPERCASE)
        std::string name_;
        // The race of the character (an enum)
        Race race_;
        // The character's vitality (a non-negative integer)
        int vitality_;
        // The character's max armor level (a non-negative integer)
        int armor_;
        // The character's level (a non-negative integer)
        int level_;
        // A flag indicating whether the character is an enemy
        bool enemy_;
        //a queue of integers to store actions a character wants to take during their turn (as integers that correspond to the enum Action) 
        std::queue<int> action_queue_;
        //a stack of Buff objects the character can use during their turn
        std::stack<Buff> buff_stack_;
};

#endif