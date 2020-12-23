/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 12/1/18
 * Description:	Implementation file for Search.
 ***************************************************/

#include "search.hpp"
#include "item.hpp"

#include <iostream>

Search::Search()		// constructor intiializes item, type, and dialogue displayed depending on if player has been here before or not
{
	type = SEARCH;
	brace = new Item(BRACE);

	artifact.addString("Elena arrives in the Queen's quarters. Looking at it now, it hardly seems like a royal's quarters. As she had been told, there was small redwood box resting on a table, untouched. Elena opens it, finding the brace. It appears timeless, untouched and unfazed by today's reality. ");
	artifact.addString("She places the brace around her wrist, feeling a sense of hope within her.");
	artifact.addString("\"...I can do this.\"");
	
	noArtifact.addString("Elena makes her way back to the Queen's quarters,  where she had found the brace.");
	noArtifact.addString("Though surely once an elegantly decorated area, it is destroyed. The tapestries and paintings are torn and ripped, and remnants of furniture collect dust.");
	noArtifact.addString("There is nothing to do here. \"I should keep moving,\" Elena tells herself. She moves onward.");
}

Search::~Search()		// constructor ensures Item pointer is deallocated if player never visited to acquire item before game ends
{
	if(brace != nullptr && !discovered)
	{
		delete brace;
		brace = nullptr;
	}
}

void Search::action(Character* hero)	// display appropriate dialogue/text based on status of space
{
	if(!discovered)			// if unvisited
	{
		artifact.display();
		hero->addItem(brace);	// add item to player inventory

		discovered = true;	// set discovered boolean value to true

		std::cout << std::endl;
	}	
	else				// if already visited
	{
		noArtifact.display();
		std::cout << std::endl;
	}
}
