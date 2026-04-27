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

// INCLUDE NPC HEADER FILES: (ignore red lines)

#include "NPCAirBender.hpp"
#include "NPCEarthBender.hpp"
#include "NPCFireBender.hpp"
#include "NPCWaterBender.hpp"





using namespace std;

// -- helper functions --

// createCharacter: were going to create a character

PlayerCharacter* createCharacter(std::string label) {
    std::string characterName;
    int bendingCode; // bring code for Bending 
    
    std::cout << "\nEnter a name for " << label << ": "; // user enters name for their character 
    std::cin.ignore(1000, '\n'); // Clear buffer properly
    std::getline(std::cin, characterName); // sprint name 

    std::cout << "Enter a bending style (0=Air, 1=Earth, 2=Fire, 3=Water): "; // user chooses  a bending style 
    while (!(std::cin >> bendingCode) || bendingCode < 0 || bendingCode > 3) { // error check
        std::cout << "Invalid! Enter 0-3: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    PlayerCharacter* character = nullptr; // point to null value to erase cache
    switch (bendingCode) {
        case 0: character = new AirBender(characterName, bendingCode); break; // AIRBENDER 
        case 1: character = new EarthBender(characterName, bendingCode); break; // EARTHBENDER 
        case 2: character = new FireBender(characterName, bendingCode); break; // FIREBENDER 
        case 3: character = new WaterBender(characterName, bendingCode); break; // WATERBENDER 
    }
    // .... printStats and Greet()
    if (character) { 
        character->printStats();
        character->greet();
    }
    return character;
}


// NPC implementation; create a NPC, max 4 types

NPCharacter* createNPC(std::string label) {
    int bendingCode = rand() % 4;
    NPCharacter* character = nullptr;

    switch (bendingCode) {
        case 0: character = new NPCAirBender(label, bendingCode); break;
        case 1: character = new NPCEarthBender(label, bendingCode); break;
        case 2: character = new NPCFireBender(label, bendingCode); break;
        case 3: character = new NPCWaterBender(label, bendingCode); break;
    }
    return character;
}

// partyAlive: checks health for the party @TODO EFiii, check this please
bool partyAlive(std::vector<PlayerCharacter*> party)
{
    for (PlayerCharacter* character : party) {
        if (character->getHealth() > 0) { // if char is alive
            return true; // we are good
        }
    }
    return false;
}



// void displayHealth: shows each players health 

void displayHealth(const std::vector<FighterCharacter*>& players, const std::vector<FighterCharacter*>& enemies) {
    std::cout << "\n========== HEALTH STATUS ==========\n";
    std::cout << "Players:\n";
    for (auto p : players) std::cout << " - " << p->getName() << ": " << p->getHealth() << "\n";
    std::cout << "\nEnemies:\n";
    for (auto e : enemies) std::cout << " - " << e->getName() << ": " << e->getHealth() << "\n";
    std::cout << "===================================\n";
}



// void attackTarget: attacks the player

// void attackTarget(PlayerCharacter* attacker,
//                   std::vector<PlayerCharacter*> targets)
// {
//     if (attacker->getHealth() <= 0) return; // attacker attacks the entity that's alive 
//     // get the attacker's name and display: 
//     std::cout << "\nIt is " << attacker->getName() << "'s turn!\n";
//     // performAction()
//     attacker->performAction(); // 
//     // Choose a target
//     std::cout << "\nChoose a target:\n";
//     // iterate through the targets
//     for (int i = 0; i < targets.size(); i++) {
//         if (targets[i]->getHealth() > 0) { // if health over 0
//             std::cout << i << " = " << targets[i]->getName() // display attacker's health
//                       << " Health: " << targets[i]->getHealth() << std::endl;
//         } 
//     }

//     int targetChoice; // when the player chooses the target, show the target anem
//     std::cout << "Target: ";
//     std::cin >> targetChoice;

//     while (targetChoice < 0 || // while target choise is valid
//            targetChoice >= targets.size() ||
//            targets[targetChoice]->getHealth() <= 0) {
//         std::cout << "Invalid target. Choose again: "; // error check
//         std::cin >> targetChoice;
//     }

//     int damage = 10; // deal the damage

//     int newHealth = targets[targetChoice]->getHealth() - damage;
//     if (newHealth < 0) newHealth = 0;

//     targets[targetChoice]->setHealth(newHealth);

//     std::cout << attacker->getName() << " dealt " // display how much damage was dealt to the target
//               << damage << " damage to "
//               << targets[targetChoice]->getName() << "!\n";
// }



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
