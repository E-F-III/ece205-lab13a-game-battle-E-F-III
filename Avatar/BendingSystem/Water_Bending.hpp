///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Water_Bending.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// WaterBending is a derived class of BendingSystem. WaterBenders use water manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////

#ifndef WATER_BENDING_HPP
#define WATER_BENDING_HPP
#endif

#include "Bending_System.hpp"

/// WaterBending: manages water bending abilities for WaterBender characters
class WaterBending : public BendingSystem {
public:
    /// Constructor: initializes the water bending system
    WaterBending();
    
    void healingWaters(PlayerCharacter& character);
    void waterWhip(PlayerCharacter& character);
    void iceBarrier(PlayerCharacter& character);

};