/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file of Game class.
 ***************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "utility.hpp"

#include <iostream>
#include <string>

Game::Game(int rows, int cols, int turnLimit)		// constructor sets up game; Player character and three enemies are hard-coded
{
	this->rows = rows;
	this->cols = cols;
	this->turnLimit = turnLimit;

	hero = new Player("Elena", 14, 3, 1, 3);		
	fallen1 = new Fallen(10, 3, 4, 3, true);
	fallen2 = new Fallen(18, 5, 1, 2, false);
	fallen3 = new Fallen(16, 2, 2, 6, true);
	
	map = new Space**[rows];			// declare dynamic array

	for(int i = 0; i < rows; i++)			// loop initializes map based on rows x cols and initializes all Space objects to nullptr
	{
		map[i] = new Space*[cols];		

		for(int j = 0; j < cols; j++)
		{
			map[i][j] = nullptr; 
		}
	}
	
	// Establish "menu" for each type of win/loss condition to show to user upon satisfaction of a condition
	
	victoryScreen.addString("Upon collecting the final piece, Elena immediately prepares.\nHaving already put on Faem's Royal Brace, she places each fragment as best she can into the opening of the brace. Almost immediately, the fragments glow and become whole, restoring the Eternum gemstone.");
	victoryScreen.addString("The Inero begins to glow, as Faem had told her it would. Elena's hands begin shaking as if in disbelief, but she gathers herself quickly.");
	victoryScreen.addString("As light continues to surround her, tears begin to swell in Elena's blue eyes. \"I... I did it. I did it, everyone,\" she softly cries. She closes her eyes. Her mission is not over, but she has neer felt such bittersweet joy.");
	victoryScreen.addString("Before the light envelops her, Elena looks at peace. If one were to observe her in this moment, they would never recognize her sorrow, nor the struggles of a young woman who has lost it all.");
	victoryScreen.addString("\n\"I... will change my fate. Our fate.\"");
	victoryScreen.addString("\nCongratulations on your victory, player! Thank you for playing.");

	deathScreen.addString("With Elena slain in battle, all hope is lost. Fate maintains its course, and Father Time remains undefeated.");
	deathScreen.addString("\n GAME OVER");

	defeatScreen.addString("Elena feels a strange sensation in her hand. At first, she believes she is succumbing to her fatigue, but quickly realizes that the Inero is fading. The blade to change her destiny is leaving her.");
	defeatScreen.addString("\"No... NO! NOT YET!\", she shouts as she realizes her time has run out. Without Inero, she can no longer succeed. Fate has run its course - her destiny written in ink.");
	defeatScreen.addString("The blade is gone and Elena drops to her knees, slumping. Gone is her opportunity to save what she has lost.");
	defeatScreen.addString("\n\"I'm sorry...\"");
	defeatScreen.addString("\nGAME OVER");
}

Game::~Game()						// destructor deallocates all memory
{
	for(int i = 0; i < rows; i++)			// loop ensures proper deallocation and deletion of map	
	{
		for(int j = 0; j < cols; j++)
		{
			if(map[i][j] != nullptr)
			{
				delete map[i][j];
			}
		}
		delete[] map[i];
	}
	
	delete[] map;
	
	// deallocate all memory for player and enemies
	
	delete hero;				
	delete fallen1;
	delete fallen2;
	delete fallen3;
}

void Game::run()					// run() calls necessary functions to run the game, tracking player status towards conditions for win/loss
{
	int turnNum = 1;
	int numChar = 23;			
	char borderDesign = '*';
	std::string topFormat = "\t";
	std::string bottomFormat = "     ";

	createMap();
	setPlayer(rows - 1, 0);				// player always start in bottom left of map
	linkMap();

	while(turnNum <= turnLimit && !win && !death)	// while loop checks win/loss conditions
	{	
		std::cout << std::string(numChar, borderDesign) << std::endl
			  << topFormat << "TURN "  << turnNum << std::endl
			  << std::string(numChar, borderDesign) << std::endl;
	
		displayMap();
		getPlayerInfo();
		movePlayer();
		doEvent();
		linkMap();
		
		std::cout << std::string(numChar, borderDesign) << std::endl 
			  << bottomFormat << "END OF TURN " << turnNum << std::endl	
			  << std::string(numChar, borderDesign) << "\n" << std::endl;
	
		turnNum++;
	}

	// display screen at end of game according to win or type of loss
	
	if(win)
	{
		victoryScreen.display();
	}
	else if(death)
	{
		deathScreen.display();		
	}
	else
	{
		defeatScreen.display();
	}
}

void Game::createMap()					// creates map, place Space types
{
	int tempRow = rand() % rows;		
	int tempCol = rand() % cols;
	int numBattles = 3;				// number of enemy encounters possible on map
	int fallenNum = 1;				// index tracks which enemy to place

	map[1][1] = new Search();			// only one Search space in game, always placed in middle of 3x3 map

	while(numBattles > 0)				// loop randomly places enemy encounters on map
	{
		while(map[tempRow][tempCol] != nullptr)	
		{
			tempRow = rand() % rows;
			tempCol = rand() % cols;
		}

		if(numBattles > 0)
		{
			switch(fallenNum)		// place according enemy in randomly determined location
			{
				case 1: 
					map[tempRow][tempCol] = new Battle(fallen1);
					break;
				case 2:
					map[tempRow][tempCol] = new Battle(fallen2);
					break;
				case 3:
					map[tempRow][tempCol] = new Battle(fallen3);
					break;
			}

			numBattles--;
			fallenNum++;
		}
	}	

	for(int i = 0; i < rows; i++)			// initialize all remaining locations to Free
	{
		for(int j = 0; j < cols; j++)
		{
			if(map[i][j] == nullptr)
			{
				map[i][j] = new Free();
			}
		}
	}
}

