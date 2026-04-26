///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Paladin.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Paladin is a derived class of PlayerCharacter. Paladins are holy warriors
/// whose aura strengthens nearby allies and can heal or smite in combat.
///////////////////////////////////////////////////////////////////////////////

#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "PlayerCharacter.hpp"
#include <string>

/// Paladin: a holy warrior profession derived from PlayerCharacter
class Paladin : public PlayerCharacter {

protected:
    int auraStrength; ///< increases nearby allies' defensive stats by this value

public:
    /// Constructor: sets name, race, and initializes Paladin-specific stats
    Paladin(std::string& characterName, int& raceCode);

    /// Getter for auraStrength
    int getAuraStrength();

    /// Setter for auraStrength
    void setAuraStrength(int& newAura);

    /// Heal another character based on auraStrength
    void layOnHands();

    /// Deal damage to an enemy based on auraStrength
    void smite();

    /// User chooses which Paladin ability to perform
    void performAction() override;

    /// Print Paladin-specific stats in addition to base stats
    void printStats();

    /// Paladin-specific greeting
    void greet() const override;
};

#endif // PALADIN_HPP
