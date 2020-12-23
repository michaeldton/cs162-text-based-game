/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file for Free.
 ***************************************************/

#include "free.hpp"
#include "utility.hpp"
#include <iostream>

Free::Free() : Space()				// constructor initializes menu and Space type
{
	type = FREE;
	
	menu.addString("\nWhat will Elena do?");
	menu.addString("1. Perform Awakening");
	menu.addString("2. Rest");
	menu.addString("3. Move");
	menu.addString("4. Help/Explanation");

	help.addString("HELP/EXPLANATION");
	help.addString("- Elena is on a \"free\" space where there are no hostile threats or other events occuring.");
	help.addString("- Here Elena may \"awaken\", rest, or continue forward.");
	help.addString("- Awakening will increase two stats randomly, and Elena will need to rest afterwards. This rest is lore-based, and will not affect turn count.");
	help.addString("- Resting will heal Elena for a small amount. The mandatory rest after performing an awakening will not restore any health.");
	help.addString("- Elena may opt choose to do neither, and move on to another room.");
}

void Free::action(Character* hero)		// initiates event for player to increase their stats, heal, move on, or ask for help/explanation, calling functions from Character as needed
{
	bool done = false;
	bool recover = false;

	std::cout << "Elena enters the room slowly through the open doorway, observing her surroundings.  The room is quiet and empty - a rare moment of peace." << std::endl
		  << "Recognizing this, she sighs in relief. Time moves constantly, but perhaps a few minutes can be spared for a brief respite." << std::endl;

	do	
	{
		menu.display();
		std::cout << "Enter your decision: ";
		int choice = getInteger(1, 4);
		std::cout << std::endl;
		
		switch(choice)
		{
			case 1:			// user decides to increase stats
				std::cout << "She breathes in deeply, as if searching for a sign of life in this grim atmosphere. Closing her eyes and clearing her mind, Elena links with the power of the Goddess Faem." << std::endl
				<< "Though her battle-worn body feels faint, she opens her eyes as she feels a pulse of energy within her. Elena has channeled the essence of Faem, strengthening her abilities.\n" << std::endl;
				
				hero->awaken();
				std::cout << "\nElena feels a bit weak from the process, taking some time to gather her energy." << std::endl	
					  << "Eventually, she prepares to move onward, her face reflecting a sense of newly discovered power." << std::endl;

				recover = false;	// player will not heal from rest; this rest is lore-related
				hero->rest(recover);
				std::cout << std::endl;
				
				done = true;
				break;
			case 2:			// user decides to rest
				std::cout << "She leans gently against the wall of the room before slowly sinking to the ground.  The area is reminiscent of the ruined state of her kingdom." << std::endl
				<< "She remains still in her place.  Perhaps she is remembering her friends and the moments they shared; perhaps she is haunted and broken by their deaths." << std::endl
				<< "After some time, Elena rises with renewed determination.\n" << std::endl;

				recover = true;		// player will heal from rest
				hero->rest(recover);
				std::cout << std::endl;

				done = true;
				break;
			case 3:			// user decides to just move on
				std::cout << "\"Father Time waits for no one\", she reminds herself. Elena presses onward, keeping her task in mind.\n" << std::endl;

				done = true;
				break;
			case 4: 		// user decides to see help menu
				help.display();
				break;
		}

	} while(!done);
}
