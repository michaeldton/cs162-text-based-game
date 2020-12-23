/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Character class is an abstract class that serves as a base class. It handles many functions that may possibly be related to characters in the game. Intended to be expanded/adapted in the future - for example, enemies in this game do not use an inventory, but player character does. Future changes may add multiple playable characters; awaken() can be adapted to allow enemy fighters to buff stats mid-battle.
 ***************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "item.hpp"

class Character
{
	protected:
		Item** inventory;		// array containing Item pointers serving as character inventory

		std::string name;
		int maxHealth, health, atk, def, spd;	
		int inventorySize = 3;		// max inventory size is 3

	public:
		Character();
		virtual ~Character() = 0;
	
		void awaken();
		void rest(bool);
		void calcDamage(int);
		bool victory();

		void addItem(Item*);
		
		void displayInfo();
		void displayStats();

  		std::string getName();
		int getMaxHealth();
		void setHealth(int);
		int getHealth();
		int getAtk();
		int getDef();
		int getSpd();
};
#endif
