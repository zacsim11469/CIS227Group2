#pragma once
/* File Name: Group2_ArrayBuilder.h
*    Authors: Johnson, Pelton, Simmons, Thompson
*       Date: 01/30/2022
*  Rev. Date: 02/08/2022
*    Version: 0.4.3
*/

//blueprints ArrayBuilder class
//POSSIBLE: convert to using vector (instead of array)

class ArrayBuilder
{
private:
	std::string strArray[12];

public:
	ArrayBuilder()
	{
		//constructor
		for (unsigned short int i = 0; i < 12; i++)
		{
			strArray[i] = "placeholder" + std::to_string(i + 1);
		}
	}
	~ArrayBuilder()
	{
		//destructor
	}
	void SetArrayBuilderValue(std::string& str, int x)
	{
		//setter
		strArray[x] = str;
	}
	std::string GetArrayBuilderValue(int x)
	{
		//getter
		return strArray[x];
	}

	void printArrayBuilder()
	{
		for (unsigned short int i = 0; i < 12; i++)
		{
			std::cout << strArray[i] << std::endl;
		}
	}
};