///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    NPC_Character.hpp
/// @author  Steven Daniel Javier <sdjavier@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef NPC_CHARACTER_H
#define NPC_CHARACTER_H
#include "GameCharacter.hpp" ///base class
#include <string>

enum BendingStyle {
    air,
    earth,
    fire,
    water
};

class NPC_Character : public GameCharacter {
protected:
    int health;
    int strength;
    int agility;
    int defense;
    int bendingStyle;

public:
    NPC_Character(std::string& characterName, int& bendingStyleCode);
    
    /// Virtual Destructor added to fix undefined behavior warning during deletion
    virtual ~NPC_Character() = default;

    int getHealth();
    int getAgility();
    int getDefense();
    int getStrength();
    int getBendingStyle();

    void setHealth(int health);
    void setStrength(int strength);
    void setAgility(int agility);
    void setDefense(int defense);
    void setBendingStyle(int bendingStyleChoice);

    static int rollDice(int lower, int upper);
    
    void printStats();

    ///NPC_Character greeting using given name and generic message
    void greet() const override;

    ///from lab12a instructions
    virtual void performAction(NPC_Character& target);
};

#endif //NPC_Character_H
