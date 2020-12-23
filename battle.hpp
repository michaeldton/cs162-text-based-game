/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Header file for Battle class. Battle is derived from Space and contains functions that handle the combat system.
 ***************************************************/

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "space.hpp"
#include "character.hpp"
#include "player.hpp"
#include "fallen.hpp"
#include "menu.hpp"

class Battle : public Space
{
	private:
		Fallen* enemy = nullptr;		// Battle contains a pointer to an enemy
		Menu menu;
		Menu help;
		Menu combatHelp;
		Menu combatMenu;

		bool enemyAlive = true;			// boolean tracks if enemy has been defeated already

	public:
		Battle(Fallen*);
		
		void action(Character*);
		void fight(Character*, Character*);
		bool playerTurn(Character*);
		void combat(Character*);
		void checkEnemy(Character*);
};
#endif
