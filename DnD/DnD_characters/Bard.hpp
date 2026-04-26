///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Bard.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Bard is a derived class of PlayerCharacter. Bards use inspiration and
/// illusions to distract enemies and support allies in creative ways.
///////////////////////////////////////////////////////////////////////////////

#ifndef BARD_HPP
#define BARD_HPP

#include "PlayerCharacter.hpp"
#include <string>

/// Bard: a performance and illusion profession derived from PlayerCharacter
class Bard : public PlayerCharacter {

protected:
    int inspirationUses; ///< number of inspiration uses remaining before rest

public:
    /// Constructor: sets name, race, and initializes Bard-specific stats
    Bard(std::string& characterName, int& raceCode);

    /// Getter for inspirationUses
    int getInspirationUses();

    /// Setter for inspirationUses
    void setInspirationUses(int& newUses);

    /// Create a weak illusion to distract an enemy
    void minorIllusion();

    /// Insult an enemy, potentially causing self-damage and disadvantage
    void viciousMockery();

    /// Repeat the most recent spell with increased strength
    void encore();

    /// User chooses which Bard ability to perform
    void performAction() override;

    /// Print Bard-specific stats in addition to base stats
    void printStats();

    /// Bard-specific greeting
    void greet() const override;
};

#endif // BARD_HPP
