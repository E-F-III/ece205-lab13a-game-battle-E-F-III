///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    WaterBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// WaterBender is a derived class of PlayerCharacter. WaterBenders use water manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./PlayerCharacter.hpp"
#include "./WaterBender.hpp"
#include "../BendingSystem/Water_Bending.hpp"

using namespace std;

/// Constructor: initializes the water bending system
WaterBender::WaterBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    waterBendingSystem = new WaterBending(); // Initialize the water bending system
}

/// use bending system to perform a water bending action
void WaterBender::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    waterBendingSystem->getAvailableBendingActions(*this); // Display available water bending actions
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;  

    ///@Mendencan: The logic for performing the chosen water bending action would go here. 
    ///@Mendencan: adjust the code to use pointers to the water bending system and call the appropriate method based on the user's choice. For example:
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
