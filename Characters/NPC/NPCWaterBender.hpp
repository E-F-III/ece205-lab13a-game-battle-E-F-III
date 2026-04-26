///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    NPCWaterBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCWaterBender is a derived class of NPCharacter. WaterBenders use water manipulation to fight enemies and protect allies.
///////////////////////////////////////////////////////////////////////////////

#ifndef NPCWATERBENDER_HPP
#define NPCWATERBENDER_HPP

#include "GameCharacter.hpp"
#include "NPCharacter.hpp"
#include "Water_Bending.hpp" // CORRECT INCLUDE PATH
#include <string>

/// WaterBender: a profession derived from NPCharacter that specializes in water manipulation
class NPCWaterBender : public NPCharacter {
    private:
        // Pointer to WaterBending system for performing water bending actions
        WaterBending* waterBendingSystem; 
        
    public:
        /// Constructor:
        explicit NPCWaterBender(std::string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~NPCWaterBender();
        
        /// use bending system to perform a water bending action
        virtual void performAction(GameCharacter& target);
        
        /// Print NPC-specific stats in addition to base stats
        void printStats();
        
        /// NPC-specific greeting
        void greet() const override;
};
#endif //NPC_HPP
