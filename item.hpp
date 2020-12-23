/***************************************************
 * Program: Final Project - CS162 - 'Till the End of Time
 * Author: Michael Ton
 * Date: 12/1/18
 * Description: Header file for Item class. Handles type and name of Item object. This class is rather simple, intended to be expanded upon in the future.
 ***************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

enum ItemType {FRAGMENT, BRACE};		// game consists of two types: FRAGMENT and BRACE

class Item
{
	protected:
		std::string itemName = "";
		ItemType type;

	public:
		Item(ItemType);

		std::string getItemName();
};
#endif
