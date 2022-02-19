#pragma once
/* File Name: Group2_ReadFile.h
*    Authors: Johnson, Pelton, Simmons, Thompson
*       Date: 02/03/2022
*  Rev. Date: 02/10/2022
*    Version: 0.4.3
*/

//blueprints ReadFileToArray class
//COMPLETE: TEMPORARILY change vector to list
//ERROR: if there is [spacebar] in file, reads the [spacebars] as part of the word

#include <fstream>
#include <vector>
#include <list>

class ReadFileToArray
{
private:
	//std::vector<std::string> strArray;
	std::list<std::string> strArray;

public:
	ReadFileToArray()
	{
		//default constructor, no paramater
		std::string strLine;
		std::ifstream txtFile;

		txtFile.open("Group2_TxtFile.txt");

		if (txtFile.is_open())
		{
			while (getline(txtFile, strLine))
			{
				unsigned short int index = 0;

				//trim strLine of whitespace at start
				//strLine.erase(std::remove(strLine.begin(), strLine.end(), ' '), strLine.end());

				strArray.push_back(strLine);
				
				++index;
			}
		}
		txtFile.close();
	}

	~ReadFileToArray()
	{
		//destructor
	}

	//outputs one line of vector
	std::string outputLineOfFile(int x)
	{
		//std::string line = strArray[x];

		std::list<std::string>::iterator it = strArray.begin();
		for (int i = 0; i < x; i++) {
			++it;
		}

		std::string line = *it;

		return line;
	}
	
	//outputs whole vector
	std::list<std::string> outputReadFileToArray()
	{
		return strArray;
	}

};