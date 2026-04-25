///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    PlayerCharacter.cpp
/// @author  Steven Daniel Javier <sdjavier@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <random>
#include "PlayerCharacter.hpp"

using namespace std;

/// generates random number btwn lower / upper limits 
int PlayerCharacter::rollDice(int lower, int upper) {

  random_device rd; /// non-deterministic random number 
  ///rd: random number source providing inital randomness for different values
  mt19937 engine(rd()); /// Mersenne Twister algorithm-based random number gen.
  /// engine produces the random number above

  uniform_int_distribution<int> distribution(lower, upper); 
  /// generate integer btwn lower and upper

  int result = distribution(engine);
  /// ^generates the random number 

  return result;
}


/// constructor declaration for "PlayerCharacter"
/// takes in address of name from user and int corresponding to race
/// inherited from GameCharacter, note only the setName() member is used, 
// (since no race member) 
PlayerCharacter::PlayerCharacter(string& characterName, int& raceCode) {
  setName(characterName);

  /// health automatically set to 100
  health = 100;

  ///generate random values between 0 and 10 using rollDice() for stats
  agility = rollDice(0, 10);
  defense = rollDice(0, 10);
  strength = rollDice(0, 10);

  /// take race from user and set race
  setRace(raceCode);

}

/// getters
int PlayerCharacter::getHealth() {
  return health;
  }

int PlayerCharacter::getAgility() {
  return agility;
}

int PlayerCharacter::getDefense() {
  return defense;
}

/// note the type PlayerCharacter::Race
PlayerCharacter::Race PlayerCharacter::getRace() {
    return race;
}

///setters
void PlayerCharacter::setHealth(int& newHealth) {
  health = newHealth;
}

void PlayerCharacter::setAgility(int& newAgility) {
  agility = newAgility;
}

void PlayerCharacter::setDefense(int& newDefense) {
  defense = newDefense;
}

void PlayerCharacter::setRace(int& newRace) {
    /// loops, keep asking for value for race until valid {0, 1, 2, 3}
  while (newRace < 0 || newRace > 3) {

    /// prompt user if wrong -->  give them the options again

    cout << "Invalid value!" << endl;
    cout << "\nEnter a race for your character (human: 0, fishman: 1, giant: 2, dwarf: 3): " << endl;
    cin >> newRace;  /// take user input 
  }

  /// switch case for the races based on the int taken in
  switch (newRace) {
    case 0:
      race = Race::human;
      break;
    case 1:
      race = Race::fishman;
      break;
    case 2:
      race = Race::giant;
      break;
    case 3:
      race = Race::dwarf;
      break;
  }
}

/// print stats with correct format 
void PlayerCharacter::printStats() {

  /// array that stores the races in order for later (for printing race)
  ///
  /// for index of array, use the enum value
  ///
  /// since order is same in array and enum
  string raceArray[4] = {"human", "fishman", "giant", "dwarf"};

  cout << "----------Stats for " << name << "----------" << endl;
  cout << "Name: " << name << endl;
  cout << "Race: " << raceArray[race] << endl; ///note use enum race value as index of array declared above
  cout << "Health: " << health << endl;
  cout << "Strength: " << strength << endl;
  cout << "Agility: " << agility << endl;
  cout << "Defense: " << defense << endl;
  cout << "------------------------------------" << endl;
}

///greeting using the name of PlayerCharacter
void PlayerCharacter::greet() const {
  cout << name << " : Hello, my name is " << name << ". How can I help with your quest?" << endl;
}

void PlayerCharacter::performAction() {
  cout << "I am performing an action!" << endl;
   // cpp file

}

