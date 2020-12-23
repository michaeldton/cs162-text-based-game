/***************************
* Author: Michael Ton
* Date: 10/27/18
* Description: 
****************************/
#include "Utility.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cctype>

int getInteger() //validate integer input that does not require checking of bounds, converting string input into interger if input is valid
{
	std::string userInput;
	bool valid = false;
	
	while(!valid) 
	{
		getline(std::cin, userInput);

		if(!isOnlyDigits(userInput) || !isInRange(userInput) || userInput.find('.') != std::string::npos || userInput.find(" ") != std::string::npos || userInput.at(0) == '0')
		{
			std::cout << "Invalid input. You entered '" << userInput << "'. Please try again." << std::endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}

	return stoi(userInput, nullptr, 10);	
}

int getInteger(int min, int max) //validate user input that requires checking for min/max bounds, converting string input into intger if input is valid
{
	std::string userInput;
	bool valid = false;
	
	while(!valid) 
	{
		getline(std::cin, userInput);

		if(!isOnlyDigits(userInput) || !isInRange(userInput, min, max) || userInput.find('.') != std::string::npos || userInput.find(" ") != std::string::npos || userInput.at(0) == '0')
		{
			std::cout << "Invalid input. You entered '" << userInput << "'. Please try again." << std::endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}
	
	return stoi(userInput, nullptr, 10);	
}

char getChar()
{
	std::string input;
	getline(std::cin, input);
	
	while(input.length() != 1)
	{
		std::cout << "That is not a valid input. Try again." << std::endl;
		getline(std::cin, input);
	}
	
	char tempChar = toupper(input[0]);

	return tempChar;
}

bool isInRange(std::string userInput) //checks user input with stoi, if error message is received, then returns false
{
	try
	{
		stoi(userInput, nullptr, 10);
	}
	catch(std::out_of_range& e)
	{
		return false;
	}
	catch(std::invalid_argument& e)
	{
		return false;
	}

	return true;
}

bool isInRange(std::string userInput, int min, int max) //checks user input with stoi, if error message is received, then returns false - accounts for bounds
{
	try
	{
		stoi(userInput, nullptr, 10);
	}
	catch(std::out_of_range& e)
	{
		return false;
	}
	catch(std::invalid_argument& e)
	{
		return false;
	}

	if(stoi(userInput, nullptr, 10) < min || stoi(userInput, nullptr, 10) > max)
	{
		return false;
	}

	return true;
}

bool isOnlyDigits(std::string userInput) //returns true if string input contains only digits
{
	bool isOnlyDigits = true;
	int length = userInput.length();
	
	for(int i = 0; i < length; i++)
	{
		if(!isdigit(userInput[i]))
		{	
			isOnlyDigits = false;
		}
	}

	return isOnlyDigits;
}

