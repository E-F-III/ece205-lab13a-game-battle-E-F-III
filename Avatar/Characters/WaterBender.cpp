///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    WaterBender.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// WaterBender is a derived class of PlayerCharacter. WaterBenders use water manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./WaterBender.hpp"
#include "../BendingSystem/Water_Bending.hpp"
using namespace std;

/// Constructor: initializes the water bending system
WaterBender::WaterBender(string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    // Initialize water bending system
    waterBendingSystem = new WaterBending(); 
}

// Destructor: Cleanup pointer to prevent memory leaks
WaterBender::~WaterBender() {
    delete waterBendingSystem; // Free memory allocated in constructor
}

/// use bending system to perform a water bending action
void WaterBender::performAction() {
    int choice = 0; // Initialize choice variable for loop validation
    
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    waterBendingSystem->getAvailableBendingActions(*this); // Display available actions
    
    // Loop ensures the options 0-2 are selected (Validation)
    while (choice < 0 || choice > 2) { 
        cout << "Enter the number corresponding to your choice (0=Wave, 1=Shield, 2=Tidal): "; 
        cin >> choice; 
        
        if (choice < 0 || choice > 2) {
            cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl; 
        }
    }
    
    // Call the appropriate function in waterBendingSystem based on user selection.
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Wave Slash ---\n" << endl; 
            waterBendingSystem->waveSlash(*this);   
            break;
        case 1:
            cout << "\n--- Action Selected: Water Shield ---\n" << endl;
            waterBendingSystem->waterShield(*this);  
            break;
        case 2:
            cout << "\n--- Action Selected: Tidal Wave ---\n" << endl; 
            waterBendingSystem->tidalWave(*this);      
            break;
    }
}

/// Print WaterBender-specific stats in addition to base stats
void WaterBender::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: WaterBender" << endl;
    cout << "------------------------------------" << endl;
}

/// WaterBender-specific greeting
void WaterBender::greet() const {
    cout << name << " the WaterBender: Greetings! I am " << name << ". The waters are at my command, and I will use them to protect my allies" << endl;
}
