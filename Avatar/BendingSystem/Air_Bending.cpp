///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Air_Bending.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Air_Bending.hpp" 

using namespace std;

/// Constructor: initializes the air bending system
AirBending::AirBending() {
    // Initialize any air bending specific attributes if needed
}

// Air Slice: a quick, slicing gust of wind that can cut through enemies
void AirBending::airSlice(PlayerCharacter& character) {
    cout << character.getName() << " performs Air Slice! A sharp gust of wind cuts through the enemy." << endl;
    // Implement damage logic here
}

// Air Shield: creates a swirling barrier of wind that protects and deflects attacks
void AirBending::airShield(PlayerCharacter& character) {
    cout << character.getName() << " creates an Air Shield! A swirling barrier of wind protects them from incoming attacks." << endl;
    // Implement defense logic here
}

// Flight: allows the character to take to the skies, increasing mobility and evasion
void AirBending::flight(PlayerCharacter& character) {
    cout << character.getName() << " takes to the skies with Flight! They can now move freely and avoid ground-based attacks." << endl;
    // Implement flight logic here
}