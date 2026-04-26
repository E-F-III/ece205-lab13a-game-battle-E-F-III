# Lab 12b - Game Character Class Part III (Polymorphism)
**ECE 205 - Spring 2026**  
**Author:** Edward Felipe III <efelipe3@hawaii.edu>

---

## Overview
This project extends the `PlayerCharacter` base class using polymorphism. Four profession subclasses have been implemented, each overriding `performAction()` to provide unique character behaviors based on their profession.

---

## Class Hierarchy

```
GameCharacter
└── PlayerCharacter
    ├── Bard
    ├── Rogue
    ├── Paladin
    └── Sorcerer
```

---

## Subclass Descriptions

### Bard
Bards are charismatic performers who use inspiration and illusions to support allies and confuse enemies.

| Member | Type | Description |
|---|---|---|
| `inspirationUses` | `int` | Number of inspiration uses remaining before rest |
| `minorIllusion()` | method | Creates a weak illusion to distract an enemy |
| `viciousMockery()` | method | Insults an enemy, potentially causing self-damage and disadvantage on their next attack |
| `encore()` | method | Repeats the most recent spell with increased strength, costs 1 inspiration use |

---

### Rogue
Rogues are cunning thieves who rely on stealth to ambush enemies, disguise themselves, and bypass locks.

| Member | Type | Description |
|---|---|---|
| `stealth` | `int` | Efficiency at performing attacks without being caught |
| `sneakAttack()` | method | Deals 2x damage if the Rogue's stealth is high enough to remain hidden |
| `disguiseSelf()` | method | Wears a disguise to temporarily increase stealth stat |
| `pickLock()` | method | Attempts to unlock a locked item without a key |

---

### Paladin
Paladins are holy warriors whose divine aura strengthens nearby allies and empowers their attacks.

| Member | Type | Description |
|---|---|---|
| `auraStrength` | `int` | Increases nearby allies' defensive stats and scales ability power |
| `layOnHands()` | method | Heals an ally; heal amount scales with auraStrength |
| `smite()` | method | Deals holy damage to an enemy; damage scales with auraStrength |

---

### Sorcerer
Sorcerers channel raw magical energy through sorcery points to cast devastating spells and enhance their magic.

| Member | Type | Description |
|---|---|---|
| `sorceryPoints` | `int` | Required resource consumed when performing spells |
| `fireball()` | method | Hurls a ball of fire at an enemy; costs 2 sorcery points |
| `metaMagic()` | method | Consumes 1 sorcery point to empower the next spell with a damage bonus |

---

## How to Build and Run

### Requirements
- g++ with C++17 support
- make

### Build
```bash
make
```

### Run
```bash
./lab12b
```

### Clean
```bash
make clean
```

---

## Sample Interaction

```
Enter a name for your character: Bob
Enter a race for your character (0 = Human, 1 = Fishman, 2 = Giant, 3 = Dwarf): 0
Enter a profession (0 = Bard, 1 = Rogue, 2 = Paladin, 3 = Sorcerer): 3

----------Stats for Bob----------
Name: Bob
Race: human
Health: 100
Strength: 7
Agility: 4
Defense: 6
------------------------------------
Profession: Sorcerer
Sorcery Points: 8
------------------------------------

Bob the Sorcerer: I am Bob. Magic flows through my veins — step aside.

Game Master: What would you like Bob to do?
(0 = Fireball, 1 = Meta Magic): 0

Bob hurls a blazing fireball at the enemy!
You need to roll at least a 5 to hit.
You rolled a 9. Boom! The fireball connects for 11 fire damage!
Sorcery points remaining: 6

Would you like to perform another action? (y/n): n

Farewell, Bob! Until next time.
```
