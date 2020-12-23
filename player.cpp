/***************************************************
 * Program: Final Project - CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file for Player.
 ***************************************************/

#include "player.hpp"

#include <iostream>

Player::Player(std::string name, int maxHealth, int atk, int def, int spd) : Character()	// constructor sets player name and starting stas
{
	this->name = name;
	this->maxHealth = maxHealth;
	health = maxHealth;
	this->atk = atk;
	this->def = def;
	this->spd = spd;
}

void Player::setCoordinates(int row, int col)		// set player location
{
	playerRow = row;
	playerCol = col;
}

int Player::getRow()
{
	return playerRow;
}

int Player::getCol()
{
	return playerCol;
}

void Player::move(Direction direction)			// set player new location based on Direction enum type passed as parameter
{
	switch(direction)
	{
		case NORTH: 
			playerRow--;
			break;
		case WEST:
			playerCol--;
			break;
		case EAST:
			playerCol++;
			break;
		case SOUTH:
			playerRow++;
			break;
	}
}
