/*********************
* Program: Recursion - Lab 4
* Author: Michael Ton
* Date: 10/27/18
* Description: This is the source file for the Menu class, which will be used for a variety of assignments in CS162 that require a menu in the program. This is a "bare-bones" version that will require additions and adjustments in the future to create a robust Menu class. 
**********************/

#include "menu.hpp"
#include <iostream>

Menu::Menu()
{
	menuOptions = 0;
}

void Menu::display() //displays menu to user using for-loop to print all necessary initial menu prompts, and prints a border above and below the display for easier reading on user end
{
	//printBorder();
	for(int i = 0; i < menuOptions; i++)
	{
		std::cout << programMenu.at(i) << std::endl;
	}
	//printBorder();
}

void Menu::display(int stringNum)
{
	int prompt = stringNum - 1;
	std::cout << programMenu.at(prompt) << std::endl;
}

/*
void Menu::printBorder()
{
	int numSymbol = 50;
	std::cout << std::string(numSymbol, '*') << std::endl;
}
*/

void Menu::addString(std::string str)
{
	programMenu.push_back(str); //vector::push_back adds string to element currently at the end of vector
	menuOptions++;
}

void Menu::deleteString(int number)
{
	programMenu.erase(programMenu.begin() + (number - 1));
	menuOptions--;
}

void Menu::deleteAll()
{
	programMenu.erase(programMenu.begin(), programMenu.begin() + menuOptions);
	menuOptions -= menuOptions;
}

void Menu::editString(int number, std::string str)
{
	programMenu.at(number - 1) = str;
}
