/***************************************************
 * Program: CS 162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 11/24/18
 * Description: Header file for Space class. The map is made from a 2D array of Space pointers. Space class contains Space pointers that point to surrounding spaces. Space is an abstract class.
 ***************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "character.hpp"

#include <string>

enum SpaceType {BATTLE, SEARCH, FREE};			// enum used for Space type
enum Position {TOP, LEFT, RIGHT, BOTTOM};		// enum used for initializing pointers in Space object

class Space
{
	protected:
		Space* top = nullptr;
		Space* left = nullptr;
		Space* right = nullptr;
		Space* bottom = nullptr;

		SpaceType type;
		bool discovered = false;
		bool occupied = false;
	
	public:
		Space();
		virtual ~Space() = 0;

		void setDiscovered(bool);
		void setOccupied(bool);
		char getType();
		
		void link(Position, Space*);
		virtual void action(Character*) = 0;		// to be overridden by derived classes	

		void displayHeader();
		void test();
};
#endif

