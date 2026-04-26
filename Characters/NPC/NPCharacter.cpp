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
    random_device rd;
    /// non-deterministic random number
    ///rd: random number source providing inital randomness for different values
    mt19937 engine(rd());
    /// Mersenne Twister algorithm-based random number gen.
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
PlayerCharacter::PlayerCharacter(string& characterName, int& bendingStyleCode) {
    setName(characterName);
    /// health automatically set to 100
    health = 100;

    ///generate random values between 0 and 10 using rollDice() for stats
    agility = rollDice(0, 10);
    defense = rollDice(0, 10);
    strength = rollDice(0, 10);

    /// take bending style from user and set it using setBendingStyle() method
    setBendingStyle(bendingStyleCode);
}

/// getters
int PlayerCharacter::getHealth() { return health; }
int PlayerCharacter::getAgility() { return agility; }
int PlayerCharacter::getDefense() { return defense; }
int PlayerCharacter::getStrength() { return strength; }
int PlayerCharacter::getBendingStyle() { return bendingStyle; }

/// setters
void PlayerCharacter::setHealth(int health) { this->health = health; }
void PlayerCharacter::setStrength(int strength) { this->strength = strength; }
void PlayerCharacter::setAgility(int agility) { this->agility = agility; }
void PlayerCharacter::setDefense(int defense) { this->defense = defense; }

void PlayerCharacter::setBendingStyle(int bendingStyleChoice) {
    switch (bendingStyleChoice) {
        case 0: bendingStyle = BendingStyle::air; break;
        case 1: bendingStyle = BendingStyle::earth; break;
        case 2: bendingStyle = BendingStyle::fire; break;
        case 3: bendingStyle = BendingStyle::water; break;
    }
}

/// print stats with correct format
void PlayerCharacter::printStats() {
    /// array that stores the races in order for later (for printing race)
    ///
    /// for index of array, use the enum value
    ///
    /// since order is same in array and enum
    string bendingStyleArray[4] = {"air", "earth", "fire", "water"};
    
    cout << "----------Stats for " << name << "----------" << endl;
    cout << "Name: " << name << endl;
    cout << "Bending Style: " << bendingStyleArray[bendingStyle] << endl;
    ///note use enum bendingStyle value as index of array declared above
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

void PlayerCharacter::performAction(PlayerCharacter& target) {
    cout << "I am performing an action!" << endl;
}
