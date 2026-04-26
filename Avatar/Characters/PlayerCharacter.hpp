///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 13b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    PlayerCharacter.hpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
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
    int rollDice(int lower, int upper); // Function signature remains the same

    // Constructor and methods remain unchanged...

    ///getters (remain unchanged)
    int getHealth();
    int getAgility();
    int getDefense();
    int getStrength();
    BendingStyle getBendingStyle();

    ///setters - FIX: Changed signature to accept 'int' instead of 'int&'
    void setHealth(int newHealth); // Changed from int& to int (by value)
    void setAgility(int newAgility);
    void setDefense(int newDefense);
    void setStrength(int newStrength);
    // This method is fine as a reference because it validates and sets the internal member variable.
    void setBendingStyle(int& newBendingStyle); 

    ///print all stats to match prompt (remains unchanged)
    void printStats();
    // ... rest remains unchanged ...
};

#endif //PLAYERCHARACTER_H
