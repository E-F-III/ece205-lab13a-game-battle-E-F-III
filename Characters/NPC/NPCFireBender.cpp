///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    NPCFireBender.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCFireBender is a derived class of NPCharacter. FireBenders use fire manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "GameCharacter.hpp"
#include "NPCharacter.hpp"
#include "FireBender.hpp"
#include "Fire_Bending.hpp"

using namespace std;

/// Constructor: initializes the fire bending system
NPCFireBender::NPCFireBender(std::string& characterName, int& raceCode) : NPCharacter(characterName, raceCode) {
    // Initialize fire bending system
    fireBendingSystem = new FireBending();
}

// Destructor: Cleanup pointer to prevent memory leaks
NPCFireBender::~NPCFireBender() {
    delete fireBendingSystem;
    // Free memory allocated in constructor
}

/// use bending system to perform a fire bending action
void NPCFireBender::performAction(GameCharacter& target) {
    // for now, randomize the action selection for NPCs
    int choice = rand() % 3; // Randomly select an action (0, 1, or 2)
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Fire Blast ---\n" << endl;
            fireBendingSystem->fireBlast(target);
            break;
        case 1:
            cout << "\n--- Action Selected: Fire Breath ---\n" << endl;
            fireBendingSystem->fireBreath(target);
            break;
        case 2:
            cout << "\n--- Action Selected: Lightning Strike ---\n" << endl;
            fireBendingSystem->lightningStrike(target);
            break;
    }
}

/// Print FireBender-specific stats in addition to base stats
void NPCFireBender::printStats() {
    NPCharacter::printStats();
    cout << "Profession: FireBender" << endl;
    cout << "------------------------------------" << endl;
}

/// FireBender-specific greeting
void NPCFireBender::greet() const {
    cout << name << " the FireBender: Greetings! I am " << name << ". The flames are at my command, and I will use them to protect my allies" << endl;
}
