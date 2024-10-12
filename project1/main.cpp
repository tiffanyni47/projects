
#include "Character.hpp"
#include <iostream>

int main() {
  std::cout << "TEST DEFAULT CONSTRUCTOR & ACCESSORS\n" << std::endl;

  // Test default constructor
  Character my_character;

  // Test accessor functions
  std::cout << "Name: " << my_character.getName() << std::endl;
  std::cout << "Race: "<< my_character.getRace() << std::endl;
  std::cout << "Vitality: " << my_character.getVitality() << std::endl;
  std::cout << "Armor: " << my_character.getArmor() << std::endl;
  std::cout << "Level: " << my_character.getLevel() << std::endl;
  std::cout << "Is enemy: "<< my_character.isEnemy() << std::endl;

  std::cout << "\nTEST PARAMETERIZED CONSTRUCTOR & ACCESSORS" << std::endl;

  // Test parameterized constructor
  Character my_character1("Amy", "HUMAN", -8, 35, 9, 1);
  Character my_character2("YIng1125", "", 23, -10, 34, 1);
  Character my_character3("", "hwqbfs", 53, 12, -17, 0);

  // Test accessor functions
  std::cout << "\nCHARACTER 1" << std::endl;
  std::cout << "Name: " << my_character1.getName() << "\nRace: " << my_character1.getRace() << "\nVitality: " << my_character1.getVitality() << std::endl;
  std::cout << "Armor: " << my_character1.getArmor() << "\nlevel: " << my_character1.getLevel() << "\nIs Enemy: " << my_character1.isEnemy() << std::endl;
  std::cout << "\nCHARACTER 2" << std::endl;
  std::cout << "Name: " << my_character2.getName() << "\nRace: " << my_character2.getRace() << "\nVitality: " << my_character2.getVitality() << std::endl;
  std::cout << "Armor: " << my_character2.getArmor() << "\nlevel: " << my_character2.getLevel() << "\nIs Enemy: " << my_character2.isEnemy() << std::endl;
  std::cout << "\nCHARACTER 3" << std::endl;
  std::cout << "Name: " << my_character3.getName() << "\nRace: " << my_character3.getRace() << "\nVitality: " << my_character3.getVitality() << std::endl;
  std::cout << "Armor: " << my_character3.getArmor() << "\nlevel: " << my_character3.getLevel() << "\nIs Enemy: " << my_character3.isEnemy() << std::endl;

  std::cout << "\nTEST MUTATOR FUNCTIONS & ACCESSORS" << std::endl;

  // Test mutator functions
  Character my_character4("Eleven Wishes", "DWARF", 100, 100, 100, 0);
  my_character4.setName("11wishes_");
  my_character4.setRace("WFJS");
  my_character4.setVitality(23);
  my_character4.setArmor(-10);
  my_character4.setLevel(50);
  my_character4.setEnemy();

  // Test accessor functions
  std::cout << "\nCHARACTER 4" << std::endl;
  std::cout << "Name: " << my_character4.getName() << "\nRace: " << my_character4.getRace() << "\nVitality: " << my_character4.getVitality() << std::endl;
  std::cout << "Armor: " << my_character4.getArmor() << "\nlevel: " << my_character4.getLevel() << "\nIs Enemy: " << my_character4.isEnemy() << std::endl;

}