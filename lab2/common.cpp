// common.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Define an enumeration for the different array indices that are relevant to my program
//          Define an enumeration for the different success and failure values my program
//          Define functions (Usage Message, Lowercase)

#include "stdafx.h"
#include "common.h"

const int A_to_a = 32; // 'A'-'a'=32
					   /**
					   * Usage Message function
					   */
int UsageMessage(char * program_name, char * promote)
{
	cout << "Usage: " << program_name << " " << promote << endl;
	return WRONG_ARGUMENTS_NUMBER;
}

/**
* Function that takes a reference to a C++ style string
* and modifies that string so that all of the alphabetic characters in it become lowercase
*/
void LowerCase(string &temp)
{
	for (unsigned int i = 0;i < temp.length();i++)
	{
		if (temp[i] >= 'A'&&temp[i] <= 'Z')
		{
			temp[i] = temp[i] + A_to_a;
		}
	}
}