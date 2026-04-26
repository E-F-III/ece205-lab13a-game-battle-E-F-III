///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    FireBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// FireBender is a derived class of PlayerCharacter. FireBenders use fire manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////
#ifndef FIRE_BENDER_HPP
#define FIRE_BENDER_HPP
#include "PlayerCharacter.hpp"
// FIX: Use underscores in the include path to match the filename structure provided.
#include "../BendingSystem/Fire_Bending.hpp" 

/// FireBender: a profession derived from PlayerCharacter that specializes in fire manipulation
class FireBender : public PlayerCharacter {
    private:
        // Pointer to FireBending system for performing fire bending actions
        FireBending* fireBendingSystem; 
        
    public:
        /// Constructor:
        explicit FireBender(string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~FireBender();
        /// use bending system to perform a fire bending action (REMOVED 'override' KEYWORD)
        void performAction();
        
        /// Print FireBender-specific stats in addition to base stats
        void printStats();
        
        /// FireBender-specific greeting
        void greet() const override;
};
#endif //FIRE_BENDER_HPP
