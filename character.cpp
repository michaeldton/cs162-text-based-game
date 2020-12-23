/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file for Character
 ***************************************************/

#include "character.hpp"

#include <iostream>
#include <string>

Character::Character()			// construtor initializes inventory to nullptr
{
	inventory = new Item*[inventorySize];

	for(int i = 0; i < inventorySize; i++)
	{
		inventory[i] = nullptr;
	}
}
		
Character::~Character()			// destructor deallocate memory used for inventory
{
	for(int i = 0; i < inventorySize; i++)
	{
		if(inventory[i] != nullptr)
		{
			delete inventory[i];
		}
	}

	delete[] inventory;
	inventory = nullptr;
}

void Character::awaken()		// character 'awakens', increasing their stats (similar to training mechanic)
{
	int statsUp = 0;		// variable tracks number of stat increases

	while(statsUp < 2)		// each 'awaken' increases two random stats; can be the same stat
	{	
		int stat = rand() % 4 + 1;

		switch(stat)
		{
			case 1: 	// increase max HP by 3; heals 3 HP accordingly
				maxHealth += 3;
				health += 3;
				std::cout << name << "'s max HP has increased to " << maxHealth << "." << std::endl;
				break;
			case 2:		// increase atk by 1
				atk++;
				std::cout << name << "'s attack has increased to " << atk << "." << std::endl;
				break;
			case 3:		// increase def by 1
				def++;
				std::cout << name << "'s defense has increased to " << def << "." << std::endl;
				break;
			case 4:		// increase spd by 1
				spd++;
				std::cout << name << "'s speed has increased to " << spd << "." << std::endl;
				break;
		}
	
		stat = rand() % 4 + 1;	// ensure stat chosen is re-randomized
		statsUp++;		// increment tracker variable
	}	
		
	std::cout << std::endl;
	displayStats();			// display current stats to user post-increase
}

void Character::rest(bool recover)	// recovers character HP by 2
{
	if(recover)
	{
		health += 2;
		
		if(health > maxHealth)	// ensure current health does not exceed maximum HP
		{
			health = maxHealth;
		}	

		std::cout << name << " recovers 2 HP from resting.\n" << std::endl;
		displayStats();
	}
}

void Character::calcDamage(int dmg)	// takes in parameter for damage and applies to character health; ensures health does not drop below 0
{
	health -= dmg;
	
	if(health < 0)
	{
		health = 0;
	}
}

bool Character::victory()		// returns boolean value to track if user has acquired all items for victory; only useful to this program because exactly three items exist in game
{
	int victoryIndex = 0;

	for(int i = 0; i < inventorySize; i++)		// loops checks through inventory, incrementing index if item is found
	{
		if(inventory[i] != nullptr)
		{
			victoryIndex++;
		}
	}

	if(victoryIndex >= 3)				// if three items were found, return true
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Character::addItem(Item* newItem)			// add item to next open space in inventory
{
	int position = 0;

	while(position < inventorySize)			// check if there is space to add an item
	{
		if(inventory[position] == nullptr)	// if an empty space is found, add item to inventory
		{
			inventory[position] = newItem;
			position = 100;			// set position outside of inventory size to ensure no duplicates placed in inventory by loop
		}
		else
		{
			position++;
		}
	}
}

void Character::displayInfo()				// display all info of character (inventory, stats)
{
	int numChars = 23;
	char borderDesign = '*';

	std::cout << std::string(numChars, borderDesign) 
		  << "\n* Name: " << name
		  << "\n* HP: " << health << "/" << maxHealth
		  << "\n* ATK: " << atk
		  << "\n* DEF: " << def
		  << "\n* SPD: " << spd
		  << "\n* Inventory: ";

	for(int i = 0; i < inventorySize; i++)
	{
		if(inventory[i] != nullptr)
		{
			std::cout << inventory[i]->getItemName();
			
			if(i < 2)			// print borders when listing items in one line if needed
			{
				std::cout << " | ";
			}
		}
	}

	std::cout << std::endl << std::string(numChars, borderDesign) << std::endl << std::endl;
}

void Character::displayStats()				// display stats
{
	int numChars = 23;
	char borderDesign = '*';

	std::cout << std::string(numChars, borderDesign) 
		  << "\n* Name: " << name
		  << "\n* HP: " << health << "/" << maxHealth
		  << "\n* ATK: " << atk
		  << "\n* DEF: " << def
		  << "\n* SPD: " << spd << std::endl
		  << std::string(numChars, borderDesign) << std::endl;
}

// ***************************************************
// * 	    Get Methods for Character class	     *
// ***************************************************

std::string Character::getName()
{
	return name;
}

int Character::getMaxHealth()
{
	return maxHealth;
}

void Character::setHealth(int newHealth)
{
	health = newHealth;
}
int Character::getHealth()
{
	return health;
}

int Character::getAtk()
{
	return atk;
}

int Character::getDef()
{
	return def;
}

int Character::getSpd()
{
	return spd;
}	
