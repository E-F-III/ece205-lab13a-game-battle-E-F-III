///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    FighterCharacter.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// FighterCharacter is a derived class of GameCharacter.
/// FighterCharacters are GameCharacters that specialize in physical combat, using their strength and agility to defeat enemies.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <random>

#include "GameCharacter.hpp"
#include "FighterCharacter.hpp"

using namespace std;

int FighterCharacter::rollDice(int lower, int upper) {
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> distribution(lower, upper);
    return distribution(engine);
}

FighterCharacter::FighterCharacter(std::string& name, int& styleCode) : GameCharacter(name) {
    this->health = 100;
    this->strength = rollDice(0, 10);
    this->agility = rollDice(0, 10);
    this->defense = rollDice(0, 10);
    setBendingStyle(styleCode); // Set the style only for fighters.
}

void FighterCharacter::setBendingStyle(int choice) {
    switch (choice) {
        case 0: bendingStyle = air; break;
        case 1: bendingStyle = earth; break;
        case 2: bendingStyle = fire; break;
        case 3: bendingStyle = water; break;
    }
}

void FighterCharacter::printStats() {
    std::string styleNames[] = {"Air", "Earth", "Fire", "Water"};
    std::cout << "--- " << name << " Stats ---" << std::endl;
    std::cout << "Bending: " << styleNames[bendingStyle] << std::endl;
    std::cout << "Health: " << health << std::endl;
}

// perform action is a placeholder for now, but it will be the main function that handles combat logic and interactions with other characters.
void FighterCharacter::performAction(FighterCharacter& target) {
    std::cout << name << " performs a basic attack on " << target.getName() << "!" << std::endl;
    // Basic attack logic can be implemented here, and this method can be overridden by derived classes for more specific actions.
}