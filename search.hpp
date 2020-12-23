/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 12/1/18
 * Description: Header file for Search. Search is derived from Space, and only one exists in the game.  It contains an item needed for victory.  Upon first entry into this space, player acquires the item. This class was originally intended to be used to allow player to search for items, but for this project, will be used as the singular location to obtain a story item.
 ***************************************************/

#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "space.hpp"
#include "character.hpp"
#include "menu.hpp"
#include "item.hpp"

class Search : public Space
{
	private:
		Menu artifact;		// menu displayed if player has not been to this location before
		Menu noArtifact;	// menu displayed if location already visited
	
		Item* brace;

	public:
		Search();
		~Search();	
	
		void action(Character*);
};
#endif
