/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Header file for Game class. Game class contains functions and member variables to run the game until a victory or defeat condition is achieved.
 ***************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "battle.hpp"
#include "free.hpp"
#include "search.hpp"
#include "player.hpp"
#include "fallen.hpp"

class Game
{
	private:
		Space*** map;			// 2D array of Space type pointers to create map
		Player* hero = nullptr;		
		Fallen* fallen1 = nullptr;
		Fallen* fallen2 = nullptr;
		Fallen* fallen3 = nullptr;
		Menu victoryScreen;
		Menu deathScreen;
		Menu defeatScreen;

		int rows, cols, turnLimit;
		bool win = false;		
		bool death = false;

	public:
		Game(int, int, int);		// constructor initializes with integer values for map size and turn limit
		~Game();

		void run();			
		void createMap();
		void linkMap();			// ensures that all Space pointers are correctly linked despite changes to game state
		void displayMap();

		void setPlayer(int, int);	// set player starting position
		void movePlayer();		
		void getPlayerInfo();
		void doEvent();			// activates the event contained in each Space
};
#endif
