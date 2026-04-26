///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    FireBender.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// FireBender is a derived class of PlayerCharacter. FireBenders use fire manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./FireBender.hpp"
#include "../BendingSystem/Fire_Bending.hpp"
using namespace std;

/// Constructor: initializes the fire bending system
FireBender::FireBender(string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    // Initialize fire bending system
    fireBendingSystem = new FireBending(); 
}

// Destructor: Cleanup pointer to prevent memory leaks
FireBender::~FireBender() {
    delete fireBendingSystem; // Free memory allocated in constructor
}

/// use bending system to perform a fire bending action
void FireBender::performAction() {
    int choice = 0; // Initialize choice variable for loop validation
    
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    fireBendingSystem->getAvailableBendingActions(*this); // Display available actions
    
    // Loop ensures the options 0-2 are selected (Validation)
    while (choice < 0 || choice > 2) { 
        cout << "Enter the number corresponding to your choice (0=Burn, 1=Shield, 2=Flame): "; 
        cin >> choice; 
        
        if (choice < 0 || choice > 2) {
            cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl; 
        }
    }
    
    // Call the appropriate function in fireBendingSystem based on user selection.
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Fire Slash ---\n" << endl; 
            fireBendingSystem->fireSlash(*this);   
            break;
        case 1:
            cout << "\n--- Action Selected: Fire Shield ---\n" << endl;
            fireBendingSystem->fireShield(*this);  
            break;
        case 2:
            cout << "\n--- Action Selected: Flame Aura ---\n" << endl; 
            fireBendingSystem->flameAura(*this);      
            break;
    }
}

/// Print FireBender-specific stats in addition to base stats
void FireBender::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: FireBender" << endl;
    cout << "------------------------------------" << endl;
}

/// FireBender-specific greeting
void FireBender::greet() const {
    cout << name << " the FireBender: Greetings! I am " << name << ". The flames are at my command, and I will use them to protect my allies" << endl;
}
