///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    AirBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// AirBender is a derived class of PlayerCharacter. AirBenders use air manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "./AirBender.hpp"

using namespace std;

/// Constructor: initializes the air bending system
AirBender::AirBender(std::string& characterName, int& raceCode) : PlayerCharacter(characterName, raceCode) {
    airBendingSystem = new AirBending(); // Initialize the air bending system
}

/// use bending system to perform an air bending action
void AirBender::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    
    airBendingSystem->getAvailableBendingActions(*this); // Display available air bending actions
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;

    // @Mendencan: The logic for performing the chosen air bending action would go here. For example:
    // @Mendencan: adjust the code to use pointers to the air bending system and call the appropriate method based on the user's choice. For example:

    // while (choice < 0 || choice > 2) {
    //     cout << "Invalid! Enter 0 = Minor Illusion, 1 = Vicious Mockery, 2 = Encore: ";
    //     cin >> choice;
    // }

    // switch (choice) {
    //     case 0: minorIllusion();   break;
    //     case 1: viciousMockery();  break;
    //     case 2: encore();          break;
    // }
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
