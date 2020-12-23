/***************************************************
 * Program: CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Implementation file for Space.
 ***************************************************/

#include "space.hpp"
#include <iostream>

Space::Space(){}

Space::~Space(){}

/***************************************************
 * Get/Set methods for Space class
 ***************************************************/

void Space::setDiscovered(bool discovered)
{
	this->discovered = discovered;
}

void Space::setOccupied(bool occupied)
{
	this->occupied = occupied;
}

char Space::getType()					// return character based on Space type
{
	char typeName;
	
	switch(type)
	{
	 	case BATTLE:
			typeName = 'B';
			break;
		case SEARCH:
			typeName = 'S';
			break;
		case FREE:
			typeName = ' ';
			break;
		default:
			typeName = ' ';
			break;
	}

	if(occupied)					// if Space is occupied, then player is located there; returns '#' representing player instead
	{
		return '#';
	}

	else
	{
		return typeName;
	}
}

/***************************************************
 * Other methods for Space class
 ***************************************************/

void Space::link(Position position, Space* space)	// initialize pointers to other Space objects surrounding this Space
{
	switch(position)
	{
		case TOP:
			top = space;
			break;
		case LEFT:
			left = space;
			break;
		case RIGHT: 
			right = space;
			break;
		case BOTTOM:
			bottom = space;
			break;
	}
}

/***************************************************
 * Test/debug methods for Space class
 ***************************************************/

void Space::test()	// function tests that all spaces have been initialized and linked - there are no 'empty' spaces as all non-randomized spaces are set to FREE type and no statement printed if space is edge
{
	if(top != nullptr)
	{
		std::cout << getType() << " top initialized" << std::endl;
	}
	if(left != nullptr)
	{
		std::cout << getType() << " left initialized" << std::endl;
	}
	if(right != nullptr)
	{
		std::cout << getType() << " right initialized" << std::endl;
	}
	if(bottom != nullptr)
	{
		std::cout << getType() << " bottom initialized" << std::endl;
	}
}
