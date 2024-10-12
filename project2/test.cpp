#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>

int main(){
    //2.1.1 Instantiate a default Mage
    //Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Mage defaultMage;
    defaultMage.setName("defaultMage");
    defaultMage.setRace("ELF");
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();

    //Print out information for default Mage 
    std::cout << defaultMage.getName() << " is a Level " << defaultMage.getLevel() << " "<< defaultMage.getRace()<< ".";
    std::cout << "\nVitality: " << defaultMage.getVitality() << "\nArmor: " << defaultMage.getArmor();
    std::cout << "\nThey are ";
    defaultMage.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nSchool of magic: " << defaultMage.getSchool();
    std::cout << "\nWeapon: "<< defaultMage.getCastingWeapon();
    std::cout << "\nSummon Incarnate: ";
    defaultMage.hasIncarnateSummon() ? std::cout << "TRUE" : std::cout << "FALSE" ;
    
    std::cout << "\n\n";

    //2.1.2 Instantiate a Mage with the parameterized constructor
    Mage mage_1("SPYNACH", "ELF", 6, 4, 4, false);

    //2.1.3 Set SPYNACH's unique private member variables
    mage_1.setSchool("Illusion");
    mage_1.setCastingWeapon("wand");
    mage_1.setIncarnateSummon(true);

    //Print out information for SPYNACH
    std::cout << mage_1.getName() << " is a Level " << mage_1.getLevel() << " " << mage_1.getRace()<< ".";
    std::cout << "\nVitality: " << mage_1.getVitality() << "\nArmor: " << mage_1.getArmor();
    std::cout << "\nThey are ";
    mage_1.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nSchool of magic: " << mage_1.getSchool();
    std::cout << "\nWeapon: "<< mage_1.getCastingWeapon();
    std::cout << "\nSummon Incarnate: ";
    mage_1.hasIncarnateSummon() ? std::cout << "TRUE" : std::cout << "FALSE" ;
    std::cout << "\n\n";

    //2.2.1 Instantiate a default Scoundrel
    //Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Scoundrel defaultScoundrel;
    defaultScoundrel.setName("defaultScoundrel");
    defaultScoundrel.setRace("HUMAN");
    defaultScoundrel.setVitality(6);
    defaultScoundrel.setArmor(4);
    defaultScoundrel.setLevel(3);
    defaultScoundrel.setEnemy();

    //Print out information for default Scoundrel 
    std::cout << defaultScoundrel.getName() << " is a Level " << defaultScoundrel.getLevel() << " " << defaultScoundrel.getRace()<< ".";
    std::cout << "\nVitality: " << defaultScoundrel.getVitality() << "\nArmor: " << defaultScoundrel.getArmor();
    std::cout << "\nThey are ";
    defaultScoundrel.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nDagger: " << defaultScoundrel.getDagger();
    std::cout << "\nFaction: "<< defaultScoundrel.getFaction();
    std::cout << "\nDisguise: ";
    defaultScoundrel.hasDisguise() ? std::cout << "TRUE" : std::cout << "FALSE" ;
    std::cout << "\n\n";

    //2.2.2 Instantiate a Scoundrel with the parameterized constructor
    Scoundrel scoundrel_1("FLEA", "DWARF", 12, 7, 5, false);

    //2.2.3 Set FLEA's unique private member variables
    scoundrel_1.setDagger("Adamant");
    scoundrel_1.setFaction("Cutpurse");
    scoundrel_1.setDisguise(true);

    //Print out information for FLEA
    std::cout << scoundrel_1.getName() << " is a Level " << scoundrel_1.getLevel() << " " << scoundrel_1.getRace()<< ".";
    std::cout << "\nVitality: " << scoundrel_1.getVitality() << "\nArmor: " << scoundrel_1.getArmor();
    std::cout << "\nThey are ";
    scoundrel_1.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nDagger: " << scoundrel_1.getDagger();
    std::cout << "\nFaction: "<< scoundrel_1.getFaction();
    std::cout << "\nDisguise: ";
    scoundrel_1.hasDisguise() ? std::cout << "TRUE" : std::cout << "FALSE" ;
    std::cout << "\n\n";

    //2.3.1 Instantiate a default Ranger
    //Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Ranger defaultRanger;
    defaultRanger.setName("defaultRanger");
    defaultRanger.setRace("UNDEAD");
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();

    //Print out information for default Ranger
    std::cout << defaultRanger.getName() << " is a Level " << defaultRanger.getLevel() << " " << defaultRanger.getRace()<< ".";
    std::cout << "\nVitality: " << defaultRanger.getVitality() << "\nArmor: " << defaultRanger.getArmor();
    std::cout << "\nThey are ";
    defaultRanger.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    //Print out vector for arrows and affinities using for loops
    std::vector<Arrows> defaultRanger_arrows = defaultRanger.getArrows();
    std::cout << "\nArrows: ";
    if (defaultRanger_arrows.size() == 0 ){
        std::cout << "NONE";  //if the vector is empty, print "NONE"
    }
    for(int i = 0; i < defaultRanger_arrows.size(); i++){ //else, print the item in vector one by one by the format of type, quantity, type, quantity...
        if ( i == defaultRanger_arrows.size() - 1){
            std::cout << defaultRanger_arrows[i].type_ << ", " << defaultRanger_arrows[i].quantity_;
        }
        else{
            std::cout << defaultRanger_arrows[i].type_ << ", " << defaultRanger_arrows[i].quantity_ << ", ";
        }
    }
    std::cout << "\nAffinities: ";
    std::vector<std::string> defaultRanger_Affinities = defaultRanger.getAffinities();
    if (defaultRanger_Affinities.size() == 0){
        std::cout << "NONE";  //if the vector is empty, print "NONE"
    }
    for(int i = 0; i < defaultRanger_Affinities.size(); i++){  //else, print the item in vector one by one
        if ( i == defaultRanger_Affinities.size() - 1){
            std::cout << defaultRanger_Affinities[i];
        }
        else{
            std::cout << defaultRanger_Affinities[i] << ", ";
        }
    }
    std::cout << "\nAnimal Companian: ";
    defaultRanger.getCompanion() ? std::cout << "TRUE" : std::cout << "FALSE";
    std::cout << "\n\n";

    //2.2.2 Instantiate a Ranger with the parameterized constructor
    Ranger Ranger_1("MARROW", "UNDEAD", 9, 6, 5, true);

    //2.1.3 Set SPYNACH's unique private member variables
    Ranger_1.addArrows("Wood", 30);
    Ranger_1.addArrows("Fire", 5);
    Ranger_1.addArrows("Water", 5);
    Ranger_1.addArrows("Poison", 5);
    Ranger_1.addAffinity("Fire");
    Ranger_1.addAffinity("Poison");
    Ranger_1.setCompanion(true);

    //Print out information for MARROW
    std::cout << Ranger_1.getName() << " is a Level " << Ranger_1.getLevel() << " " << Ranger_1.getRace()<< ".";
    std::cout << "\nVitality: " << Ranger_1.getVitality() << "\nArmor: " << Ranger_1.getArmor();
    std::cout << "\nThey are ";
    Ranger_1.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    //Print out vector for arrows and affinities using for loops
    std::vector<Arrows> Ranger_1_Arrow = Ranger_1.getArrows();
    std::cout << "\nArrows: ";
    if (Ranger_1_Arrow.size() == 0 ){
        std::cout << "NONE"; //if the vector is empty, print "NONE"
    }
    for(int i = 0; i < Ranger_1_Arrow.size(); i++){ //else, print the item in vector one by one by the format of type, quantity, type, quantity...
        if ( i == Ranger_1_Arrow.size() - 1){
            std::cout << Ranger_1_Arrow[i].type_ << ", " << Ranger_1_Arrow[i].quantity_;
        }
        else{
            std::cout << Ranger_1_Arrow[i].type_ << ", " << Ranger_1_Arrow[i].quantity_ << ", ";
        }
    }
    std::cout << "\nAffinities: ";
    std::vector<std::string> Ranger_1_Affinities = Ranger_1.getAffinities();
    if (Ranger_1_Affinities.size() == 0){
        std::cout << "NONE"; //if the vector is empty, print "NONE"
    }
    for(int i = 0; i < Ranger_1_Affinities.size(); i++){ //else, print the item in vector one by one
        if ( i == Ranger_1_Affinities.size() - 1){
            std::cout << Ranger_1_Affinities[i];
        }
        else{
            std::cout << Ranger_1_Affinities[i] << ", ";
        }
    }
    std::cout << "\nAnimal Companian: ";
    Ranger_1.getCompanion() ? std::cout << "TRUE" : std::cout << "FALSE";
    std::cout << "\n\n";

    Ranger_1.fireArrow("WOOD"); //test if fireArrow complies

    //2.4.1 Instantiate a default Barbarian
    //Sets its name, race, vitality, and armor levels using the appropriate setter functions
    Barbarian defaultBarbarian;
    defaultBarbarian.setName("defaultBarbarian");
    defaultBarbarian.setRace("HUMAN");
    defaultBarbarian.setVitality(10);
    defaultBarbarian.setArmor(5);
    defaultBarbarian.setLevel(5);
    defaultBarbarian.setEnemy();

    //Print out information for default Barbarian
    std::cout << defaultBarbarian.getName() << " is a Level " << defaultBarbarian.getLevel() << " " << defaultBarbarian.getRace()<< ".";
    std::cout << "\nVitality: " << defaultBarbarian.getVitality() << "\nArmor: " << defaultBarbarian.getArmor();
    std::cout << "\nThey are ";
    defaultBarbarian.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nMain Weapon: " << defaultBarbarian.getMainWeapon();
    std::cout << "\nOffhand Weapon: " << defaultBarbarian.getSecondaryWeapon();
    std::cout << "\nEnraged: ";
    defaultBarbarian.getEnrage() ? std::cout << "TRUE" : std::cout << "FALSE";
    std::cout << "\n\n";

    //2.4.2 Instantiate a Barbarian with the parameterized constructor
    Barbarian Barbarian_1("BONK", "HUMAN", 11, 5, 5, true);

    //2.4.3 Set BONK's unique private member variables
    Barbarian_1.setMainWeapon("Mace");
    Barbarian_1.setSecondaryWeapon("ANOTHERMACE");
    Barbarian_1.setEnrage(true);

    //Print ouf information for BONK
    std::cout << Barbarian_1.getName() << " is a Level " << Barbarian_1.getLevel() << " " << Barbarian_1.getRace()<< ".";
    std::cout << "\nVitality: " << Barbarian_1.getVitality() << "\nArmor: " << Barbarian_1.getArmor();
    std::cout << "\nThey are ";
    Barbarian_1.isEnemy() ? std::cout << "an enemy" : std::cout << "not an enemy";
    std::cout << "\nMain Weapon: " << Barbarian_1.getMainWeapon();
    std::cout << "\nOffhand Weapon: " << Barbarian_1.getSecondaryWeapon();
    std::cout << "\nEnraged: ";
    Barbarian_1.getEnrage() ? std::cout << "TRUE" : std::cout << "FALSE";

    Barbarian_1.toggleEnrage(); //test if toggleEnrage complies
}