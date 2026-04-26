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
#include "AirBender.hpp"
#include "EarthBender.hpp"
#include "FireBender.hpp"
#include "WaterBender.hpp"

using namespace std;

// createCharacter: creates a playable characetr or enemy: 

PlayerCharacter* createCharacter(std::string label)
{
    std::string characterName;
    int bendingCode;
    // enter the name 
    std::cout << "\nEnter a name for " << label << ": ";
    std::cin.ignore();
    std::getline(std::cin, characterName);
    // CHOOSE A BENDING STYLE
    std::cout << "Enter a bending style for " << label
              << " (0 = Air, 1 = Earth, 2 = Fire, 3 = Water): ";
    std::cin >> bendingCode;
    // error check
    while (bendingCode < 0 || bendingCode > 3) {
        std::cout << "Invalid! Enter 0 = Air, 1 = Earth, 2 = Fire, 3 = Water: ";
        std::cin >> bendingCode;
    }
    // point to nullptr to remove temp data
    PlayerCharacter* character = nullptr;

    switch (bendingCode) {
        case 0: character = new AirBender(characterName, bendingCode); break;
        case 1: character = new EarthBender(characterName, bendingCode); break;
        case 2: character = new FireBender(characterName, bendingCode); break;
        case 3: character = new WaterBender(characterName, bendingCode); break;
    }

    cout << endl;
    character->printStats(); 
    cout << endl;
    character->greet(); 

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
    if (attacker->getHealth() <= 0) return; // If the attacker is already defeated, skip their turn
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

    while (targetChoice < 0 || // invalid check for target choice
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
    // --- Creat Player Characters and "Enemies" ---
    int numPlayers;
    int numEnemies;

    std::vector<PlayerCharacter*> players;
    std::vector<PlayerCharacter*> enemies;

    std::cout << "Enter the number of player characters: ";
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        // push_back is used to add the created character to the players vector, similar to push method
        players.push_back(createCharacter("Player " + std::to_string(i + 1))); 
        // createCharacter is called to create a new character and add it to the players vector
        // The label "Player X" is passed to createCharacter to identify each player during creation
    }

    std::cout << "Enter the number of enemy characters: ";
    std::cin >> numEnemies;

    for (int i = 0; i < numEnemies; i++) {
        enemies.push_back(createCharacter("Enemy " + std::to_string(i + 1))); 
    }

    char playAgain = 'y';
    // The loop continues as long as you want to play AND Bob is still standing
    while ((playAgain == 'y' || playAgain == 'Y')) {
        // Check if players or enemies are still alive
        if (!partyAlive(players)) {
            cout << "\nAll players have been defeated! Game Over." << endl;
            break;
        }
        if (!partyAlive(enemies)) {
            cout << "\nAll enemies have been defeated! You win!" << endl;
            break;
        }

        // Display health status of all characters
        displayHealth(players, enemies);

        // Players attack enemies
        for (PlayerCharacter* player : players) {
            attackTarget(player, enemies);
        }

        // Enemies attack players
        for (PlayerCharacter* enemy : enemies) {
            attackTarget(enemy, players);
        }

        // Ask if the user wants to play again
        cout << "\nDo you want to play another round? (y/n): ";
        cin >> playAgain;
    } 
    
    // Clean up
    for (PlayerCharacter* player : players) {
        delete player; // Free memory allocated for each player character
    }
    for (PlayerCharacter* enemy : enemies) {
        delete enemy; // Free memory allocated for each enemy character
    }
    return 0;
}
