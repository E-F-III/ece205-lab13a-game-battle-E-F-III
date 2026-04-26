///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    EarthBender.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// EarthBender is a derived class of PlayerCharacter. EarthBenders use earth manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./EarthBender.hpp"
#include "../BendingSystem/Earth_Bending.hpp"
using namespace std;

/// Constructor: initializes the earth bending system
EarthBender::EarthBender(string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    // Initialize earth bending system
    earthBendingSystem = new EarthBending(); 
}

// Destructor: Cleanup pointer to prevent memory leaks
EarthBender::~EarthBender() {
    delete earthBendingSystem; // Free memory allocated in constructor
}

/// use bending system to perform an earth bending action
void EarthBender::performAction() {
    int choice = 0; // Initialize choice variable for loop validation
    
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    earthBendingSystem->getAvailableBendingActions(*this); // Display available actions
    
    // Loop ensures the options 0-2 are selected (Validation)
    while (choice < 0 || choice > 2) { 
        cout << "Enter the number corresponding to your choice (0=Earth, 1=Shield, 2=Rock): "; 
        cin >> choice; 
        
        if (choice < 0 || choice > 2) {
            cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl; 
        }
    }
    
    // Call the appropriate function in earthBendingSystem based on user selection.
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Earth Attack ---\n" << endl; 
            earthBendingSystem->earthAttack(*this);   
            break;
        case 1:
            cout << "\n--- Action Selected: Earth Shield ---\n" << endl;
            earthBendingSystem->earthShield(*this);  
            break;
        case 2:
            cout << "\n--- Action Selected: Rock Smack ---\n" << endl; 
            earthBendingSystem->rockSmack(*this);      
            break;
    }
}

/// Print EarthBender-specific stats in addition to base stats
void EarthBender::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: EarthBender" << endl;
    cout << "------------------------------------" << endl;
}

/// EarthBender-specific greeting
void EarthBender::greet() const {
    cout << name << " the EarthBender: Greetings! I am " << name << ". The earth is my ally, and I will use it to protect my allies" << endl;
}
