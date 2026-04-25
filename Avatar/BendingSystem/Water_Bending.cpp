///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Water_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Water_Bending.hpp"

using namespace std;

/// Constructor: initializes the water bending system
WaterBending::WaterBending() {
    // Initialize any water bending specific attributes if needed
}

// Healing Waters: a soothing wave of water that can heal allies
void WaterBending::healingWaters(PlayerCharacter& character) {
    cout << character.getName() << " performs Healing Waters! A soothing wave of water washes over them, healing their wounds." << endl;
    // Implement healing logic here
}

// Water Whip: a flexible whip of water that can strike enemies from a distance
void WaterBending::waterWhip(PlayerCharacter& character) {
    cout << character.getName() << " performs Water Whip! A flexible whip of water strikes out at the enemy from a distance." << endl;
    // Implement damage logic here
}

// Ice Barrier: creates a solid barrier of ice that can block attacks and protect allies
void WaterBending::iceBarrier(PlayerCharacter& character) {
    cout << character.getName() << " creates an Ice Barrier! A solid barrier of ice forms to block incoming attacks and protect allies." << endl;
    // Implement defense logic here
}   