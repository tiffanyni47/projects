/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 4
*/

#include "Ranger.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/
Ranger::Ranger() : Character(), has_companion_{false}
{
    arrows_.clear();
    affinities_.clear();
}

/**
    Parameterized constructor.
	@param      : The name of the character (a const string reference)
	@param      : The race of the character (a const string reference)
	@param      : The character's vitality (an integer)
	@param      : The character's max armor level (an integer)
	@param      : The character's level (an integer)
	@param      : A flag indicating whether the character is an enemy
	@param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
				  Lowercase valid arrow types are retained but converted to uppercase.
				  Invalid arrows are those with non-positive quantities or invalid types.
				  If the vector contains invalid arrows, those arrows are discarded. 
	@param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
				  String inputs can be in lowercase, but must be converted to uppercase.
  				  If the vector contains invalid affinities, those affinities are discarded.
	@param      : A flag indicating whether the character is able to recruit an animal companion
	@post       : The private members are set to the values of the corresponding parameters
*/
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, std::vector<Arrows> arrows, std::vector<std::string> affinities, bool has_companion)
: Character(name, race, vitality, armor, level, enemy), has_companion_{has_companion}
{
    setArrows(arrows);
    for (std::string affinity : affinities)
    {
        addAffinity(affinity);
    }
}

/**
    @param  : a reference to a vector representing the Character's arrows
    @post   : appends arrows to the private data member
**/
void Ranger::setArrows(const std::vector<Arrows>& arrows)
{
    for(Arrows arrow : arrows)
    {
        addArrows(arrow.type_, arrow.quantity_);
    }
}

/**
    @return  : a vector of the Character's arrows
**/
std::vector<Arrows> Ranger::getArrows() const
{
    return arrows_;
}

/**
    @param  	: a reference to string representing the arrow type
    @param  	: a reference to an integer quantity
    @post   	: If the character already has that type of arrow, the quantity in the vector 
				  is updated. If not, the arrow is added to the vector. 
            	  Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
            	  Lowercase valid arrow types are retained but converted to uppercase.
            	  Quantity of arrows must be greater than 0
				  Invalid arrows are those with non-positive quantities or invalid types.
				  If the arrows are invalid, they are not added.
    @return  	: True if the arrows were added successfully, false otherwise
**/
bool Ranger::addArrows(const std::string& type, const int& quantity)
{
    std::string type_upper = type;
    //turn type to uppercase
    for(int i = 0; i<type_upper.size(); i++)
    {
        if(isalpha(type_upper[i]))
        {
            type_upper[i] = toupper(type_upper[i]);
        }
    }
    //check if valid type
    if((type_upper != "WOOD" && type_upper != "FIRE" && type_upper != "WATER" && type_upper != "POISON" && type_upper != "BLOOD") || quantity < 1)
    {
        return false;
    }
    //check if type already exists and increment
     for (int i = 0; i < arrows_.size(); i++)
     {
        if(arrows_[i].type_ == type_upper)
        {
            arrows_[i].quantity_ += quantity;
            return true;
        }

     }
    // otherwise add new arrow type
    Arrows new_arrow;
    new_arrow.type_ = type_upper;
    new_arrow.quantity_ = quantity;
    arrows_.push_back(new_arrow);
    return true;      
}

/**
    @param  : a reference to string representing the arrow type
    @post   : If the character has the listed arrow AND enough arrows to fire one, the quantity of remaining arrows in the vector is updated.
    @return : True if the character had the listed arrow AND enough arrows, False otherwise.
**/
bool Ranger::fireArrow(const std::string& type)
{
    std::string type_upper = type;
    for(char& c : type_upper)
    {
        if(isalpha(c))
        {
            c = toupper(c);
        }
    }
    for(Arrows& arrow : arrows_)
    {
        if(arrow.type_ == type_upper)
        {
            if(arrow.quantity_ > 0)
            {
                arrow.quantity_--;
                return true;
            }
        }
    }
    return false;
}

/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
			  String inputs can be in lowercase, but must be converted to uppercase when 
			  setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/
