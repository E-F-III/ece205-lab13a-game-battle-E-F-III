///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    AirBender.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
/// AirBender is a derived class of PlayerCharacter. AirBenders use air manipulation to fight enemies and protect allies.
/////////////////////////////////////////////////////////////////////////////////
#ifndef AIRBENDER_HPP
#define AIRBENDER_HPP
#include "PlayerCharacter.hpp"
#include "../BendingSystem/Air_Bending.hpp" // CORRECT INCLUDE PATH
#include <string>

/// AirBender: a profession derived from PlayerCharacter that specializes in air manipulation
class AirBender : public PlayerCharacter {
    private:
        // Pointer to AirBending system for performing air bending actions
        AirBending* airBendingSystem;
        
    public:
        /// Constructor:
        explicit AirBender(std::string& characterName, int& raceCode);
        // Destructor: Essential cleanup when using raw pointers
        ~AirBender();
        
        /// use bending system to perform an air bending action (REMOVED 'override' KEYWORD)
        virtual void performAction(PlayerCharacter& target);
        
        /// Print AirBender-specific stats in addition to base stats
        void printStats();
        
        /// AirBender-specific greeting
        void greet() const override;
};
#endif //AIRBENDER_HPP
