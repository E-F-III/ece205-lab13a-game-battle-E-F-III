///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    FireBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// FireBender is a derived class of PlayerCharacter. FireBenders use fire manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#ifndef FIREBENDER_HPP
#define FIREBENDER_HPP

#include "PlayerCharacter.hpp"
#include "../BendingSystem/Fire_Bending.hpp"

/// FireBender: a profession derived from PlayerCharacter that specializes in fire manipulation
class FireBender : public PlayerCharacter, public FireBending {
    
    private:
    // FireBender-specific attributes could be added here if needed
        FireBending* fireBendingSystem; ///< pointer to FireBending system for performing fire bending actions

    public:
    /// Constructor:
    FireBender(std::string& characterName, int& raceCode);

    /// use bending system to perform a fire bending action
    void performAction() override;

    /// Print FireBender-specific stats in addition to base stats
    void printStats();

    /// FireBender-specific greeting
    void greet() const override;

};

#endif