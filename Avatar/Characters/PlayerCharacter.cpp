///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    PlayerCharacter.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random>
#include "PlayerCharacter.hpp"
using namespace std;

// Note: rollDice() uses random device and is a member function, so we call it via object methods.
int PlayerCharacter::rollDice(int lower, int upper) {
  random_device rd; 
  mt19937 engine(rd()); 
  uniform_int_distribution<int> distribution(lower, upper); 
  return distribution(engine);
}

/// constructor declaration for "PlayerCharacter" (remains unchanged)
PlayerCharacter::PlayerCharacter(string& characterName, int& bendingStyleCode) {
  setName(characterName); // Use setter methods to ensure initialization consistency
  health = 100; // Health automatically set to 100
  // generate random values between 5 and 20 (using a slightly higher range for better gameplay)
  agility = rollDice(5, 20);
  defense = rollDice(5, 20);
  strength = rollDice(5, 20);
  setBendingStyle(bendingStyleCode);
}

// Getters (remain unchanged)
int PlayerCharacter::getHealth() { return health; }
/* ... other getters remain the same ... */


// Setters: These functions now accept 'int' by value instead of 'int&'
void PlayerCharacter::setHealth(int newHealth) { 
    health = newHealth; // Simple assignment is enough since we are passing a calculated value.
}
void PlayerCharacter::setAgility(int newAgility) { agility = newAgility; }
void PlayerCharacter::setDefense(int newDefense) { defense = newDefense; }
void PlayerCharacter::setStrength(int newStrength) { strength = newStrength; }

// setBendingStyle remains correct because it needs to modify the incoming variable (the reference).
void PlayerCharacter::setBendingStyle(int& newBendingStyle) {
    while (newBendingStyle < 0 || newBendingStyle > 3) {
        cout << "Invalid value!" << endl;
        cout << "\nEnter a bending style for your character (air: 0, earth: 1, fire: 2, water: 3): " << endl;
        cin >> newBendingStyle;  /// take user input 
    }
    switch (newBendingStyle) {
        case 0: bendingStyle = BendingStyle::air; break;
        case 1: bendingStyle = BendingStyle::earth; break;
        case 2: bendingStyle = BendingStyle::fire; break;
        case 3: bendingStyle = BendingStyle::water; break;
    }
}

// ADDED IMPLEMENTATION for polymorphism fix
void PlayerCharacter::performAction() {
    cout << "No specific action available for this generic character." << endl;
}


// ... (printStats and greet implementations remain unchanged) ...
