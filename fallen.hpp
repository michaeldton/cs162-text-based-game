/***************************************************
 * Program: Final Project - CS162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/27/18
 * Description: Header file for Fallen class, derived from Character. Represents the enemy in the game. Potentially contains story-related items, and contains functions to check item status and give loot to player upon defeat.
 ***************************************************/

#ifndef FALLEN_HPP
#define FALLEN_HPP

#include "character.hpp"
#include "item.hpp"

class Fallen : public Character
{
	private:
		bool hasItem = false;
		Item* loot = nullptr;
		
	public:
		Fallen(int, int, int, int, bool);
		~Fallen();

		void setItemStatus(bool);
		bool getItemStatus();
		void dropLoot(Character*);

};
#endif
