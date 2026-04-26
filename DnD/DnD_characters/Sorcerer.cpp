///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Sorcerer.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Sorcerer is a derived class of PlayerCharacter. Sorcerers channel raw
/// magical energy through sorcery points to cast devastating spells.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Sorcerer.hpp"

using namespace std;

/// Constructor: calls PlayerCharacter constructor, then sets Sorcerer stats
Sorcerer::Sorcerer(string& characterName, int& raceCode)
    : PlayerCharacter(characterName, raceCode) {
    sorceryPoints = rollDice(5, 10); ///< start with 5–10 sorcery points
}

/// Getter for sorceryPoints
int Sorcerer::getSorceryPoints() {
    return sorceryPoints;
}

/// Setter for sorceryPoints
void Sorcerer::setSorceryPoints(int& newPoints) {
    sorceryPoints = newPoints;
}

/// Print all stats including Sorcerer-specific attributes
void Sorcerer::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: Sorcerer" << endl;
    cout << "Sorcery Points: " << sorceryPoints << endl;
    cout << "------------------------------------" << endl;
}

/// Sorcerer greeting
void Sorcerer::greet() const {
    cout << name << " the Sorcerer: I am " << name
         << ". Magic flows through my veins — step aside." << endl;
}

/// Fireball: costs 2 sorcery points; deals fire damage on a roll >= 5
void Sorcerer::fireball() { // would need to take in an enemy object to actually deal damage, but for now just simulating
    const int cost = 2;
    if (sorceryPoints < cost) {
        cout << "\n" << name << " reaches for magical energy..." << endl;
        cout << "Not enough sorcery points! Need " << cost
             << ", have " << sorceryPoints << "." << endl;
        return;
    }

    sorceryPoints -= cost;
    cout << "\n" << name << " hurls a blazing fireball at the enemy!" << endl;
    cout << "You need to roll at least a 5 to hit." << endl;
    int roll = rollDice(1, 10);
    cout << "You rolled a " << roll << ". ";
    if (roll >= 5) {
        int damage = rollDice(6, 14);
        cout << "Boom! The fireball connects for " << damage << " fire damage!" << endl;
    } else {
        cout << "The fireball sails wide. The enemy dives out of the way." << endl;
    }
    cout << "Sorcery points remaining: " << sorceryPoints << endl;
}

/// Meta Magic: costs 1 sorcery point to empower the next spell (+bonus damage)
void Sorcerer::metaMagic() { // would need to link this to next spell cast to apply bonus, for now just simulating
    const int cost = 1;
    if (sorceryPoints < cost) {
        cout << "\n" << name << " tries to twist their magic..." << endl;
        cout << "No sorcery points left to fuel Meta Magic." << endl;
        return;
    }

    sorceryPoints -= cost;
    int bonus = rollDice(3, 8);
    cout << "\n" << name << " bends the weave of magic itself!" << endl;
    cout << "The next spell gains +" << bonus << " bonus damage." << endl;
    cout << "Sorcery points remaining: " << sorceryPoints << endl;
}

/// performAction: user picks Fireball or Meta Magic
void Sorcerer::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    cout << "(0 = Fireball, 1 = Meta Magic): ";
    cin >> choice;

    while (choice < 0 || choice > 1) {
        cout << "Invalid! Enter 0 = Fireball, 1 = Meta Magic: ";
        cin >> choice;
    }

    switch (choice) {
        case 0: fireball();   break;
        case 1: metaMagic();  break;
    }
}
