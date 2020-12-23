/*********************
* Program: Recursion - Lab 4
* Author: Michael Ton
* Date: 10/27/18
* Description: This is the header file for the Menu class, which will be used for a variety of assignments in CS162 that require a menu in the program. This is a "bare-bones" version that will require additions and adjustments in the future to create a robust Menu class. 
**********************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

class Menu
{
	private:
		std::vector<std::string> programMenu; //vector containing string elements that hold menu prompts
		int menuOptions;

	public:
		Menu();

		void display();
		void display(int);
		//void printBorder();
		
		void addString(std::string);
		void deleteString(int);
		void deleteAll();
		void editString(int, std::string);
};
#endif
