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

// createCharacter: creates a playable characetr or enemy: 

PlayerCharacter* createCharacter(std::string label)
{
    std::string characterName;
    int characterRace;
    int characterBendingStyle;
    // enter the name 
    std::cout << "\nEnter a name for " << label << ": ";
    std::cin.ignore();
    std::getline(std::cin, characterName);
    // WE ARE REMOVING THE FISHMANS, GIANT, DWARF @TODO REMOVE THIS 
    std::cout << "Enter a race for " << label
              << " (0 = Human, 1 = Fishman, 2 = Giant, 3 = Dwarf): ";
    std::cin >> characterRace;
    // CHOOSE A BENDING STYLE
    std::cout << "Enter a bending style for " << label
              << " (0 = Air, 1 = Earth, 2 = Fire, 3 = Water): ";
    std::cin >> characterBendingStyle;
    // error check
    while (characterBendingStyle < 0 || characterBendingStyle > 3) {
        std::cout << "Invalid! Enter 0 = Air, 1 = Earth, 2 = Fire, 3 = Water: ";
        std::cin >> characterBendingStyle;
    }
    // point to nullptr to remove temp data
    PlayerCharacter* character = nullptr;

    switch (characterBendingStyle) {
        case 0: character = new AirBender(characterName, characterRace); break;
        case 1: character = new EarthBender(characterName, characterRace); break;
        case 2: character = new FireBender(characterName, characterRace); break;
        case 3: character = new WaterBender(characterName, characterRace); break;
    }

    return character;
}




// partyAlive: checks health for the party
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

void displayHealth(std::vector<PlayerCharacter*> players,
                   std::vector<PlayerCharacter*> enemies) 
{
    std::cout << "\n========== HEALTH STATUS ==========" << std::endl;

    std::cout << "Players:\n";
    for (PlayerCharacter* p : players) { //iterate through players
        std::cout << p->getName()
                  << " Health: " << p->getHealth() << std::endl;
    }

    std::cout << "\nEnemies:\n";
    for (PlayerCharacter* e : enemies) { //iterate through enemies 
        std::cout << e->getName()
                  << " Health: " << e->getHealth() << std::endl;
    }

    std::cout << "===================================" << std::endl;
}


// void attackTarget: attacks the player

void attackTarget(PlayerCharacter* attacker,
                  std::vector<PlayerCharacter*> targets)
{
    if (attacker->getHealth() <= 0) return; // attacker attacks the entity that's alive 
    // get the attacker's name and display: 
    std::cout << "\nIt is " << attacker->getName() << "'s turn!\n";
    // performAction()
    attacker->performAction(); // 
    // Choose a target
    std::cout << "\nChoose a target:\n";
    // iterate through the targets
    for (int i = 0; i < targets.size(); i++) {
        if (targets[i]->getHealth() > 0) { // if health over 0
            std::cout << i << " = " << targets[i]->getName() // display attacker's health
                      << " Health: " << targets[i]->getHealth() << std::endl;
        } 
    }

    int targetChoice; // when the player chooses the target, show the target anem
    std::cout << "Target: ";
    std::cin >> targetChoice;

    while (targetChoice < 0 || // while target choise is valid
           targetChoice >= targets.size() ||
           targets[targetChoice]->getHealth() <= 0) {
        std::cout << "Invalid target. Choose again: "; // error check
        std::cin >> targetChoice;
    }

    int damage = 10; // deal the damage

    int newHealth = targets[targetChoice]->getHealth() - damage;
    if (newHealth < 0) newHealth = 0;

    targets[targetChoice]->setHealth(newHealth);

    std::cout << attacker->getName() << " dealt " // display how much damage was dealt to the target
              << damage << " damage to "
              << targets[targetChoice]->getName() << "!\n";
}



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

