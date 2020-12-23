/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file for Battle.
 ***************************************************/

#include "battle.hpp"
#include "utility.hpp"

#include <iostream>

Battle::Battle(Fallen* fallen) : Space()		// constructor intializes type, enemy passed as parameter, and relevant menus
{
	type = BATTLE;
	enemy = fallen;	

	menu.addString("\nWhat will Elena do?");
	menu.addString("1. Engage");
	menu.addString("2. Avoid");
	menu.addString("3. General Help/Explanation");
	menu.addString("4. Combat Help/Explanation");

	help.addString("GENERAL HELP/EXPLANATION");
	help.addString("- Elena has encountered a Fallen, the re-animated corpse of a warrior. She may either engage in battle or avoid fight.");
	help.addString("- If Elena engages the enemy, fight will begin.");
	help.addString("- If Elena chooses to avoid the encounter, she will leave the event and be able to move to another room.");

	combatHelp.addString("COMBAT EXPLANATION");
	combatHelp.addString("- Combat is turn-based. The character with higher SPD will go first. If both SPD stats are equal, Elena goes first.");
	combatHelp.addString("- Elena can fight or escape.");
	combatHelp.addString("- Damage inflicted is the difference between the attacker's ATK and the defender's DEF.  If a character's SPD is higher by at least 3, they will attack twice.");
	combatHelp.addString("- If Elena runs from fight, she will escape and begin her next turn on the map as normal without a turn penalty. She cannot flee unless her SPD is higher by at least 3. If it is not, the attempt will fail.\nAn enemy will be fully healed if Elena escapes a battle and returns to fight again.");
	combatHelp.addString("- Before each attack, the current health of each character will be displayed.");

	combatMenu.addString("\nWhat will Elena do?");
	combatMenu.addString("1. Attack");
	combatMenu.addString("2. Run");
}


void Battle::action(Character* hero)			// initiates combat event where player can choose to engage in battle or avoid the enemy
{
	if(enemyAlive)					// if enemy has not been defeated
	{
		bool done = false;
	
		std::cout << "Enemy spotted!\n" << std::endl;
		enemy->displayStats();			// display enemy statistics to player before they make decision

		do	
		{
			menu.display();
			std::cout << "Enter your decision: ";
			int choice = getInteger(1, 4);
			std::cout << std::endl;
		
			switch(choice)
			{
				case 1:			// begin combat
					combat(hero);	
					done = true;
					break;	
				case 2:			// avoid encounter
					std::cout << "Elena opts to not fight this time, and heads towards another room." << std::endl;
					done = true;				
					break;
				case 3:			// get general help menu
					help.display();
					break;
				case 4:			// get combat help menu
					combatHelp.display();
					break;
			}
		} while	(!done);
	}
	else						// if player has already won this battle encounter
	{
		std::cout << hero->getName() << " enters a familiar room, noting the scent of battle and the lifeless corpse laying in the vicinity.\n"
			  << "There is nothing else of interest, and the area is not suitable for " << hero->getName() << " to rest or perform an awakening.\n"
			  << "\"Nothing to do but keep going, I guess\", " << hero->getName() << " whispers.\n" << std::endl;
	}
}

void Battle::fight(Character* attacker, Character* defender)		// function calculates damage of attacker and inflicts it upon defender health
{
	int atk = attacker->getAtk();
	int def = defender->getDef();
	int atkSpd = attacker->getSpd();
	int defSpd = defender->getSpd();
	bool doubleAtk = false;

	int dmg = atk - def;

	if(atkSpd >= defSpd+3)				// check speeds to determine if attacker hits twice
	{
		doubleAtk = true;
	}

	if(dmg < 0)					// prevent healing if def is higher than atk	
	{
		dmg = 0;
	}

	std::cout << std::endl; 

	if(doubleAtk)					// doubles damage if attacker was fast enough, displaying message
	{
		dmg *= 2;
		std::cout << attacker->getName() << " attacks twice for " << dmg << " total damage.\n" << std::endl;
	}
	else						// display normal attack mesage
	{
		std::cout << attacker->getName() << " attacks for " << dmg << " damage.\n" << std::endl;
	}

	defender->calcDamage(dmg);			// apply damage to defender
}

bool Battle::playerTurn(Character* hero)		// function runs a menu on player's turn for combat
{
	bool canEscape = false;
	bool escape = false;
	int heroSpd = hero->getSpd();
	int enemySpd = enemy->getSpd();

	if(heroSpd+3 > enemySpd)			// player can escape if fast enough
	{
		canEscape = true;
	}

	combatMenu.display();
	std::cout << "Enter your decision: ";
	int choice = getInteger(1, 2);
		
	switch(choice)
	{
		case 1:					// player attacks
			fight(hero, enemy);
			break;
		case 2:					// player attempts to run
			if(canEscape)
			{
				std::cout << "Successfully escaped." << std::endl;
				escape = true;
			}
			else
			{
				std::cout << "Cannot escape." << std::endl;
			}
			break;
	}

	return escape;					// return boolean value of escape attempt
}

void Battle::combat(Character* hero)			// runs combat, allowing combat until a character dies or the player chooses to escape
{
	int heroSpd = hero->getSpd();
	int enemySpd = enemy->getSpd();
	int attacker;
	bool escape = false;

	// conditions check to see who attacks first; if player spd >= enemy spd, player goes first
	if(heroSpd >= enemySpd)
	{
		attacker = 1;
	}
	else
	{
		attacker = 2;
	}

	do					// displays HP of both characters to player before each attack/character turn
	{
		std::cout << hero->getName() << ": " << hero->getHealth() << "/" << hero->getMaxHealth() << std::endl
			  << enemy->getName() << ": " << enemy->getHealth() << "/" << enemy->getMaxHealth() << std::endl;

		if(attacker == 1)		// if player attacks first
		{
			escape = playerTurn(hero);
			attacker++;		// increment attacker variable so enemy goes next
		}
		else if(attacker == 2)		// if enemy attacks first
		{
			fight(enemy, hero);	
			attacker--;		// decrement attacker variable so player goes next
		}
	} while(hero->getHealth() > 0 && enemy->getHealth() > 0 && !escape);		// run loop until one dies, or player escapes

	if(escape)				// reset enemy health to full if player chose to run from battle
	{
		enemy->setHealth(enemy->getMaxHealth());
	}

	if(hero->getHealth() <= 0)		// display if player died
	{
		std::cout << hero->getName() << " has died!\n" << std::endl;
	}

	checkEnemy(hero);			// function call to display if enemy died, and if they did, if they dropped any loot
}

void Battle::checkEnemy(Character* hero)	// function displays enemy death and loot
{
	if(enemy->getHealth() <= 0)		// only displays if enemy has no HP after combat
	{
		std::cout << enemy->getName() << " has been defeated.\n" << std::endl;
	
		if(enemy->getItemStatus())	// if enemy holds an item, display to user
		{
			std::cout << "It dropped an Eternum Fragment! Elena places it in her backpack with a look a satisfaction.\n" << std::endl;
			enemy->dropLoot(hero);	// add item to player inventory
		}
		else				// display if enemy has no item
		{
			std::cout << "It didn't drop anything...\n" << std::endl;
		}

		enemyAlive = false;		// "remove" enemy from space
	}
}
