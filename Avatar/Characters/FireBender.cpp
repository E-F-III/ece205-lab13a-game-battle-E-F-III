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
FireBender::FireBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    fireBendingSystem = new FireBending(); // Initialize the fire bending system
}

/// use bending system to perform a fire bending action
void FireBender::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    fireBendingSystem->getAvailableBendingActions(*this); // Display available fire bending actions
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;  

    ///@Mendencan: The logic for performing the chosen fire bending action would go here. 
    ///@Mendencan: adjust the code to use pointers to the fire bending system and call the appropriate method based on the user's choice. For example:
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
