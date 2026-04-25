///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Sorcerer.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Sorcerer is a derived class of PlayerCharacter. Sorcerers channel raw
/// magical energy through sorcery points to cast devastating spells.
///////////////////////////////////////////////////////////////////////////////

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "PlayerCharacter.hpp"
#include <string>

/// Sorcerer: an arcane spellcasting profession derived from PlayerCharacter
class Sorcerer : public PlayerCharacter {

protected:
    int sorceryPoints; ///< required and consumed when performing spells

public:
    /// Constructor: sets name, race, and initializes Sorcerer-specific stats
    Sorcerer(std::string& characterName, int& raceCode);

    /// Getter for sorceryPoints
    int getSorceryPoints();

    /// Setter for sorceryPoints
    void setSorceryPoints(int& newPoints);

    /// Hurl a ball of fire at an enemy, consuming sorcery points
    void fireball();

    /// Consume sorcery points to empower the next spell
    void metaMagic();

    /// User chooses which Sorcerer ability to perform
    void performAction() override;

    /// Print Sorcerer-specific stats in addition to base stats
    void printStats();

    /// Sorcerer-specific greeting
    void greet() const override;
};

#endif // SORCERER_HPP
