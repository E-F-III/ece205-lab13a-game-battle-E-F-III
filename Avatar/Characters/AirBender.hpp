///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    AirBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// AirBender is a derived class of PlayerCharacter. AirBenders use air manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////

#ifndef AIRBENDER_HPP
#define AIRBENDER_HPP

#include "PlayerCharacter.hpp"
#include "../BendingSystem/Air_Bending.hpp"

/// AirBender: a profession derived from PlayerCharacter that specializes in air manipulation
class AirBender : public PlayerCharacter, public AirBending {

    private:
    // AirBender-specific attributes could be added here if needed
        AirBending* airBendingSystem; ///< pointer to AirBending system for performing air bending actions

    public:
    /// Constructor:
    AirBender(std::string& characterName, int& raceCode);

    /// use bending system to perform an air bending action
    void performAction() override;

    /// Print AirBender-specific stats in addition to base stats
    void printStats();

    /// AirBender-specific greeting
    void greet() const override;

};

#endif