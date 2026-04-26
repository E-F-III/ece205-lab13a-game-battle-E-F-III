///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    WaterBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// WaterBender is a derived class of PlayerCharacter. 
/// WaterBenders use water manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////

#ifndef WATERBENDER_HPP
#define WATERBENDER_HPP

#include "PlayerCharacter.hpp"
#include "../BendingSystem/Water_Bending.hpp"

/// WaterBender: a profession derived from PlayerCharacter that specializes in water manipulation
class WaterBender : public PlayerCharacter, public WaterBending {

    private:
    // WaterBender-specific attributes could be added here if needed
        WaterBending* waterBendingSystem; ///< pointer to WaterBending system for performing water bending actions

    public:
    /// Constructor:
    WaterBender(std::string& characterName, int& raceCode);

    /// use bending system to perform a water bending action
    void performAction() override;

    /// Print WaterBender-specific stats in addition to base stats
    void printStats();

    /// WaterBender-specific greeting
    void greet() const override;

};  

#endif