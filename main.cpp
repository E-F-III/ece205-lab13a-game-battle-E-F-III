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

#include <ctime>  // Added for srand
#include <thread> // Added for sleep_for
#include <chrono> // Added for chrono literals

#include "FighterCharacter.hpp"

#include "PlayerCharacter.hpp"
#include "AirBender.hpp"
#include "EarthBender.hpp"
#include "FireBender.hpp"
#include "WaterBender.hpp"

// INCLUDE NPC HEADER FILES: (ignore red lines)

#include "NPCharacter.hpp"
#include "NPCAirBender.hpp"
#include "NPCEarthBender.hpp"
#include "NPCFireBender.hpp"
#include "NPCWaterBender.hpp"

using namespace std;

// -- helper functions --

// createCharacter: were going to create a character

PlayerCharacter *createCharacter(string label)
{
    string characterName;
    int bendingCode; // bring code for Bending

    cout << "\nEnter a name for " << label << ": "; // user enters name for their character
    cin.ignore(1000, '\n');                         // Clear buffer properly
    getline(cin, characterName);                    // sprint name

    cout << "Enter a bending style (0=Air, 1=Earth, 2=Fire, 3=Water): "; // user chooses  a bending style
    while (!(cin >> bendingCode) || bendingCode < 0 || bendingCode > 3)
    { // error check
        cout << "Invalid! Enter 0-3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    PlayerCharacter *character = nullptr; // point to null value to erase cache
    switch (bendingCode)
    {
    case 0:
        character = new AirBender(characterName, bendingCode);
        break; // AIRBENDER
    case 1:
        character = new EarthBender(characterName, bendingCode);
        break; // EARTHBENDER
    case 2:
        character = new FireBender(characterName, bendingCode);
        break; // FIREBENDER
    case 3:
        character = new WaterBender(characterName, bendingCode);
        break; // WATERBENDER
    }
    // .... printStats and Greet()
    if (character)
    {
        character->printStats();
        character->greet();
    }
    return character;
}

// NPC implementation; create a NPC, max 4 types

NPCharacter *createNPC(string label)
{
    int bendingCode = rand() % 4;
    NPCharacter *character = nullptr;

    switch (bendingCode)
    {
    case 0:
        character = new NPCAirBender(label, bendingCode);
        break;
    case 1:
        character = new NPCEarthBender(label, bendingCode);
        break;
    case 2:
        character = new NPCFireBender(label, bendingCode);
        break;
    case 3:
        character = new NPCWaterBender(label, bendingCode);
        break;
    }
    return character;
}

// partyAlive: checks health for the party @TODO EFiii, check this please
bool partyAlive(const vector<FighterCharacter *> &party)
{
    for (FighterCharacter *character : party)
    {
        if (character->getHealth() > 0)
        {                // if char is alive
            return true; // we are good
        }
    }
    return false;
}

// void displayHealth: shows each players health

void displayHealth(const vector<FighterCharacter *> &players, const vector<FighterCharacter *> &enemies)
{
    cout << "\n========== HEALTH STATUS ==========\n";
    cout << "Players:\n";
    for (auto p : players)
        cout << " - " << p->getName() << "(Health): " << p->getHealth() << "\n";
    cout << "\nEnemies:\n";
    for (auto e : enemies)
        cout << " - " << e->getName() << "(Health): " << e->getHealth() << "\n";
    cout << "===================================\n";
}

// Unified attack logic using the base class FighterCharacter
void performTurn(FighterCharacter *attacker, vector<FighterCharacter *> &allies, vector<FighterCharacter *> &enemies, bool isNPC)
{
    if (attacker->getHealth() <= 0)
        return;

    cout << "\n>> " << attacker->getName() << "'s turn!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Small pause for better readability

    if (isNPC)
    {
        // Randomized target selection can be implemented here for more variety
        // Ensure we select a valid target (alive enemy)
        int random_target_idx = rand() % enemies.size();
        // Keep picking until we find a valid target
        while (enemies[random_target_idx]->getHealth() <= 0)
        {
            random_target_idx = rand() % enemies.size();
        }

        attacker->performAction(*attacker, *enemies[random_target_idx]);
    }
    else
    {
        // Player Manual Choice
        int partyIdx;
        int targetIdx;

        // Ask player to choose between attacking an enemy or an ally (for potential support actions in the future)
        cout << "Choose a target type: 0=Enemy, 1=Ally: ";
        while (!(cin >> partyIdx) || (partyIdx != 0 && partyIdx != 1))
        {
            cout << "Invalid! Enter 0 or 1: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (partyIdx)
        {
        case 0:
            cout << "Choose an enemy to attack:\n";
            for (size_t i = 0; i < enemies.size(); i++)
            {
                cout << i << ": " << enemies[i]->getName() << " (Health: " << enemies[i]->getHealth() << ")\n";
            }
            while (!(cin >> targetIdx) || targetIdx < 0 || targetIdx >= static_cast<int>(enemies.size()) || enemies[targetIdx]->getHealth() <= 0)
            {
                cout << "Invalid! Enter a valid enemy index: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            attacker->performAction(*attacker, *enemies[targetIdx]);
            break;
        case 1:
            cout << "Choose an ally to support (not implemented yet, so this will just skip the turn):\n";
            for (size_t i = 0; i < allies.size(); i++)
            {
                cout << i << ": " << allies[i]->getName() << " (Health: " << allies[i]->getHealth() << ")\n";
            }
            while (!(cin >> targetIdx) || targetIdx < 0 || targetIdx >= static_cast<int>(allies.size()) || allies[targetIdx]->getHealth() <= 0)
            {
                cout << "Invalid! Enter a valid ally index: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            // Future support action logic can be implemented here
            cout << "Support actions not implemented yet. Turn skipped.\n";
            break;
        }
    }
}

int main()
{
    srand(time(NULL)); // Seed random
    // --- Creat Player Characters and "Enemies" ---
    int numPlayers;
    int numEnemies;

    vector<FighterCharacter *> players;
    vector<FighterCharacter *> enemies;

    cout << "Enter the number of player characters (Max 4): ";
    cin >> numPlayers;

    while (!(cin >> numPlayers) || numPlayers < 1 || numPlayers > 4)
    {
        cout << "Invalid! Enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    for (int i = 0; i < numPlayers; i++)
    {
        // push_back is used to add the created character to the players vector, similar to push method
        players.push_back(createCharacter("Player " + to_string(i + 1)));
        // createCharacter is called to create a new character and add it to the players vector
        // The label "Player X" is passed to createCharacter to identify each player during creation
    }

    cout << "Enter the number of enemy characters (Max 4): ";
    cin >> numEnemies;

    while (!(cin >> numEnemies) || numEnemies < 1 || numEnemies > 4)
    {
        cout << "Invalid! Enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    for (int i = 0; i < numEnemies; i++)
    {
        enemies.push_back(createCharacter("Enemy " + to_string(i + 1)));
    }

    for (int i = 0; i < numEnemies; i++)
    {
        enemies.push_back(createCharacter("Enemy " + to_string(i + 1)));
    }

    while (partyAlive(players) && partyAlive(enemies)) {
        displayHealth(players, enemies);

        for (auto p : players) performTurn(p, players, enemies, false);
        for (auto e : enemies) performTurn(e, enemies, players, true);
    }

    if (partyAlive(players)) cout << "\nVICTORY!\n"; else cout << "\nDEFEAT!\n";

    // Clean up memory
    for (auto p : players) delete p;
    for (auto e : enemies) delete e;

    return 0;
}
