///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    PlayerCharacter.hpp
/// @author  Steven Daniel Javier <sdjavier@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "GameCharacter.hpp" ///base class
#include <string>

enum BendingStyle {
    air,
    earth,
    fire,
    water
};

class PlayerCharacter : public GameCharacter {
protected:
    int health;
    int strength;
    int agility;
    int defense;
    int bendingStyle;

public:
    PlayerCharacter(std::string& characterName, int& bendingStyleCode);
    
    /// Virtual Destructor added to fix undefined behavior warning during deletion
    virtual ~PlayerCharacter() = default;

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

    ///PlayerCharacter greeting using given name and generic message
    void greet() const override;

    ///from lab12a instructions
    virtual void performAction(PlayerCharacter& target);
};

#endif //PLAYERCHARACTER_H
