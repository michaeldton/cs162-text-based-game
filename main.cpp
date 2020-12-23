/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Main file for 'Till the End of Time. Initializes Game class and runs game after explaining backstory and basic instructions to user.
 ***************************************************/

#include "game.hpp"
#include "menu.hpp"
#include <ctime>
#include <stdlib.h>


int main()
{
	srand(std::time(NULL));		
	Menu intro;			// Menu class used to display intro text

	intro.addString("\nWelcome to my game, \'Till the End of Time\'.\n\nIn this game you control Elena, a young woman who has served as part of the royal guard for the Kingdom of Kjol, which worships the Goddess Faem.");
	intro.addString("By the beginning of the game, Kjol has long since been reduced to ruin after the return of the demon Forstosis, who has spread his chaos to other lands. ");
	intro.addString("Forstosis aims to re-shape the world in the name of the Void. Elena, a few remnants of Kjol's royal guard, and many others have battled endlessly with no success.");
	intro.addString("Elena has lost her spirit - many of her loved ones have either fallen in combat. Many others live in fear in areas controlled by the Void.");
	intro.addString("The Goddess Faem speaks to Elena to show a way to stop Forstosis: she must go to a sector of Kjol's castle overrun by Forstosis' army and reclaim the Eternum gemstone fragments and the Royal Brace.");
	intro.addString("With these artifacts, and Faem's sword Inero, she can rewind time and attempt to find a way to stop Forstosis before he arrives.");
	intro.addString("Faem warps Elena directly to Kjol's castle with Inero. Her power provides a great but limited opportunity: Inero will disappear after some time, and without it, Elena cannot succeed..");
	intro.addString("\nHOW TO PLAY:\n\'#\' represents Elena's position. There are nine rooms, three marked by \'B\' which will initiate an enemy encounter if they have not already been defeated.");
	intro.addString("Rooms with no marking are \'free\' rooms, where Elena can rest, use Faem's blessing, or continue moving. \'S\' represents the location of the brace. Two of the enemies will drop fragments upon defeat.");
	intro.addString("If she collects all three parts, the player is victorious.  If Elena hasn't by the end of Turn 15, or if Elena falls in battle at any point, it is game over.\n");  

	intro.display();

	Game game(3, 3, 15);		// initialize Game
	game.run();			// run game

	return 0;
}
