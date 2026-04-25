///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Rogue.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Rogue is a derived class of PlayerCharacter. Rogues are cunning thieves
/// who use stealth to perform ambushes, disguise themselves, and pick locks.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Rogue.hpp"

using namespace std;

/// Constructor: calls PlayerCharacter constructor, then sets Rogue stats
Rogue::Rogue(string& characterName, int& raceCode)
    : PlayerCharacter(characterName, raceCode) {
    stealth = rollDice(4, 10);
}

/// Getter for stealth
int Rogue::getStealth() {
    return stealth;
}

/// Setter for stealth
void Rogue::setStealth(int& newStealth) {
    stealth = newStealth;
}

/// Print all stats including Rogue-specific attributes
void Rogue::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: Rogue" << endl;
    cout << "Stealth: " << stealth << endl;
    cout << "------------------------------------" << endl;
}

/// Rogue greeting
void Rogue::greet() const {
    cout << name << " the Rogue: The name's " << name
         << ". Try not to draw attention to us." << endl;
}

/// Sneak attack: deals 2x damage if the Rogue is hidden (stealth >= 6)
void Rogue::sneakAttack() { // would need to take in an enemy object to actually deal damage, but for now just printing the damage amount
    cout << "\n" << name << " lines up a sneak attack from the shadows." << endl;
    if (stealth >= 6) {
        int baseDamage = rollDice(4, 10);
        int totalDamage = baseDamage * 2;
        cout << name << " strikes from the shadows! DOUBLE damage: "
             << totalDamage << " dealt!" << endl;
    } else {
        int damage = rollDice(4, 10);
        cout << name << " is spotted before attacking — regular hit for "
             << damage << " damage." << endl;
    }
}

/// Disguise self: boosts stealth temporarily by a random amount
void Rogue::disguiseSelf() {
    int boost = rollDice(1, 4);
    stealth += boost;
    cout << "\n" << name << " slips on a convincing disguise." << endl;
    cout << "Stealth increased by " << boost << "! New stealth: " << stealth << endl;
}

/// Pick lock: rolls against difficulty, needs >= 5 to succeed
void Rogue::pickLock() { // would need to take in a locked entity to actually unlock it, but for now just simulating. 
    cout << "\n" << name << " kneels down and examines the lock carefully." << endl;
    cout << "You need to roll at least a 5 to pick it." << endl;
    int roll = rollDice(1, 10);
    cout << "You rolled a " << roll << ". ";
    if (roll >= 5) {
        cout << "Click! The lock opens. " << name << " grins with satisfaction." << endl;
    } else {
        cout << "The pick slips. " << name << " will need to try again." << endl;
    }
}

/// performAction: user picks from the three Rogue abilities
void Rogue::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    cout << "(0 = Sneak Attack, 1 = Disguise Self, 2 = Pick Lock): ";
    cin >> choice;

    while (choice < 0 || choice > 2) {
        cout << "Invalid! Enter 0 = Sneak Attack, 1 = Disguise Self, 2 = Pick Lock: ";
        cin >> choice;
    }

    switch (choice) {
        case 0: sneakAttack();  break;
        case 1: disguiseSelf(); break;
        case 2: pickLock();     break;
    }
}
