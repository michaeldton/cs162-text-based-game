/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Header file for Player, which inherits Character. Handles all information relevant only to player character, such as current location (enemies in game do not move).
 ***************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "character.hpp"
#include "free.hpp"
#include "item.hpp"

class Player : public Character
{
	private:
		int playerRow, playerCol;

	public:
		Player(std::string, int, int, int, int);

		enum Direction {NORTH, WEST, EAST, SOUTH};		// public enum for player direction so Game class can move accordingly using enum

		void setCoordinates(int, int);
		int getRow();
		int getCol();

		void move(Direction);
};
#endif
