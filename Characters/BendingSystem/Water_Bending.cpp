///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Water_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Water_Bending.hpp"
using namespace std;

/// Constructor: initializes the water bending system
WaterBending::WaterBending() {
    // No specific initialization required
}

// Healing Waters: a soothing wave of water that can heal allies
void WaterBending::healingWaters(FighterCharacter& character) {
    // Implementation of healing logic here (modified to interact with passed player ref)
    cout << "\nHealing Waters activates!" << endl;
    
    // Calculate healing: Diceroll between 5 and 10 for healing amount
    int healAmount = FighterCharacter::rollDice(5, 10); 
    
    // Update health via getter/setter to ensure specific instance update (don't exceed max health if desired, but simple game allows overflow)
    character.setHealth(character.getHealth() + healAmount); 
    
    cout << "Healing Waters heals " << healAmount << " health on " << character.getName() << endl; 
}

// Water Whip: a flexible whip of water that can strike enemies from a distance
void WaterBending::waterWhip(FighterCharacter& character) {
    // Implementation of damage logic here (modified to interact with passed player ref)
    int targetHealth = character.getHealth();
    cout << "\nWater Whip hits!" << endl;
    
    // Calculate damage: Medium range for whip attack
    int damage = FighterCharacter::rollDice(7, 12); 
    
    // Update health via getter/setter to ensure specific instance update
    character.setHealth(targetHealth - damage); 
    
    cout << "Water Whip deals " << damage << " damage to " << character.getName() << endl; 
}

// Ice Barrier: creates a solid barrier of ice that can block attacks and protect allies
void WaterBending::iceBarrier(FighterCharacter& character) {
    // Implementation of defense logic here (modified to protect passed player ref)
    cout << "\nIce Barrier activates!" << endl;
    // In this simple game, ice barrier prevents immediate damage
    character.setHealth(character.getHealth()); 
}

std::vector<std::string> WaterBending::getAvailableBendingActions(FighterCharacter& character) {
    vector<std::string> actions = {"Healing Waters", "Water Whip", "Ice Barrier"};
    cout << "Available Water Bending Actions for " << character.getName() << ":" << endl;
    for (size_t i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i] << endl;
    }
    return actions;
}
