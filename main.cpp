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

// #include "PlayerCharacter.hpp"
#include "./Avatar/Characters/PlayerCharacter.hpp"
#include "./Avatar/Characters/AirBender.hpp"
#include "./Avatar/Characters/EarthBender.hpp"
#include "./Avatar/Characters/FireBender.hpp"
#include "./Avatar/Characters/WaterBender.hpp"

using namespace std;

int main()
{
    string characterName;
    int characterRace;
    int characterBendingStyle;

    //  --- Get character name
    cout << "Enter a name for your character: " << endl;
    getline(cin, characterName); 
    //  --- Get character race
    cout << "Enter a race for your character (0 = Human, 1 = Fishman, 2 = Giant, 3 = Dwarf): ";
    cin >> characterRace;

    // --- Get character bending style ---
    cout << "Enter a bending style (0 = Air, 1 = Earth, 2 = Fire, 3 = Water): ";
    cin >> characterBendingStyle;

    // Validate bending style input
    while (characterBendingStyle < 0 || characterBendingStyle > 3) {
        cout << "Invalid! Enter 0 = Air, 1 = Earth, 2 = Fire, 3 = Water: ";
        cin >> characterBendingStyle;
    }

    // --- Create character (runtime polymorphism) ---
    PlayerCharacter* player = nullptr;

    switch (characterBendingStyle) {
        case 0: player = new AirBender(characterName, characterRace);     break;
        case 1: player = new EarthBender(characterName, characterRace);    break;
        case 2: player = new FireBender(characterName, characterRace);  break;
        case 3: player = new WaterBender(characterName, characterRace); break;
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

