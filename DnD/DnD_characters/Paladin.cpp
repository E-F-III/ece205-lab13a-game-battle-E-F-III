///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Paladin.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Paladin is a derived class of PlayerCharacter. Paladins are holy warriors
/// whose aura strengthens nearby allies and can heal or smite in combat.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Paladin.hpp"

using namespace std;

/// Constructor: calls PlayerCharacter constructor, then sets Paladin stats
Paladin::Paladin(string& characterName, int& raceCode)
    : PlayerCharacter(characterName, raceCode) {
    auraStrength = rollDice(3, 10);
}

/// Getter for auraStrength
int Paladin::getAuraStrength() {
    return auraStrength;
}

/// Setter for auraStrength
void Paladin::setAuraStrength(int& newAura) {
    auraStrength = newAura;
}

/// Print all stats including Paladin-specific attributes
void Paladin::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: Paladin" << endl;
    cout << "Aura Strength: " << auraStrength << endl;
    cout << "------------------------------------" << endl;
}

/// Paladin greeting
void Paladin::greet() const {
    cout << name << " the Paladin: I am " << name
         << ". My oath is my shield and my sword." << endl;
}

/// Lay on Hands: heal an ally — amount is based on auraStrength
void Paladin::layOnHands() { // would need to take in an ally object to actually heal them, but for now just printing the heal amount
    int healAmount = rollDice(5, 10) + auraStrength;
    cout << "\n" << name << " places their hands on an ally, channeling holy light." << endl;
    cout << "The ally recovers " << healAmount << " HP!" << endl;
    cout << "(Aura Strength bonus: +" << auraStrength << ")" << endl;
}

/// Smite: deal holy damage scaled by auraStrength; needs roll >= 6 to land
void Paladin::smite() { // would need to take in an enemy object to actually deal damage, but for now just printing the damage amount
    cout << "\n" << name << " calls upon divine power to smite the enemy!" << endl;
    cout << "You need to roll at least a 6 to land the smite." << endl;
    int roll = rollDice(1, 10);
    cout << "You rolled a " << roll << ". ";
    if (roll >= 6) {
        int damage = rollDice(4, 8) + auraStrength;
        cout << "Divine light strikes! The enemy takes " << damage
             << " holy damage! (Aura bonus: +" << auraStrength << ")" << endl;
    } else {
        cout << "The smite fizzles. The enemy is untouched." << endl;
    }
}

/// performAction: user picks Lay on Hands or Smite
void Paladin::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    cout << "(0 = Lay on Hands, 1 = Smite): ";
    cin >> choice;

    while (choice < 0 || choice > 1) {
        cout << "Invalid! Enter 0 = Lay on Hands, 1 = Smite: ";
        cin >> choice;
    }

    switch (choice) {
        case 0: layOnHands(); break;
        case 1: smite();      break;
    }
}
