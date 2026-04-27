///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Bending_System.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Bending_System.hpp"
#include "PlayerCharacter.hpp"
using namespace std;

/// Constructor: initializes the bending system
BendingSystem::BendingSystem() {
    // Initialize any common bending system attributes if needed
}

/// Display available bending actions for a given character
std::vector<std::string> BendingSystem::getAvailableBendingActions(FighterCharacter& character) {
    cout << "Available bending actions for " << character.getName() << ":" << endl;
    // This function would contain logic to display bending actions based on character type
    return {}; // Placeholder return, replace with actual available actions (fixes warning)
}