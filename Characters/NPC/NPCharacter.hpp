///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    NPCharacter.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCharacter is a derived class of GameCharacter. NPCharacters are non-player characters that can be either allies or enemies in the game.
///////////////////////////////////////////////////////////////////////////////

#ifndef NPCHARACTER_HPP
#define NPCHARACTER_HPP

#include "FighterCharacter.hpp"
#include <string>

class NPCharacter : public FighterCharacter {
    public:
        // NPCs often use the same base constructor logic
        NPCharacter(std::string& characterName, int& bendingStyleCode);

        virtual ~NPCharacter() = default;

        // NPCs might have a different greeting than players
        void greet() const override;

        // Specific NPC logic (like AI-driven target selection)
        void performAction(FighterCharacter& target) override;
};

#endif
