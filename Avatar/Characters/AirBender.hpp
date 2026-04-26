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
#include "../BendingSystem/Air_Bending.hpp"
using namespace std;

/// AirBender: a profession derived from PlayerCharacter that specializes in air manipulation
class AirBender : public PlayerCharacter {
    private:
        // Pointer to the system object (raw pointer, requires manual memory management)
        AirBending* airBendingSystem; 
        
    public:
        /// Constructor: initializes the object and bending system
        explicit AirBender(string& characterName, int& raceCode);

        // Destructor: Essential for cleanup when using raw pointers allocated with 'new'.
        ~AirBender();
        
        /// Use bending system to perform an air bending action (overrides base class method)
        void performAction() override;
        
        /// Print AirBender-specific stats in addition to base stats
        void printStats();
        
        /// AirBender-specific greeting
        void greet() const override;
};

#endif //AIRBENDER_HPP
