#pragma once
/* File Name: Group2_Scorekeeper.h
*    Authors: Johnson, Pelton, Simmons, Thompson
*       Date: 02/18/2022
*  Rev. Date: 02/18/2022
*    Version: 0.5.0
*/

//blueprints Scorekeeper class
//(1) point per letter, (5) points per win

//#include if needed

class Scorekeeper
{
private:
	//variables
	short int score = 0;

public:
	Scorekeeper()
	{
		//default constructor, no paramater
	}

	~Scorekeeper()
	{
		//destructor
	}

	//--------METHODS--------

	void correctLetter()
	{
		score += 1;
	}
	
	void correctWord()
	{
		score += 5;
	}

	short int outputScore()
	{
		return score;
	}

	void clearScore()
	{
		score = 0;
	}

};