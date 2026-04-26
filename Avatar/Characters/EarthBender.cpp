///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    EarthBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// EarthBender is a derived class of PlayerCharacter. EarthBenders use earth manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./EarthBender.hpp"
#include "../BendingSystem/Earth_Bending.hpp"

using namespace std;

/// Constructor: initializes the earth bending system
EarthBender::EarthBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    earthBendingSystem = new EarthBending(); // Initialize the earth bending system
}

/// use bending system to perform an earth bending action
void EarthBender::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    earthBendingSystem->getAvailableBendingActions(*this); // Display available earth bending actions
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;  

    ///@Mendencan: The logic for performing the chosen earth bending action would go here. 
    ///@Mendencan: adjust the code to use pointers to the earth bending system and call the appropriate method based on the user's choice. For example:
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