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

    //  --- Get character name --- [cite: 3]
    cout << "Enter a name for your character: " << endl;
    getline(cin, characterName); 
    
    //  --- Get character race --- [cite: 4]
    cout << "Enter a race for your character (0 = Human, 1 = Fishman, 2 = Giant, 3 = Dwarf): ";
    cin >> characterRace;

    // --- Get character bending style --- [cite: 5]
    cout << "Enter a bending style (0 = Air, 1 = Earth, 2 = Fire, 3 = Water): ";
    cin >> characterBendingStyle;

    // Validate bending style input [cite: 6, 7]
    while (characterBendingStyle < 0 || characterBendingStyle > 3) {
        cout << "Invalid! Enter 0 = Air, 1 = Earth, 2 = Fire, 3 = Water: ";
        cin >> characterBendingStyle;
    }

    // --- Create player character (runtime polymorphism) --- [cite: 8]
    PlayerCharacter* player = nullptr;
    switch (characterBendingStyle) {
         case 0: player = new AirBender(characterName, characterRace);   break;
        case 1: player = new EarthBender(characterName, characterRace); break;
        case 2: player = new FireBender(characterName, characterRace);  break;
        case 3: player = new WaterBender(characterName, characterRace); break;
    }

    // --- INITIALIZE BOB (The Target) ---
    // We create Bob as a generic PlayerCharacter to act as our punching bag
    string bobName = "Bob";
    int bobRace = 0; // Human
    PlayerCharacter bob(bobName, bobRace);

    // --- Display stats and greet ---
    cout << endl;
    player->printStats(); 
    cout << endl;
    player->greet(); 

    cout << "\n=== A wild BOB appears for target practice! ===" << endl;
    bob.printStats();

    char playAgain = 'y';
    // The loop continues as long as you want to play AND Bob is still standing
    while ((playAgain == 'y' || playAgain == 'Y') && bob.getHealth() > 0) {
        
        // We pass 'bob' into the action so your math affects Bob's health
        player->performAction(bob); 
        cout << "\nyour's Remaining Health: " << player->getHealth() << endl;
        cout << "\nBob's Remaining Health: " << bob.getHealth() << endl;

        if (bob.getHealth() <= 0) {
            cout << "Bob has been defeated! Practice session over." << endl;
            break;
        }

        cout << "\nWould you like to perform another action on Bob? (y/n): "; 
        cin >> playAgain;
    } 

    cout << "\nFarewell, " << characterName << "! Until next time." << endl; 
    
    // Clean up
    delete player;

    return 0;
}
