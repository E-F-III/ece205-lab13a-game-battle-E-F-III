///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Air_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Air_Bending.hpp"
using namespace std;

/// Constructor: initializes the air bending system
AirBending::AirBending() {
    // Initialize any air bending specific attributes if needed
}

// Air Slice: a quick, slicing gust of wind that can cut through enemies
void AirBending::airSlice(FighterCharacter& character, FighterCharacter& 
target) {
    cout << character.getName() << " performs Air Slice! A sharp gust of wind cuts through the enemy." << endl;
    // Implementation of damage logic
    int targetHealth = target.getHealth();
    cout << "\nAir Slice hits!" << endl;
    
    // Calculate damage: Diceroll between 5 and 10
    int damage = FighterCharacter::rollDice(5, 10); 
    
    // This sets the target health to damage dealt
    target.setHealth(targetHealth - damage); 
    
    // Move statement
    cout << "Air Slice deals " << damage << " damage to " << 
target.getName() << endl; 
}

// Air Shield: creates a swirling barrier of wind that protects and deflects attacks
void AirBending::airShield(FighterCharacter& character,FighterCharacter& target) {
    cout << character.getName() << " creates an Air Shield! A swirling barrier of wind protects them from incoming attacks." << endl;
    // Implement defense logic here
    cout << "\nAir Shield activates!" << "Protects" << target.getName() << endl;
    cout << "Shield logic not fully implemented yet, but it will block the next incoming attack." << endl;
    // Blocks all damage
    // Below is stubbed out will implement shields later. 
    // character.setHealth(character.getHealth());
}

// Flight: allows the character to take to the skies, increasing mobility and evasion
void AirBending::flight(FighterCharacter& character) {
    cout << character.getName() << " takes to the skies with Flight! They can now move freely and avoid ground-based attacks." << endl;
    // Implement flight logic here (not implementing for now because basic combat will function without)
}

std::vector<std::string> AirBending::getAvailableBendingActions(FighterCharacter& character) {
    vector<std::string> actions = {"Air Slice", "Air Shield", "Flight"};
    cout << "Available Air Bending Actions for " << character.getName() << ":" << endl;
    for (size_t i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i] << endl;
    }
    return actions;
}
