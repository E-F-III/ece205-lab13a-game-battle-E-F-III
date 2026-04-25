///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Earth_Bending.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// EarthBender is a derived class of BendingSystem. EarthBenders use earth manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////

#ifndef EARTH_BENDING_HPP
#define EARTH_BENDING_HPP

#include "Bending_System.hpp"

/// EarthBending: manages earth bending abilities for EarthBender characters
class EarthBending : public BendingSystem {
    public:
    /// Constructor: initializes the earth bending system
    EarthBending();
    
    void earthSpike(PlayerCharacter& character);
    void rockShield(PlayerCharacter& character);
    void seismicSlam(PlayerCharacter& character);

    /// Display available earth bending actions for a given character
    std::vector<std::string> getAvailableBendingActions(PlayerCharacter& character) override;
};

#endif
