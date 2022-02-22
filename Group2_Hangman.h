#pragma once
/* File Name: Group2_Hangman.h
*    Authors: Johnson, Pelton, Simmons, Thompson
*       Date: 02/06/2022
*  Rev. Date: 02/21/2022
*    Version: 0.5.0
*/

//blueprints Hangman class
//ERROR: YouWin() procs trice, proccing the score.correctWord() twice, adding +10 instead of +5 for a correct word

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Group2_Scorekeeper.h"         /*includeed scorekeeper.h*/

using namespace std;

class Hangman
{
private:
	string word;
	int badGuesses;
	bool win = false;
	bool foundLetter;
	bool hintGiven = false;
	bool goodGuess = false;
	vector<char> wordVector;
	vector<char> guessedLetters;
	
	Scorekeeper score;

public:

	//constructor
	Hangman()
	{
		badGuesses = 0;
		foundLetter = false;

		wordVector.clear();
		guessedLetters.clear();
	}

	//--------METHODS--------
	 
	//resets values on game end
	void GameClear()
	{
		badGuesses = 0;
		hintGiven = false;

		wordVector.clear();
		guessedLetters.clear();

		score.clearScore();                               /*added the clearScore*/
	}

	void guess(char letter)
	{
		goodGuess = false;
		
		//Section checks if input letter has been guessed already
		if (!guessedLetters.empty())
		{
			for (unsigned int j = 0; j < (guessedLetters.size()); j++)
			{
				if (tolower(guessedLetters[j]) == tolower(letter))
				{
					cout << "\nYou already guessed " << letter << "!" << endl;
					return;
				}
			}
		}

		//Section checks if letter is correct guess or not
		for (unsigned int i = 0; i < (wordVector.size()); i++)
		{
			if (tolower(wordVector[i]) == tolower(letter) && goodGuess != true)
			{
				cout << "\nYes, this word contains a(n): " << letter << endl;
				goodGuess = true;
				guessedLetters.push_back(tolower(letter));
				score.correctLetter();                                     /*add +1 pt for each correct letter guess*/
			}
		}

		//On a bad guess, moves badGuesses closer to a losing position
		if (!goodGuess)
		{
			badGuesses += 1;
			cout << "\nSorry! Try another letter" << endl;
			guessedLetters.push_back(letter);
		}

		BuildASCIIMan();
		DisplayWordSpaces();
		DisplayGuessedLetters();
		YouLose();
		YouWin();
	}

	void DisplayWordSpaces()
	{
		bool foundLetter;
		cout << endl;
		cout << "\n\t\t\t\t\t\t\t\t";

		//Goes through wordVector one letter at a time
		for (unsigned int i = 0; i < wordVector.size(); i++)
		{
			foundLetter = false;

			//checks guessedLetters against the above letter
			for (unsigned int j = 0; j < guessedLetters.size(); j++)
			{
				if (tolower(guessedLetters[j]) == tolower(wordVector[i]))
				{
					//if match, print letter
					foundLetter = true;
					cout << wordVector[i];	
				}

				if ((j == guessedLetters.size() - 1) && !foundLetter)
				{
					//if no matches, print _
					cout << "_";
				}
			}

			if (i == wordVector.size() - 1)
			{
				//when done, print new line
				cout << endl;
			}
		}
	}

	//section displays each guessed letter
	void DisplayGuessedLetters()
	{
		cout << "\nGuessed Letters :";
		for (unsigned int j = 0; j < (guessedLetters.size()); j++)
		{
			cout << " " << guessedLetters[j];
		}
	}

	//Section displays the hangman character based on number of bad guesses
	void BuildASCIIMan()
	{
		switch (badGuesses)
		{
		case 1:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t            | \n";
			cout << "\t\t\t\t\t\t\t\t            | \n";
			break;

		case 2:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t      |     | \n";
			cout << "\t\t\t\t\t\t\t\t            | \n";
			break;

		case 3:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t     /|     | \n";
			cout << "\t\t\t\t\t\t\t\t            | \n";
			break;

		case 4:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t     /|\\    | \n";
			cout << "\t\t\t\t\t\t\t\t            | \n";
			break;

		case 5:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t     /|\\    | \n";
			cout << "\t\t\t\t\t\t\t\t     /      | \n";
			break;

		case 6:
			cout << "\n\t\t\t\t\t\t\t\t      _______  \n";
			cout << "\t\t\t\t\t\t\t\t      ;     | \n";
			cout << "\t\t\t\t\t\t\t\t      O     | \n";
			cout << "\t\t\t\t\t\t\t\t     /|\\    | \n";
			cout << "\t\t\t\t\t\t\t\t     / \\    | \n";
			break;

		default:
			break;
		}
	}

	void Hint()
	{
		//reset value
		foundLetter = false;
		char letter;

		do
		{
			for (unsigned int i = 0; i < wordVector.size(); i++)
			{
				foundLetter = false;
				//This will become the given hint, if not in guessedLetters
				letter = wordVector[i];

				for (unsigned int j = 0; j < guessedLetters.size(); j++)
				{
					if ((tolower(guessedLetters[j]) == tolower(letter)))
					{
						foundLetter = true;
						break;
					}
					else if (!foundLetter)
					{
						guessedLetters.push_back(tolower(letter));
						//flag to disable further hints and exit loop
						hintGiven = true;
						break;
					}
				}

				if (hintGiven)
				{
					break;
				}
			}
		} while (!hintGiven);
	}

	bool YouLose()
	{
		//Bad guesses cause a losing condition
		if (badGuesses < 6)
		{
			return true;
		}

		win = false;
		return false;
	}

	bool YouWin()
	{
		unsigned int points = 0;

		//Section compares each letter in wordVector to guessed letters
		for (char wordVectorItem : wordVector)
		{
			for (char guessedLettersItem : guessedLetters)
			{
				if (tolower(wordVectorItem) == tolower(guessedLettersItem))
				{
					//On match, add a point.
					points += 1;
				}
			}
		}

		//Get points equal to the length of wordVector to win
		if (points >= wordVector.size())
		{
			win = true;
			return true;
		}

		return false;
	}

	//destructor
	~Hangman()
	{
		//empty
	}

	//setter
	void SetHangmanWord(string _word)
	{
		word = _word;
		copy(word.begin(), word.end(), back_inserter(wordVector));
	}

	//getters
	string GetHangmanWord()
	{
		return word;
	}

	bool GetWin()
	{
		return win;
	}

	int GetBadGuesses()
	{
		return badGuesses;
	}

	bool GetHintGiven()
	{
		return hintGiven;
	}

	void gameWin()                                   /*added methods to call upon winning or losing*/
	{
		score.correctWord();
		cout << "\n\n\nWINNER! Good Job!" << endl;
		cout << "Score: " << score.outputScore() << endl;
	}

	void gameLose()
	{
		cout << "\n\nSorry! The word was: " << GetHangmanWord() << endl;
		cout << "\nScore: " << score.outputScore() << endl;
		cout << "\nBetter luck next time!" << endl;
	}

	short int gameTotalScore()                         /*added method to output Scorekeeper*/
	{
		short int result = score.outputScore();
		return result;
	}
};
