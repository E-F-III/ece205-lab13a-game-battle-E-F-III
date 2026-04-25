///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Rogue.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Rogue is a derived class of PlayerCharacter. Rogues are cunning thieves
/// who use stealth to perform ambushes, disguise themselves, and pick locks.
///////////////////////////////////////////////////////////////////////////////

#ifndef ROGUE_HPP
#define ROGUE_HPP

#include "PlayerCharacter.hpp"
#include <string>

/// Rogue: a stealth and trickery profession derived from PlayerCharacter
class Rogue : public PlayerCharacter {

protected:
    int stealth; ///< efficiency at performing attacks without being caught

public:
    /// Constructor: sets name, race, and initializes Rogue-specific stats
    Rogue(std::string& characterName, int& raceCode);

    /// Getter for stealth
    int getStealth();

    /// Setter for stealth
    void setStealth(int& newStealth);

    /// Attack that deals 2x damage if the Rogue is undetected
    void sneakAttack();

    /// Wear a disguise to temporarily increase stealth
    void disguiseSelf();

    /// Attempt to unlock a locked item without a key
    void pickLock();

    /// User chooses which Rogue ability to perform
    void performAction() override;

    /// Print Rogue-specific stats in addition to base stats
    void printStats();

    /// Rogue-specific greeting
    void greet() const override;
};

#endif // ROGUE_HPP
