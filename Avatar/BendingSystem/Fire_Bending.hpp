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
#endif

#include "Bending_System.hpp"

/// FireBending: manages fire bending abilities for FireBender characters
class FireBending : public BendingSystem {
public:
    /// Constructor: initializes the fire bending system
    FireBending();

    void fireBlast(PlayerCharacter& character);
    void fireBreath(PlayerCharacter& character);
    void lightningStrike(PlayerCharacter& character);
};