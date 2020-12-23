/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 12/1/18
 * Description: Implementation file for Item class.
 ***************************************************/

#include "item.hpp"

Item::Item(ItemType type)	// constructor takes in ItemType and determines name based on it; Item class is only used for two types of story-related items, thus constructor only serves to initialize their names
{
	this->type = type;
	
	switch(type)
	{
		case FRAGMENT:		// FRAGMENT items are named 'Eternum Fragment'
			itemName = "Eternum Fragment";
			break;
		case BRACE:		// BRACE items are named 'Faem's Royal Brace'
			itemName = "Faem's Royal Brace";
			break;
	}
}

std::string Item::getItemName()	// return name of item
{
	return itemName;
}

