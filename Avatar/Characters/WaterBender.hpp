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
#include <string>

/// WaterBender: a water manipulation profession derived from PlayerCharacter
class WaterBender : public PlayerCharacter {
    protected:
    int waterManipulationLevel; ///< level of water manipulation skill

    public:
    /// Constructor:
    WaterBender(std::string& characterName);

    /// Getter for waterManipulationLevel
    int getWaterManipulationLevel();

    /// Setter for waterManipulationLevel
    void setWaterManipulationLevel(int& newLevel);

    /// Create a water whip to strike an enemy
    void waterWhip();
    /// Heal an ally using water's restorative properties
    void healingWaters();
    /// Create a protective water shield to reduce incoming damage
    void waterShield();

    /// User chooses which WaterBender ability to perform
    void performAction() override;

    /// Print WaterBender-specific stats in addition to base stats
    void printStats();

    /// WaterBender-specific greeting
    void greet() const override;

};