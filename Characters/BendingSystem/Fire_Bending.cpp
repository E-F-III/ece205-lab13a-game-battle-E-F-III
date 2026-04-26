///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Fire_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Fire_Bending.hpp"
using namespace std;

/// Constructor: initializes the fire bending system
FireBending::FireBending() {
    // No specific initialization required
}

// Fire Blast: a powerful blast of fire that can burn enemies
void FireBending::fireBlast(FighterCharacter& character) {
    cout << "\nFire Blast hits!" << endl;
    
    // Calculate damage: Medium range for fire blast
    int damage = FighterCharacter::rollDice(7, 12); 
    
    // Update health via getter/setter to ensure specific instance update
    character.setHealth(character.getHealth() - damage); 
    
    cout << "Fire Blast deals " << damage << " damage to " << character.getName() << endl; 
}

// Fire Breath: the character exhales a cone of fire that can damage multiple enemies
void FireBending::fireBreath(FighterCharacter& character) {
    // Area damage logic here (applied to current target for simplicity in this game)
    cout << "\nFire Breath activates!" << endl;
    
    // Calculate area damage: Cone of fire deals moderate damage
    int damage = FighterCharacter::rollDice(6, 11); 
    
    character.setHealth(character.getHealth() - damage);
    cout << "Fire Breath deals " << damage << " damage to " << character.getName() << endl; 
}

// Lightning Strike: the character generates a bolt of lightning that can strike a single enemy with high damage
void FireBending::lightningStrike(FighterCharacter& character) {
    // High damage logic here (modified to interact with passed player ref)
    cout << "\nLightning Strike hits!" << endl;
    
    // Calculate damage: High range for lightning attack
    int damage = FighterCharacter::rollDice(12, 20); 
    
    // Update health via getter/setter to ensure specific instance update
    character.setHealth(character.getHealth() - damage); 
    
    cout << "Lightning Strike deals " << damage << " damage to " << character.getName() << endl; 
}

std::vector<std::string> FireBending::getAvailableBendingActions(FighterCharacter& character) {
    vector<std::string> actions = {"Fire Blast", "Fire Breath", "Lightning Strike"};
    cout << "Available Fire Bending Actions for " << character.getName() << ":" << endl;
    for (size_t i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i] << endl;
    }
    return actions;
}
