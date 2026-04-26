///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    NPCFireBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCFireBender is a derived class of NPCharacter. FireBenders use fire manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#ifndef NPCFIREBENDER_HPP
#define NPCFIREBENDER_HPP

#include "GameCharacter.hpp"
#include "NPCharacter.hpp"
#include "Fire_Bending.hpp" // CORRECT INCLUDE PATH
#include <string>

/// NPCFireBender: a profession derived from PlayerCharacter that specializes in fire manipulation
class NPCFireBender : public NPCharacter {
    private:
        // Pointer to FireBending system for performing fire bending actions
        FireBending* fireBendingSystem;
        
    public:
        /// Constructor:
        explicit NPCFireBender(std::string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~NPCFireBender();
        
        /// use bending system to perform a fire bending action
        virtual void performAction(FighterCharacter& target);
        
        /// Print NPCFireBender-specific stats in addition to base stats
        void printStats();
        
        /// NPCFireBender-specific greeting
        void greet() const override;
};
#endif //NPCFireBender_HPP
