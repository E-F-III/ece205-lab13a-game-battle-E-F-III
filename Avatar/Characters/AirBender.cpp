///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    AirBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// AirBender is a derived class of PlayerCharacter. AirBenders use air manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./AirBender.hpp"
#include "../BendingSystem/Air_Bending.hpp"

using namespace std;

/// Constructor: initializes the air bending system
AirBender::AirBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    airBendingSystem = new AirBending(); // Initialize the air bending system
}

/// use bending system to perform an air bending action
void AirBender::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    
    airBendingSystem->getAvailableBendingActions(*this); // Display available options
    
    int choice = 0; // Initialize choice variable for loop validation
    
    // Loop ensured the options 0-2 are selected
    while (choice < 0 || choice > 2) { 
        cout << "Enter the number corresponding to your choice (0=Slice, 1=Shield, 2=Flight): "; 
        cin >> choice; 
        
        if (choice < 0 || choice > 2) {
            cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl; 
        }
    }
    
    // Call the appropriate function in airBendingSystem based on user selection.
    switch (choice) {
        case 0:
            cout << "\n--- Action Selected: Air Slice ---\n" << endl; 
            airBendingSystem->airSlice(*this);   
            break;
        case 1:
            cout << "\n--- Action Selected: Air Shield ---\n" << endl;
            airBendingSystem->airShield(*this);  
            break;
        case 2:
            cout << "\n--- Action Selected: Flight ---\n" << endl; 
            airBendingSystem->flight(*this);      
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
    cout << name << " the AirBender: Greetings! I am " << name << ". The winds are at my command, and I will use them to protect my allies" << endl;
}