bool Ranger::addAffinity(const std::string& affinity)
{
    std::string aff_upper = affinity;
    //convert to uppercase
    for(int i = 0; i<aff_upper.size();i++)
    {
        if(isalpha(aff_upper[i]))
        {
            aff_upper[i] = toupper(aff_upper[i]);
        }
    }
    // check if valid
    if(aff_upper == "FIRE" || aff_upper == "WATER" || aff_upper == "POISON" || aff_upper == "BLOOD")
    {
        //check if already exists don't add
        for(std::string aff : affinities_)
        {
            if(aff == aff_upper)
            {
                return false;
            }
        }
        //otherwise add
        affinities_.push_back(aff_upper);
        return true;
    }
    return false;
}


/**
    @return  : a vector of the Character's affinities
**/
std::vector<std::string> Ranger::getAffinities() const
{
    return affinities_;
}

/**
    @param  : a reference to a boolean indicating whether the character is able to recruit an animal companion
    @post   : sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(const bool& has_companion)
{
    has_companion_ = has_companion;
}

/**
    @return  : a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const
{
    return has_companion_;
} 

/**
    @post     : displays Ranger data in the form:
    "[NAME] is a Level [LEVEL] [RACE] RANGER.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nAnimal Companion: [TRUE/FALSE]
    \nArrows:
    \n[ARROW TYPE]: [QUANTITY]
    \nAffinities: [AFFINITY1], [AFFINITY2],..., [AFFINITYN]
    \n\n"
    
    Example:
    MARROW is a Level 6 UNDEAD RANGER.
    Vitality: 9
    Armor: 4
    They are not an enemy.
    Animal Companion: TRUE
    Arrows:
    WOOD: 30
    FIRE: 5
    Affinities: FIRE, POISON
*/
void Ranger::display() 
{
    std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " RANGER." 
    << "\nVitality: " << getVitality() 
    << "\nArmor: " << getArmor()
    << "\nThey are " << (isEnemy() ? "an enemy." : "not an enemy.")
    << "\nAnimal Companion: " << (has_companion_ ? "TRUE" : "FALSE")
    << "\nArrows: ";
    if(arrows_.size() == 0){                        //If character has no arrows, print none
        std::cout << "NONE";
    }
    else{
        for(int i = 0; i < arrows_.size(); i++){
            std::cout << "\n" << arrows_[i].type_ << ": " << arrows_[i].quantity_;      //Use for loop to print out the arrow that the character had one by one
        }
    }
    std::cout << "\nAffinities: ";
    if(affinities_.size() == 0){                    //If character has no arrows, print none
        std::cout << "NONE";
    }
    else{
        for(int j = 0; j < affinities_.size(); j++){        //Use for loop to print out the affinities that the character had one by one
            if (j == affinities_.size()-1 ){
                std::cout << affinities_[j];
            }
            else{
                std::cout << affinities_[j] << ", ";
            }
        }
    }
    std::cout << "\n\n";
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens. 

    If the character is NOT UNDEAD and, as a Ranger has POISON affinity, their Vitality is halved (round down to the nearest integer).
    Otherwise (not UNDEAD and not POISON affinity), their Vitality is set to 1.
    Whether the not UNDEAD Ranger has POISON affinity or not, if they have an animal companion, the emotional support allows the character to recover 1 Vitality point. 
*/
void Ranger::eatTaintedStew() 
{
    int current_vitality = getVitality();       //get the character's current vitality
    if(getRace() == "UNDEAD"){                  //If the character is undead
        current_vitality += 3;                  //Add 3 to current vitality and do nothing else
    }
    else{                                       //If character is not undead
        bool contain_poison = false;                  //Create a boolean for whether the Character has poison affinitiy
        for(int i = 0; i < affinities_.size(); i++){  //Use for loop to check the affinities that Character currently have
            if(affinities_[i] == "POISON"){
                contain_poison = true;                //There is a poison affinity, set the boolean true
            }
        }
        if(contain_poison == true){                   //If there are a poison affinity, the character's vitality get halved and round down
            current_vitality /= 2;
        }
        else{                                         //If there are no poison affinity, set vitality to 1
            current_vitality = 1;                   
        }
        if(has_companion_ == true){                   //If character have animal companion, add 1 to current vitality 
        current_vitality++;
        }
    }
    setVitality(current_vitality);                    //Set Character's vitality
}
