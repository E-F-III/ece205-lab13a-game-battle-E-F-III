///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    AirBender.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "PlayerCharacter.hpp"
#include "AirBender.hpp"
#include "Air_Bending.hpp"
using namespace std;

// --- Constructor and Destructor --- 
/// Constructor: initializes the air bending system
AirBender::AirBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    airBendingSystem = new AirBending();
    // Initialize the air bending system pointer
}

// Destructor: This MUST be defined to clean up memory allocated in the constructor.
AirBender::~AirBender() {
    delete airBendingSystem; 
}


/// use bending system to perform an air bending action (This function contains the menu logic)
void AirBender::performAction(FighterCharacter& target) {
    int choice = -1;
    // Initialize choice variable for loop validation
    cout << "\nGame Master: What would you like " << name << " to do?"
         << endl;
    airBendingSystem->getAvailableBendingActions(target); // Display available options
    
    // Loop ensured the options 0-2 are selected (Input Validation)
    while (choice < 0 || choice > 2) {
        cout << "Enter the number corresponding to your choice (0=Slice, 1=Shield, 2=Flight): ";
        cin >> choice;
        if (choice < 0 || choice > 2) {
            // Using endl for console consistency
            cout << "Invalid input! Please enter a number between 0 and 2."
                 << endl;
        }
    }
    
    // Call the appropriate function in airBendingSystem based on user selection.
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Air Slice ---\n" << endl;
            airBendingSystem->airSlice(target);
            // Passing target reference to modify health
            break;
        case 1:
            cout << "\n--- Action Selected: Air Shield ---\n" << endl;
            airBendingSystem->airShield(target); // Passing target reference to modify health
            break;
        case 2:
            cout << "\n--- Action Selected: Flight ---\n" << endl;
            airBendingSystem->flight(target);
            break;
    }
}

/// Print AirBender-specific stats in addition to base stats
void AirBender::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: AirBender" << endl;
    cout << "------------------------------------" << endl;
}

/// AirBender-specific greeting
void AirBender::greet() const {
    cout << name << " the AirBender: Greetings! I am " << name << ". The wind is at my command, and I will use it to protect my allies" << endl;
}
