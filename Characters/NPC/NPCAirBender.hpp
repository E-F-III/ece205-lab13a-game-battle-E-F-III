///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    NPCAirBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// NPCAirBender is a derived class of NPCharacter. AirBenders use air manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////
#ifndef NPCAIRBENDER_HPP
#define NPCAIRBENDER_HPP

#include "GameCharacter.hpp"
#include "NPCharacter.hpp"
#include "Air_Bending.hpp" // CORRECT INCLUDE PATH
#include <string>

/// AirBender: a profession derived from PlayerCharacter that specializes in air manipulation
class NPCAirBender : public NPCharacter {
    private:
        // Pointer to AirBending system for performing air bending actions
        AirBending* airBendingSystem;
        
    public:
        /// Constructor:
        explicit NPCAirBender(std::string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~NPCAirBender();
        
        /// use bending system to perform an air bending action (REMOVED 'override' KEYWORD)
        virtual void performAction(FighterCharacter& target);
        
        /// Print AirBender-specific stats in addition to base stats
        void printStats();
        
        /// AirBender-specific greeting
        void greet() const override;
};
#endif //AIRBENDER_HPP
