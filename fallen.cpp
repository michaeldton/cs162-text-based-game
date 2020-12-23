/***************************************************
 * Program: Final Project - CS162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/27/18
 * Description: Implementation file for Fallen.
 ***************************************************/

#include "fallen.hpp"

#include <iostream>

Fallen::Fallen(int maxHealth, int atk, int def, int spd, bool hasItem) : Character()	// constructor initializes stats and if Fallen has an item
{
	name = "Fallen Warrior";
	this->maxHealth = maxHealth;
	health = maxHealth;
	this->atk = atk;
	this->def = def;
	this->spd = spd;
	this->hasItem = hasItem;

	if(hasItem)	// if hasItem is true, initialize loot carried to FRAGMENT
	{
		loot = new Item(FRAGMENT);	
	}
}

Fallen::~Fallen()	// deallocates item if not obtained by player by end of game
{
	if(loot != nullptr)
	{
		delete loot;
		loot = nullptr;
	}
}

void Fallen::setItemStatus(bool status)
{
	hasItem = status;
}

bool Fallen::getItemStatus()
{
	return hasItem;
}

void Fallen::dropLoot(Character* hero)	// function called upon defeat to place loot into player inventory
{
	hero->addItem(loot);
	loot = nullptr;
	setItemStatus(false);
}
