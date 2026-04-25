///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab 11a - Game Character Class Part II - ECE 205 - Spring 2025
//
///
/// @file    main.cpp
/// @author  Steven Daniel Javier <sdjavier@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "PlayerCharacter.hpp"
#include "Bard.hpp"
#include "Rogue.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
using namespace std;

int main()
{
    string characterName;
    int characterRace;
    int characterProfession;

    //  --- Get character name
    cout << "Enter a name for your character: " << endl;
    getline(cin, characterName); 
    //  --- Get character race
    cout << "Enter a race for your character (0 = Human, 1 = Fishman, 2 = Giant, 3 = Dwarf): ";
    cin >> characterRace;

    // --- Get character profession ---
    cout << "Enter a profession (0 = Bard, 1 = Rogue, 2 = Paladin, 3 = Sorcerer): ";
    cin >> characterProfession;

    // Validate profession input
    while (characterProfession < 0 || characterProfession > 3) {
        cout << "Invalid! Enter 0 = Bard, 1 = Rogue, 2 = Paladin, 3 = Sorcerer: ";
        cin >> characterProfession;
    }

    // --- Create character (runtime polymorphism) ---
    PlayerCharacter* player = nullptr;

    switch (characterProfession) {
        case 0: player = new Bard(characterName, characterRace);     break;
        case 1: player = new Rogue(characterName, characterRace);    break;
        case 2: player = new Paladin(characterName, characterRace);  break;
        case 3: player = new Sorcerer(characterName, characterRace); break;
    }

    // --- Display stats and greet ---
    cout << endl;
    player->printStats();
    cout << endl;
    player->greet();


    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        player->performAction();

        cout << "\nWould you like to perform another action? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nFarewell, " << characterName << "! Until next time." << endl;

    // Note: PlayerCharacter has no virtual destructor.
    // Setting pointer to nullptr; OS reclaims memory on program exit.
    player = nullptr;

    return 0;
}

