/***************************
* Author: Michael Ton
* Date: 10/27/18
* Description: 
****************************/
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>

int getInteger(); 			//integer validation without limitations
int getInteger(int, int); 		//parameters that set min/max bounds to check input
char getChar();
bool isInRange(std::string); 		//handle errors involving bounds of integer type
bool isInRange(std::string, int, int);  //handle errors involving bounds of integer type accounting for min/max 
bool isOnlyDigits(std::string); 	//return true if input contains only numbers (0-9)

#endif