void Game::linkMap()					// function re-initializes all pointers to surrounding spaces for each Space in map
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			if(i - 1 >= 0)			// link pointer to Space above
			{
				map[i][j]->link(TOP, map[i - 1][j]);
			}
			if(j - 1 >= 0)			// link pointer to Space to left
			{
				map[i][j]->link(LEFT, map[i][j - 1]);
			}	
			if(j + 1 < cols)		// link pointer to Space to right
			{
				map[i][j]->link(RIGHT, map[i][j + 1]);			
			}	
			if(i + 1 < rows)		// link pointer to Space below
			{
				map[i][j]->link(BOTTOM, map[i + 1][j]);			
			}
		}
	}
}

void Game::displayMap()					// display current map to player; each Space on the map is portrayed by a 3x3 cell
{
	std::string topEdge = " _ _ _ ";
	std::string sides = "|     |";
	std::string bottomEdge = "|_ _ _|";

	for(int i = 0; i < cols; i++)
	{
		std::cout << topEdge;
	}

	std::cout << std::endl;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)		// print side edges of top row of cell
		{
			std::cout << sides; 
		}
	
		std::cout << std::endl;

		for(int j = 0; j < cols; j++)		// print edges and contents of cell 
		{
			std::cout << "|  ";

			if(map[i][j] == nullptr)	// if Space is uninitialized leave blank (DEBUGGING STEP LEFT IN - does not affect final)
			{
				std::cout << " ";
			}
			else				// print character representing Space ype
			{
				std::cout << map[i][j]->getType();
			}

			std::cout << "  |";		// print outside edge of middle row of cell

			if(j == cols - 1)		// ensures proper display of right edges of cells
			{
				std::cout << std::endl;
			
				for(int j = 0; j < cols; j++)
				{
					std::cout << bottomEdge;
				}

				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl;
}

void Game::doEvent()					// calls event contained by Space at player location and updates win/loss conditions
{
	int playerRow = hero->getRow();
	int playerCol = hero->getCol();

	map[playerRow][playerCol]->action(hero);

	if(hero->getHealth() == 0)
	{
		death = true;
	}

	win = hero->victory();
}

void Game::getPlayerInfo()				// ask user if they want to display character's current stats/inventory
{	
	bool legal = false;

	std::cout << "Would you like to review " << hero->getName() << "'s current information?\n"
		  << "Y: Yes\n"
		  << "N: No" << std::endl;

	do
	{
		std::cout << "Enter your decision: ";
		char choice = getChar();
		std::cout << std::endl;

		switch(choice)
		{
			case 'Y':			// display all info
				hero->displayInfo();
				legal = true;
				break;
			case 'N':			// don't display
				legal = true;
				break;
			default:			// invalid input
				std::cout << "That is not a valid input. Try again." << std::endl;
				break;
		}
	} while(!legal);
}

void Game::setPlayer(int row, int col)			// sets player at a location
{
	hero->setCoordinates(row, col);
	map[row][col]->setOccupied(true);
}

void Game::movePlayer()					// moves player based user decision and ensures that they can move to the chosen location
{	
	int playerRow = hero->getRow();
	int playerCol = hero->getCol();
	bool northValid = false, westValid = false, eastValid = false, southValid = false, legal = false;

	Menu menu;
	menu.addString("Move in which direction?");
	menu.addString("N: North");
	menu.addString("W: West");
	menu.addString("E: East");
	menu.addString("S: South");
	menu.display();

	// conditions check for bounds of map
	
	if(playerRow - 1 >= 0)
	{
		northValid = true;
	}
	if(playerCol - 1 >= 0)
	{
		westValid = true;
	}
	if(playerCol + 1 < cols)	
	{
		eastValid = true;
	}
	if(playerRow + 1 < rows)
	{
		southValid = true;
	}

	do
	{
		std::cout << "Enter your decision: ";
		char choice = getChar();
		std::cout << std::endl;

		switch(choice)				// if user choice is valid, moves character in that direction.  If not, alerts user and asks for different input
		{
			case 'N':
				if(northValid)
				{
					hero->move(Player::Direction::NORTH);
					std::cout << "Elena heads north." << std::endl;
					legal = true;
				}
				else
				{
					std::cout << "Elena cannot move there. Try again." << std::endl;
				}
				break;
			case 'W':
				if(westValid)
				{
					hero->move(Player::Direction::WEST);
					std::cout << "Elena heads west." << std::endl;
					legal = true;
				}
				else
				{
					std::cout << "Elena cannot move there. Try again." << std::endl;
				}
				break;
			case 'E':
				if(eastValid)
				{
					hero->move(Player::Direction::EAST);
					std::cout << "Elena heads east." << std::endl;
					legal = true;
				}
				else
				{
					std::cout << "Elena cannot move there. Try again." << std::endl;
				}
				break;
			case 'S':
				if(southValid)
				{
					hero->move(Player::Direction::SOUTH);
					std::cout << "Elena heads south." << std::endl;
					legal = true;
				}
				else
				{
					std::cout << "Elena cannot move there. Try again." << std::endl;
				}
				break;
			default:
				std::cout << "That is not a valid input. Try again." << std::endl;
		}

	} while(!legal);

	map[playerRow][playerCol]->setOccupied(false);	// removes player from original space			

	playerRow = hero->getRow();
	playerCol = hero->getCol();
	setPlayer(playerRow, playerCol);		// place player in new space

	linkMap();					// re-link map
	displayMap();					// display new map to user
}
