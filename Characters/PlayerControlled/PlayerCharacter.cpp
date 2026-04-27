///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    PlayerCharacter.cpp
/// @author  Steven Daniel Javier <sdjavier@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <random>
#include "PlayerCharacter.hpp"
using namespace std;

/// constructor declaration for "PlayerCharacter"
/// takes in address of name from user and int corresponding to race
/// inherited from GameCharacter, note only the setName() member is used,
// (since no race member)
PlayerCharacter::PlayerCharacter(std::string& characterName, int& bendingStyleCode)
    : FighterCharacter(characterName, bendingStyleCode) 
{
    // No extra logic for now, but you could add player-specific initialization here if needed
}

///greeting using the name of PlayerCharacter
void PlayerCharacter::greet() const {
    cout << name << " : Hello, my name is " << name << ". How can I help with your quest?" << endl;
}

void PlayerCharacter::performAction(FighterCharacter& target) {
    cout << "I am performing an action  on " << target.getName() << "!" << endl;
}
