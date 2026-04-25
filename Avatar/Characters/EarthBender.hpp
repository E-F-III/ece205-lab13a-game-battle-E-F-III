///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    EarthBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// EarthBender is a derived class of PlayerCharacter. EarthBenders use earth manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#ifndef EARTHBENDER_HPP
#define EARTHBENDER_HPP

#include "PlayerCharacter.hpp"
#include "../BendingSystem/Earth_Bending.hpp"

/// EarthBender: a profession derived from PlayerCharacter that specializes in earth manipulation
class EarthBender : public PlayerCharacter, public EarthBending {

    private:
    // EarthBender-specific attributes could be added here if needed
        EarthBending* earthBendingSystem; ///< pointer to EarthBending system for performing earth bending actions

    public:
    /// Constructor:
    EarthBender(std::string& characterName, int& raceCode);

    /// use bending system to perform an earth bending action
    void performAction() override;

    /// Print EarthBender-specific stats in addition to base stats
    void printStats();

    /// EarthBender-specific greeting
    void greet() const override;

};

#endif