///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    NPCEarthBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCEarthBender is a derived class of NPCharacter. EarthBenders use earth manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////

#ifndef NPCEARTHBENDER_HPP
#define NPCEARTHBENDER_HPP

#include "GameCharacter.hpp"
#include "NPCharacter.hpp"
#include "Earth_Bending.hpp" // CORRECT INCLUDE PATH
#include <string>

/// EarthBender: a profession derived from PlayerCharacter that specializes in earth manipulation
class NPCEarthBender : public NPCharacter {
    private:
        // Pointer to EarthBending system for performing earth bending actions
        EarthBending* earthBendingSystem;
        
    public:
        /// Constructor:
        explicit NPCEarthBender(std::string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~NPCEarthBender();
        
        /// use bending system to perform an earth bending action (REMOVED 'override' KEYWORD)
        virtual void performAction(FighterCharacter& target);
        
        /// Print EarthBender-specific stats in addition to base stats
        void printStats();
        
        /// EarthBender-specific greeting
        void greet() const override;
};
#endif //EARTHBENDER_HPP
