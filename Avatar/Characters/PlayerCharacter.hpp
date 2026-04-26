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

using namespace std;

///PlayerCharacter class declaration derived from GameCharacter
class PlayerCharacter : public GameCharacter {

  ///protected stats and race
  protected:
    int health;
    int agility;
    int defense;
    int strength;

    enum BendingStyle {
      air,
      earth,
      fire,
      water
    };

    BendingStyle bendingStyle;

  public:

    ///function to generate random number within range
    int rollDice(int lower, int upper);

    ///use pass by referance
    ///explicit no unintended type conversions
    ///constructor takes in address of the name and takes value of race as an int
    explicit PlayerCharacter(string& characterName, int& raceCode);

    ///getters
    int getHealth();
    int getAgility();
    int getDefense();
    int getStrength();
    BendingStyle getBendingStyle();

    ///setters
    void setHealth(int& newHealth);
    void setAgility(int& newAgility);
    void setDefense(int& newDefense);
    void setStrength(int& newStrength);
    void setBendingStyle(int& newBendingStyle);

    ///print all stats to match prompt
    void printStats();

    ///PlayerCharacter greeting using given name and generic message
    void greet() const override;

    ///from lab12a instructions
    
    virtual void performAction();

};

#endif //PLAYERCHARACTER_H
