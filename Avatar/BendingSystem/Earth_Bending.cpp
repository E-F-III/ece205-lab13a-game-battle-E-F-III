///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Earth_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Earth_Bending.hpp"
using namespace std;

/// Constructor: initializes the earth bending system
EarthBending::EarthBending() {
    // No specific initialization required
}

// Earth Spike: a sharp spike of earth that can impale enemies
void EarthBending::earthSpike(PlayerCharacter& character) {
    // Implementation of damage logic here (modified to interact with passed player ref)
    int targetHealth = character.getHealth();
    cout << "\nEarth Spike hits!" << endl;
    
    // Calculate damage: Diceroll between 5 and 10 for spike attack
    int damage = PlayerCharacter::rollDice(5, 10); 
    
    // Update health via getter/setter to ensure specific instance update
    character.setHealth(targetHealth - damage); 
    
    cout << "Earth Spike deals " << damage << " damage to " << character.getName() << endl; 
}

// Rock Shield: creates a sturdy shield of rock that can block attacks
void EarthBending::rockShield(PlayerCharacter& character) {
    // Implementation of defense logic here (modified to protect passed player ref)
    cout << "\nRock Shield activates!" << endl;
    // In this simple game, shielding prevents immediate damage
    character.setHealth(character.getHealth()); 
}

// Seismic Slam: slams the ground to create a shockwave that damages and knocks back enemies
void EarthBending::seismicSlam(PlayerCharacter& character) {
    // Implementation of area damage logic here (modified to damage passed player ref)
    int targetHealth = character.getHealth();
    cout << "\nSeismic Slam hits!" << endl;
    
    // Calculate damage: Higher range for slam attack
    int damage = PlayerCharacter::rollDice(8, 15); 
    
    // Update health via getter/setter to ensure specific instance update
    character.setHealth(targetHealth - damage); 
    
    cout << "Seismic Slam deals " << damage << " damage to " << character.getName() << endl; 
}

std::vector<std::string> EarthBending::getAvailableBendingActions(PlayerCharacter& character) {
    vector<std::string> actions = {"Earth Spike", "Rock Shield", "Seismic Slam"};
    cout << "Available Earth Bending Actions for " << character.getName() << ":" << endl;
    for (size_t i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i] << endl;
    }
    return actions;
}
