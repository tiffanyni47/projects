/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 4
*/

#include "Tavern.hpp"

/** Default Constructor **/
//since the character is now a abstract class, change it to pointer to the itemtype and other param 
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
1. Name: An uppercase string
2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
4. Level/Vitality/Armor: A positive integer
5. Enemy: 0 (False) or 1 (True)
6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and its quantity are separated with a space.
7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, or if the character is of a different subclass.
8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
    @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/
Tavern::Tavern(const std::string& file){
  std::ifstream file_name(file);   //open the file
  std::string name, race, subclass, main, offhand, school_or_faction, affinity, current_line, current_item;  //creates variable to store each information that was read
  int level, vitality, armor;
  bool is_enemy, has_summon, has_disguise, is_enraged;
  while(std::getline(file_name, current_line)){             //use while loop to read the file line by line
    std::istringstream current_character(current_line);
    std::getline(current_character, current_item, ',');     //each items appears separated by comma, so read until reaching the comma to get each individual items
    name = current_item;

    std::getline(current_character, current_item, ',');
    race = current_item;

    std::getline(current_character, current_item, ',');
    subclass = current_item;

    std::getline(current_character, current_item, ',');
    std::istringstream string_level(current_item);    //convert to int
    string_level >> level;

    std::getline(current_character, current_item, ',');
    std::istringstream string_vitality(current_item); //convert to int
    string_vitality >> vitality;

    std::getline(current_character, current_item, ',');
    std::istringstream string_armor(current_item);    //convert to int
    string_armor >> armor;

    std::getline(current_character, current_item, ',');
    std::istringstream enemy(current_item);           //convert to boolean
    enemy >> is_enemy;

    std::getline(current_character, current_item, ',');
    main = current_item;

    std::getline(current_character, current_item, ',');
    offhand = current_item;

    std::getline(current_character, current_item, ',');
    school_or_faction = current_item;

    std::getline(current_character, current_item, ',');
    std::istringstream summon(current_item);          //convert to boolean
    summon >> has_summon;

    std::getline(current_character, current_item, ',');
    affinity = current_item;                        

    std::getline(current_character, current_item, ',');
    std::istringstream disguise(current_item);        //convert to boolean
    disguise >> has_disguise;

    std::getline(current_character, current_item);
    std::istringstream enraged(current_item);         //convert to boolean
    enraged >> is_enraged;

    //After finished reading the entire line, based one the subclass of the information provide, 
    //used the information that is applicable to the subclass to create the character pointer and stores it in the Tavern
    if(subclass == "MAGE"){ 
      Character * mage = new Mage(name, race, vitality, armor, level, is_enemy, school_or_faction, main, has_summon);
      enterTavern(mage);
    }
    else if(subclass == "BARBARIAN" ){
      Character * barbarian = new Barbarian(name, race, vitality, armor, level, is_enemy, main, offhand, is_enraged);
      enterTavern(barbarian);
    }
    else if(subclass == "SCOUNDREL"){
      Character * scoundrel = new Scoundrel(name, race, vitality, armor, level, is_enemy, main, school_or_faction, has_disguise);
      enterTavern(scoundrel);
    }
    else if(subclass == "RANGER"){        //if the subclass is Ranger, the main, which in Ranger's case is the arrow, and affinity might have multiple items that is separated by ";"
      std::istringstream list_arrow(main);              //use istringstream so the getline function can be apply
      std::istringstream list_affinities(affinity);
      std::vector<Arrows> arrows;                       //create temp vectors for arrows and affinities so it can be used later to set up pointer for ranger
      std::vector<std::string> affinities;
      std::string arrow, temp_affinitiy;
      Arrows new_arrow;                                   //create an temp Arrows item for the Arrows vector
      while(std::getline(list_arrow, arrow, ';')){        //Use while loop and getline function to read information of each arrow
        std::istringstream current_arrow(arrow);          //since arrow type and arrow quantity is separate by space, use istringstream so getline can be apply to read them one by one
        std::getline(current_arrow, current_item, ' '); 
        new_arrow.type_ = current_item;
        std::getline(current_arrow, current_item, ' ');
        new_arrow.quantity_ = stoi(current_item);
        arrows.push_back(new_arrow);                      //After both arrow type and arrow quantity is being read, store them into the temp Arrows item and add the temp Arrows item to the temp Arrow vector
      }
      while(std::getline(list_affinities, temp_affinitiy, ';')){   //Use while loop and getline function to read information of each affinities
        affinities.push_back(temp_affinitiy);                      //Add affinities to the temp affinities vector 
      }
      //Use temp Arrow vector and temp affinities vector and other applicable variable to set up the Character pointer for ranger class and stores it in the Tavern
      Character * ranger = new Ranger(name, race, vitality, armor, level, is_enemy, arrows, affinities, has_summon);
      enterTavern(ranger);
    }
  }
  file_name.close();  //close the file
}


/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}



/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}

/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters(){
  for(int i = 0; i < item_count_; i++){  //Use for loop to go through each character in the Tavern bag
    items_[i]->display();                //use -> operater to access the member function display()
  }
}

/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race (only exact matches to the input string), displays each character's information

*/
void Tavern::displayRace(const std::string& race){
  for(int i = 0; i < item_count_; i++){   //Use for loop to go through each character in the Tavern bag
    if(items_[i]->getRace() == race){     //use the -> operater to access the member function getRace() to see if the character matches the race given
      items_[i]->display();               //if the character is the race given, use the -> operater to access member function display()
    }
  }
}

/**
    @post: Every character in the tavern eats a tainted stew.
*/
void Tavern::taintedStew(){
  for(int i = 0; i < item_count_; i++){    //Use for loop to go through each character in the Tavern bag
    items_[i]->eatTaintedStew();           //use the -> operater to access the member function eatTaintedStew()
  }
}
