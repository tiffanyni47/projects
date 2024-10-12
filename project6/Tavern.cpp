/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 6
modify the given Tavern.cpp
*/

#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
    Tavern::Tavern(const std::string& filename)
    {
      std::ifstream fin(filename);
      std::string line;
      std::getline(fin, line);
      std::string name, race, string_vitality, string_armor, string_level, string_enemy;
      int vitality, armor, level;
      bool enemy;
      
      while(std::getline(fin, line))
      {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, race, ',');

        std::getline(iss, string_vitality, ',');
        std::istringstream(string_vitality) >> vitality;

        std::getline(iss, string_armor, ',');
        std::istringstream(string_armor) >> armor;

        std::getline(iss, string_level, ',');
        std::istringstream(string_level) >> level;

        std::getline(iss, string_enemy, ',');
        std::istringstream(string_enemy) >> enemy;
        Character* character = new Character(name, race, vitality, armor, level, enemy);
        enterTavern(character);
      }
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
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {
    items_[i]->display();
  }
}


/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {
      items_[i]->display();
    }
  }
}


/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}

/**
  @param: a Character pointer 
  @post: sets the Tavern's main character to the pointer that is given
*/
void Tavern::setMainCharacter(Character *character)
{
  main_character = character;
}

/**
  @return: a pointer to the main character in the Tavern, nullptr if there is no main character
*/
Character *Tavern::getMainCharacter() const
{
  if(contains(main_character)){
    return main_character;
  }
  else{
    return nullptr;
  }
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(Character *character_lhs, Character *character_rhs)
{
  if(character_lhs->getLevel() < character_rhs->getLevel()){
    return true;
  }
  else{
    return false;
  }
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is greater than the rhs Character's level
*/
bool Tavern::levelIsGreater(Character *character_lhs, Character *character_rhs)
{
  if(character_lhs->getLevel() > character_rhs->getLevel()){
    return true;
  }
  else{
    return false;
  }
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is less than the rhs Character's vitality
*/
bool Tavern::vitalityIsLess(Character *character_lhs, Character *character_rhs)
{
  if(character_lhs->getVitality() < character_rhs->getVitality()){
    return true;
  }
  else{
    return false;
  }
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(Character *character_lhs, Character *character_rhs)
{
  if(character_lhs->getVitality() > character_rhs->getVitality()){
    return true;
  }
  else{
    return false;
  }
}

/**
  @pre  : The combat queue should be emptied before the characters are added to the queue
  @param  : A string reference to a sorting filter with a default value of "NONE"
  @post   : With default filter "NONE": add every character marked as an enemy to the combat queue
    : With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
    : With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
    : With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
    : With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
void Tavern::createCombatQueue(const std::string &filter)
{
  combat_queue_ = {};                          //combat queue is emptied
  std::vector<Character*> enemies = {};        //Create a temp vector to store all the enemies in the Tavern
  for(int i = 0; i < item_count_; i++){        //Use for loop to check all characters in the Tavern one by one, if the character is an enemy, add it to the temp vector
    if(items_[i]->isEnemy() == true){
      enemies.push_back(items_[i]);            
    }
  }
  //With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
  if(filter == "LVLASC"){
    std::sort(enemies.begin(), enemies.end(), 
    [this] (Character* character_lhs, Character* character_rhs)
    {
      return levelIsLess(character_lhs, character_rhs);
    });
  }
  //With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
  else if(filter == "LVLDES"){
    std::sort(enemies.begin(), enemies.end(), 
    [this] (Character* character_lhs, Character* character_rhs)
    {
      return levelIsGreater(character_lhs, character_rhs);
    });
  }
  //With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
  else if(filter == "HPASC"){
    std::sort(enemies.begin(), enemies.end(), 
    [this] (Character* character_lhs, Character* character_rhs)
    {
      return vitalityIsLess(character_lhs, character_rhs);
    });
  }
  //With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
  else if(filter == "HPDES"){
    std::sort(enemies.begin(), enemies.end(), 
    [this] (Character* character_lhs, Character* character_rhs)
    {
      return vitalityIsGreater(character_lhs, character_rhs);
    });
  }
  //With default filter "NONE" or something else, add every character marked as an enemy to the combat queue
  else{
    std::sort(enemies.begin(), enemies.end());
  }
  //after done sorting the temp vector, add all items in the temp vector into the combat_queue_ using for loop
  for(int j = 0; j < enemies.size(); j++){
    combat_queue_.push(enemies[j]);
  }
}

/**
  @post   : returns a pointer to the Character at the front of the Combat Queue. 
          : If there are no characters in the queue, return nullptr
*/
Character* Tavern::getTarget() const
{
  if(!combat_queue_.empty()){
    return combat_queue_.front();     // combat_queue_ is not empty, return to the character at front of the combat_queue_
  }
  else{
    return nullptr;                   // combat_queue_ is empty, return to nullptr
  }
}

/**
  @post : Prints the details of each character in the combat queue in the following form:
        (ENEMY)[ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue()
{
  std::queue<Character*> temp = combat_queue_;   //create a temp queue and copy all the items that stores in the combat_queue_
  while(!temp.empty()){                          //use while loop to print details of each character in the combat queue
  //print the detail of the character in front of the temp, then pop it out, repeat the action until the temp queue is empty
    Character* current_char = temp.front();
    std::cout << "(ENEMY) " << current_char->getName() << ": LEVEL " << current_char->getLevel() << " " << current_char->getRace() << ". "
    << "\nVITALITY: " << current_char->getVitality() 
    << "\nARMOR: " << current_char->getArmor() << "\n";
    temp.pop();                                 
  }
}
/** THE FOLLOWING FUNCTIONS WILL MANAGE THE COMBAT - YOU SHOULD CONSIDER HOW THESE WILL AFFECT THE CHARACTERS AND WHAT ADDITIONAL MEMBER FUNCTION YOU NEED TO IMPLEMENT IN THE CHARACTER CLASS TO SUPPORT THESE ACTIONS */

/** 
        @post : If there are no enemies in the combat queue, do nothing.
              : Otherwise do all of the following
              :     - The action queue must be emptied before the new actions are added.
              :     - Print out the start of turn and details of the target enemy in the form:
                      : YOUR TURN\n
                      : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 
    
              :     - Repeat the following process thrice (i.e. read three actions from input): 
              :           - Print the actions that are available to the main character, and read 
                            a non-negative number from input, corresponding to an action. 
                            Printing the available options should be of the following form. 
                            You may consider writing a helper function for this.
                            :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
              :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                          keep prompting for a non-negative number that is within range, by
                          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
              :           - When a valid action is read, 
                          it is added to the main character's action queue.    
*/
void Tavern::actionSelection()
{
  if(!combat_queue_.empty()){                               //if the combat is not empty, do the following
    Character* enemy = getTarget();                         //create a Character pointer to store the information of the enemy that's in front of the combat_queue
    while(!main_character->getActionQueue().empty()){       //action queue must be emptied before new actions are add, use while loop to pop out all the items in action_queue_ until the action_queue is empty
      main_character->popActionQueue();
    }
    //Print out the start of turns and details of targer enemy
    std::cout << "YOUR TURN\n";
    std::cout << "(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
    << "\nVITALITY: " << enemy->getVitality() 
    << "\nARMOR: " << enemy->getArmor() << "\n\n";
    //since we are getting action from input, use the while loop to ensure that character has get 3 valid input and was all successfully added to action_queue
    while(main_character->getActionQueue().size() < 3){    //if action_queue_ has less than 3 actions, it will keep prompting for more actions
      int action_chosen;
      std::cout << "Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n";
      std::cin >> action_chosen;
      while (action_chosen > 4 || action_chosen < 1)       //valid input are 1-4, use while loop to keep prompting for a valid input if an invalid input has been enter
      {
        std::cout << "Invalid input. Please enter a number between 1 and 4 inclusive.\n";
        std::cin >> action_chosen;
      }
      //according to the number that the user entered, add the correspond action to the action_queue 
      if (action_chosen == 1){
        main_character->setActionQueue(BUFF_Heal);
      }
      else if(action_chosen == 2){
        main_character->setActionQueue(BUFF_MendMetal);
      }
      else if(action_chosen == 3){
        main_character->setActionQueue(ATT_Strike);
      }
      else if(action_chosen == 4){
        main_character->setActionQueue(ATT_ThrowTomato);
      }
    }
  }
}

/**
        @post : If there are no actions in the main character's action queue, 
                or there are no enemies in the combat queue, do nothing.
                
                Otherwise do all of the following:            
                
                1. If the Buff stack is not empty, apply the buff once and decrement the turns.
                   Any time a Buff's turns_ goes to zero, it is removed
                   from the stack. Print out the results of the action as described below.
                2. While there are actions on the action queue:
                - take the next action off the queue
                - if the next action is  a buff, apply once and push it onto the buff stack after 
                  decrementing the turns. 
                  BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
                  for 2 turns in total. Print out the results of the action as described below.
                - if the next action is an attack, execute it against the enemy at the front of
                  the combat queue. Print out the results of the action as described below. 
                 - if after this action there are no more enemies to fight, clear the action
                   queue and return.
                3. Print "END OF YOUR TURN\n" 
          
            : More details:
        
            : After applying each action, print out the results of the action as follows:
            : [MAINCHARACTER NAME] used [ACTION NAME]!
            : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
            : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

             Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
            
            :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
                "[CHARACTER NAME] DEFEATED\n" 
                and remove the enemy from the combat queue AND let them exit the tavern. 
                Then carry out the remaining actions, if any, against the next enemy on the
                combat queue.
          
*/
void Tavern::turnResolution()
{
  Character* enemy = getTarget();                 //create a Character pointer to store the information of the enemy that's in front of the combat_queue
  if(!(main_character->getActionQueue().empty()) || !(combat_queue_.empty())){    //if there are actions in character's action queue or there are enemy in the combat_queue, do the following
    if(!main_character->getBuffStack().empty()){                                  //first, check whether buff_stack_ is empty, if not apply the top buff
      if(main_character->getBuffStack().top().name_ == "BUFF_Heal"){
        main_character->heal();
      }
      else if(main_character->getBuffStack().top().name_ == "BUFF_MendMetal"){
        main_character->mendMetal();
      }
      main_character->decrementTurnsinBuff();                                    //since applied once, decrement the turns by 1
      if(main_character->getBuffStack().top().turns_ == 0){                      //if the turns of the top buff goes to 0, pop out the buff
        main_character->popBuffStack();
      }
    }
    while(!main_character->getActionQueue().empty()){               //second, while there are actions on the action queue
    //take the action in the front of the action queue. After performed each action, print out the results of the action
      if(main_character->getActionQueue().front() == 0){            // 0 is the int correspond to Buff_Heal of enum Action
        main_character->heal();                                     //apply buff heal once
        Buff heal_buff;
        heal_buff.name_ = "BUFF_Heal";
        heal_buff.turns_ = 2;         //Heal last for 3 turns, since it is already being apply once by action, the remain turn is 2
        main_character->getBuffStack().push(heal_buff);             //add BUFF_Heal to the buff_stack
        std::cout << "\n" << main_character->getName() << " used Heal!"
        << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
        << "\nVITALITY: " << main_character->getVitality() 
        << "\nARMOR: " << main_character->getArmor() << "\n"
        << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
        << "\nVITALITY: " << enemy->getVitality() 
        << "\nARMOR: " << enemy->getArmor() << "\n";
      }
      else if(main_character->getActionQueue().front() == 1){       // 1 is the int correspond to Buff_MendMetal of enum Action
        main_character->mendMetal();                                // apply buff mendMetal once
        Buff MendMetal_buff;
        MendMetal_buff.name_ = "BUFF_MendMetal";
        MendMetal_buff.turns_ = 1;     //MendMetal last for 2 turns, since it is already being apply once by action, the remain turn is 1
        main_character->getBuffStack().push(MendMetal_buff);       // add BUFF_MendMetal to the buff_stack_ 
        std::cout << "\n" <<main_character->getName() << " used MendMetal!"
        << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
        << "\nVITALITY: " << main_character->getVitality() 
        << "\nARMOR: " << main_character->getArmor() << "\n"
        << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
        << "\nVITALITY: " << enemy->getVitality() 
        << "\nARMOR: " << enemy->getArmor() << "\n";
      }
      else if(main_character->getActionQueue().front() == 2){       // 2 is the int correspond to ATT_Strike of enum Action
        main_character->strike(enemy);                              //perform the action of strike
        std::cout << "\n" << main_character->getName() << " used Strike!"
        << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
        << "\nVITALITY: " << main_character->getVitality() 
        << "\nARMOR: " << main_character->getArmor() << "\n"
        << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
        << "\nVITALITY: " << enemy->getVitality() 
        << "\nARMOR: " << enemy->getArmor() << "\n";
        if(enemy->getVitality() <= 0){                            // if enemy's vitality becomes <= 0 after the attack
          std::cout << enemy->getName() << " DEFEATED\n";         // print out "[CHARACTER NAME] DEFEATED\n" 
          combat_queue_.pop();                                    // remove the enemy form combat_queue use pop()
          exitTavern(enemy);                                      // also exit the enemy out of Tavern
          enemy = getTarget();                                    // make the Character pointer enemy pointing to the next enemy(if there's any) in the combat_queue_ so the main_character can carry out the remaining actions
        }
      }
      else if(main_character->getActionQueue().front() == 3){       // 3 is the int correspond to ATT_ThrowTomato of enum Action
        main_character->throwTomato(enemy);                         // perform the action of ThrowTomato
        std::cout << "\n" << main_character->getName() << " used ThrowTomato!"
        << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
        << "\nVITALITY: " << main_character->getVitality() 
        << "\nARMOR: " << main_character->getArmor() << "\n"
        << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
        << "\nVITALITY: " << enemy->getVitality() 
        << "\nARMOR: " << enemy->getArmor() << "\n";
        if(enemy->getVitality() <= 0){                            // if enemy's vitality becomes <= 0 after the attack
          std::cout << enemy->getName() << " DEFEATED\n";         // print out "[CHARACTER NAME] DEFEATED\n" 
          combat_queue_.pop();                                    // remove the enemy form combat_queue use pop()
          exitTavern(enemy);                                      // also exit the enemy out of Tavern
          enemy = getTarget();                                    // make the Character pointer enemy pointing to the next enemy(if there's any) in the combat_queue_ so the main_character can carry out the remaining actions
        }
      }
      main_character->popActionQueue();                             //after the action is being taken, pop the action out of the action_queue_, the process will repeat until the action_queue_ is empty
      if(combat_queue_.empty()){                                    //if there are no more enemies to fight, which means that combat_queue is empty
        while(!main_character->getActionQueue().empty()){           //clear all the actions in the action queue using while loop
          main_character->popActionQueue();
        }
      }
    }
    std::cout << "END OF YOUR TURN\n";                              //third and last step, print this to signal the end of the main_character's turn
  }
}

/**
        @param  : A pointer to the enemy
        @post   : Do all of the following:
                : 1. If the enemy's buff stack is not empty, apply buff once and decrement the
                  turns. Any time a Buff's turns_ goes to zero, it is removed
                  from the stack. Print out the results of the action as described below.
                : 2. Pick a random Action 
                    (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
                : If the selected action is a buff, apply once immediately and add it to the 
                  enemy's buff stack, performing the necessary turns update. 
                  Print out the results of the action as described below.
                : If the selected action is an attack, execute it against the main character.
                  Print out the results of the action as described below. 
                : More details:
                
                : After applying each action, print out the results of the action as follows:
                : [ENEMY NAME] used [ACTION NAME]!
                : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
                : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/
void Tavern::enemyTurn(Character* enemy)
{
  if(!enemy->getBuffStack().empty()){                         //check whether the buff_stack_ is empty, if not apply the top buff
    if(enemy->getBuffStack().top().name_ == "BUFF_Heal"){
      enemy->heal();
    }
    else if(enemy->getBuffStack().top().name_ == "BUFF_MendMetal"){
      enemy->mendMetal();
    }
    enemy->decrementTurnsinBuff();                            //since applied once, decrement the turns by 1
    if(enemy->getBuffStack().top().turns_ == 0){              //if the turns of the top buff goes to 0, pop out the buff
      enemy->popBuffStack();
    }
  }
  srand(time(NULL));
  int random_action = rand() % 3;                             //Pick a random action from 0-3, after the enemy have perform the action, print out the result of the action
  if(random_action == 0){                                     //if the random action is 0, it correspond to BUFF_Heal
    enemy->heal();                                            //apply buff heal immediately
    Buff heal_buff;
    heal_buff.name_ = "BUFF_Heal";
    heal_buff.turns_ = 2;           //Heal last for 3 turns, since it is already being apply once by action, the remain turn is 2
    enemy->getBuffStack().push(heal_buff);                    //add BUFF_Heal to buff_stack_
    std::cout << "\n" << enemy->getName() << " used Heal!"
    << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
    << "\nVITALITY: " << enemy->getVitality() 
    << "\nARMOR: " << enemy->getArmor() << "\n"
    << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
    << "\nVITALITY: " << main_character->getVitality() 
    << "\nARMOR: " << main_character->getArmor() << "\n";
  }
  else if(random_action == 1){                               //if the random action is 1, it correspond to BUFF_MendMetal
    enemy->mendMetal();                                      //apply buff MendMetal immediately
    Buff MendMetal_buff;
    MendMetal_buff.name_ = "BUFF_MendMetal";
    MendMetal_buff.turns_ = 1;    //MendMetal last for 2 turns, since it is already being apply once by action, the remain turn is 1
    enemy->getBuffStack().push(MendMetal_buff);              //add BUFF_MendMetal to buff_stack_
    std::cout << "\n" << enemy->getName() << " used MendMetal!"
    << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
    << "\nVITALITY: " << enemy->getVitality() 
    << "\nARMOR: " << enemy->getArmor() << "\n"
    << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
    << "\nVITALITY: " << main_character->getVitality() 
    << "\nARMOR: " << main_character->getArmor() << "\n";
  }
  else if(random_action == 2){                              //if the random action is 2, it correspond to ATT_Strike
    enemy->strike(main_character);                          //perform the action of Strike
    std::cout << "\n" << enemy->getName() << " used Strike!"
    << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
    << "\nVITALITY: " << enemy->getVitality() 
    << "\nARMOR: " << enemy->getArmor() << "\n"
    << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
    << "\nVITALITY: " << main_character->getVitality() 
    << "\nARMOR: " << main_character->getArmor() << "\n";
  }
  else if(random_action == 3){                             //if the random action is 3, it correspond to ATT_ThrowTomato
    enemy->throwTomato(main_character);                    //perform the action of ThrowTomato
    std::cout << "\n" << enemy->getName() << " used ThrowTomato!"
    << "\n(ENEMY) " << enemy->getName() << ": LEVEL " << enemy->getLevel() << " " << enemy->getRace() << ". "
    << "\nVITALITY: " << enemy->getVitality() 
    << "\nARMOR: " << enemy->getArmor() << "\n"
    << "\n(YOU) " << main_character->getName() << ": LEVEL " << main_character->getLevel() << " " << main_character->getRace() << ". "
    << "\nVITALITY: " << main_character->getVitality() 
    << "\nARMOR: " << main_character->getArmor() << "\n";
  }
  //signal the end of the Enemy turn
  std::cout << "END OF ENEMY TURN\n";
}

/**
        @post : While the main character's vitality is > 0, and there are still enemies 
                  in the combat queue, do the following:
              :     - Call actionSelection()
                    - Call turnResolution()
                    - Call enemyTurn() with a pointer to the first enemy on combat queue.

              : If the main character's vitality has fallen to 0, print "YOU HAVE PERISHED."
              : If there are no more enemies in the combat queue, print "NO MORE ENEMIES."
*/
void Tavern::combat()
{
  while(main_character->getVitality() > 0 && !(combat_queue_.empty())){
    actionSelection();
    turnResolution();
    Character* enemy = getTarget();
    //if character pointer enemy is not pointing to a nullptr, it means that there combat_queue is not empty. 
    //if character pointer enemy is pointing to a nullptr, it means that there's no more enemy in the combat_queue, thus there's no need to call the enemyTurn()
    if(enemy != nullptr){
      enemyTurn(enemy);
    }
  }
  if(main_character->getVitality() <= 0){
    std::cout << "YOU HAVE PERISHED.";
  }
  if(combat_queue_.empty()){
    std::cout << "NO MORE ENEMIES.";
  }
}