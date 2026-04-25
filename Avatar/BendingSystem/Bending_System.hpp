///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Bending_System.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Bending_System is a class that manages the bending abilities of different character types.
///////////////////////////////////////////////////////////////////////////////

#ifndef BENDING_SYSTEM_HPP
#define BENDING_SYSTEM_HPP

#include <vector>
#include <string>

#include "../Characters/PlayerCharacter.hpp"

/// BendingSystem: manages bending abilities for different character types
class BendingSystem {
    public:
    /// Constructor: initializes the bending system
    BendingSystem();
    virtual ~BendingSystem() = default; // Virtual destructor for proper cleanup of derived classes
    
    /// Activate bending abilities for a given character
    virtual void performBendingAction(PlayerCharacter& character);
    
    /// Display available bending actions for a given character
    virtual std::vector<std::string> getAvailableBendingActions(PlayerCharacter& character);
};

#endif