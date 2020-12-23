/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Header file for Free class. Free is derived from Space, and represents a location the player can heal or train to increase their stats.
 ***************************************************/

#ifndef FREE_HPP
#define FREE_HPP

#include "space.hpp"
#include "player.hpp"
#include "menu.hpp"

class Free : public Space
{
	private:
		Menu menu;			// general menu
		Menu help;			// help menu

	public:
		Free();

		void action(Character*);
};
#endif
