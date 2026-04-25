///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Earth_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Earth_Bending.hpp"

using namespace std;

/// Constructor: initializes the earth bending system
EarthBending::EarthBending() {
    // Initialize any earth bending specific attributes if needed
}

// Earth Spike: a sharp spike of earth that can impale enemies
void EarthBending::earthSpike(PlayerCharacter& character) {
    cout << character.getName() << " performs Earth Spike! A sharp spike of earth shoots up to impale the enemy." << endl;
    // Implement damage logic here
}

// Rock Shield: creates a sturdy shield of rock that can block attacks
void EarthBending::rockShield(PlayerCharacter& character) {
    cout << character.getName() << " creates a Rock Shield! A sturdy shield of rock forms to block incoming attacks." << endl;
    // Implement defense logic here
}

// Seismic Slam: slams the ground to create a shockwave that damages and knocks back enemies
void EarthBending::seismicSlam(PlayerCharacter& character) {
    cout << character.getName() << " performs Seismic Slam! They slam the ground, creating a shockwave that damages and knocks back enemies." << endl;
    // Implement area damage and knockback logic here
}