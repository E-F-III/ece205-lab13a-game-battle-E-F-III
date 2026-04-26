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
    // Initialize any fire bending specific attributes if needed
}

// Fire Blast: a powerful blast of fire that can burn enemies
void FireBending::fireBlast(PlayerCharacter& character) {
    cout << character.getName() << " performs Fire Blast! A powerful blast of fire shoots towards the enemy, burning them." << endl;
    // Implement damage logic here
}

// Fire Breath: the character exhales a cone of fire that can damage multiple enemies
void FireBending::fireBreath(PlayerCharacter& character) {
    cout << character.getName() << " performs Fire Breath! They exhale a cone of fire that can damage multiple enemies in front of them." << endl;
    // Implement area damage logic here
}

// Lightning Strike: the character generates a bolt of lightning that can strike a single enemy with high damage
void FireBending::lightningStrike(PlayerCharacter& character) {
    cout << character.getName() << " performs Lightning Strike! They generate a bolt of lightning that strikes a single enemy with high damage." << endl;
    // Implement high damage logic here
}

std::vector<std::string> FireBending::getAvailableBendingActions(PlayerCharacter& character) {
    vector<std::string> actions = {"Fire Blast", "Fire Breath", "Lightning Strike"};
    cout << "Available Fire Bending Actions for " << character.getName() << ":" << endl;
    for (size_t i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i] << endl;
    }
    return actions;
}