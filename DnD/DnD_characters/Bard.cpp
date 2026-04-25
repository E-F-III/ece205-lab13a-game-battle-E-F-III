///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 12b - Game Character Class Part III (Polymorphism) - ECE 205 - Spring 2026
//
/// @file    Bard.cpp
/// @author  Edward Felipe III <efelipe3@hawaii.edu>
///
/// Bard is a derived class of PlayerCharacter. Bards use inspiration and
/// illusions to distract enemies and support allies in creative ways.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Bard.hpp"

using namespace std;

/// Constructor: calls PlayerCharacter constructor, then sets Bard stats
Bard::Bard(string& characterName, int& raceCode)
    : PlayerCharacter(characterName, raceCode) {
    inspirationUses = rollDice(3, 6); ///< start with 3–6 inspiration uses
}

/// Getter for inspirationUses
int Bard::getInspirationUses() {
    return inspirationUses;
}

/// Setter for inspirationUses
void Bard::setInspirationUses(int& newUses) {
    inspirationUses = newUses;
}

/// Print all stats including Bard-specific attributes
void Bard::printStats() {
    PlayerCharacter::printStats();
    cout << "Profession: Bard" << endl;
    cout << "Inspiration Uses: " << inspirationUses << endl;
    cout << "------------------------------------" << endl;
}

/// Bard greeting
void Bard::greet() const {
    cout << name << " the Bard: Greetings! I am " << name
         << ". Sit back and let my songs guide us to victory." << endl;
}

/// Create a weak illusion to distract an enemy
/// Rolls dice — needs >= 5 to succeed
void Bard::minorIllusion() { // would need to take in an enemy object to actually apply the distraction, but for now just simulating
    cout << "\n" << name << " conjures a flickering illusion to confuse the enemy." << endl;
    cout << "You need to roll at least a 5 to fool them." << endl;
    int roll = rollDice(1, 10);
    cout << "You rolled a " << roll << ". ";
    if (roll >= 5) {
        cout << "The illusion holds! The enemy is distracted for one round." << endl;
    } else {
        cout << "The illusion flickers out. The enemy is not fooled." << endl;
    }
}

/// Insult an enemy — may cause them disadvantage but risks self-damage
/// Roll >= 6 to land mockery; on a 1 the Bard takes recoil damage
void Bard::viciousMockery() { // would need to take in an enemy object to actually apply the effects, but for now just simulating
    cout << "\n" << name << " unleashes a devastating string of insults!" << endl;
    cout << "You need to roll at least a 6 to rattle the enemy." << endl;
    int roll = rollDice(1, 10);
    cout << "You rolled a " << roll << ". ";
    if (roll >= 6) {
        int penalty = rollDice(1, 4);
        cout << "The mockery lands! The enemy suffers -" << penalty
             << " on their next attack roll." << endl;
    } else if (roll == 1) {
        int selfDamage = rollDice(1, 4);
        cout << "The insult backfires! " << name << " takes "
             << selfDamage << " damage from embarrassment." << endl;
    } else {
        cout << "The enemy shrugs it off. They've heard worse." << endl;
    }
}

/// Repeat the most recent spell with increased strength
/// Costs 1 inspiration use; fails if none remain
void Bard::encore() { // would need to link this to the previous spell cast to actually repeat it, for now just simulating the effect
    if (inspirationUses <= 0) {
        cout << "\n" << name << " reaches for inspiration... but the well is dry." << endl;
        cout << "No inspiration uses remaining. Rest to recover." << endl;
        return;
    }
    inspirationUses--;
    int bonus = rollDice(2, 6);
    cout << "\n" << name << " channels their remaining inspiration for an encore!" << endl;
    cout << "The previous spell repeats with +" << bonus << " bonus power!" << endl;
    cout << "Inspiration uses remaining: " << inspirationUses << endl;
}

/// performAction: user picks from the three Bard abilities
void Bard::performAction() {
    int choice;
    cout << "\nGame Master: What would you like " << name << " to do?" << endl;
    cout << "(0 = Minor Illusion, 1 = Vicious Mockery, 2 = Encore): ";
    cin >> choice;

    while (choice < 0 || choice > 2) {
        cout << "Invalid! Enter 0 = Minor Illusion, 1 = Vicious Mockery, 2 = Encore: ";
        cin >> choice;
    }

    switch (choice) {
        case 0: minorIllusion();   break;
        case 1: viciousMockery();  break;
        case 2: encore();          break;
    }
}
