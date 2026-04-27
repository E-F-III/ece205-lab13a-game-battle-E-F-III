///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Fire_Bending.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// FireBender is a derived class of BendingSystem. FireBenders use fire manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////
#ifndef FIRE_BENDING_HPP
#define FIRE_BENDING_HPP
#include "Bending_System.hpp"
/// FireBending: manages fire bending abilities for FireBender characters
class FireBending : public BendingSystem { // Base class is BendingSystem
public:
    /// Constructor: initializes the fire bending system
    FireBending();
    void fireBlast(FighterCharacter& character, FighterCharacter& target);
    void fireBreath(FighterCharacter& character, FighterCharacter& target);
    void lightningStrike(FighterCharacter& character, FighterCharacter& target);
    /// Display available fire bending actions for a given character
    std::vector<std::string> getAvailableBendingActions(FighterCharacter& character) override; // Keep virtual and override here
};
#endif