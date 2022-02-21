/* File Name: Group2_Main.cpp
*    Authors: Johnson, Pelton, Simmons, Thompson
*	    Date: 01/30/2022
*  Rev. Date: 02/21/2022
*    Version: 0.5.2
*/

//POSSIBLE: convert all arrays to vectors

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include "Group2_ArrayBuilder.h"
#include "Group2_ReadFile.h"
#include "Group2_Hangman.h"
#include "Group2_Players.cpp"

using namespace std;

int main(int argc, char* argv[])
{

	//declaring variables
	bool mainMenu = true;
	bool optionMenu = true;
	bool exitHangman = false;
	string versionNumber = "0.5.2";
	string input;
	unsigned short int choice = 0;
	short int option;
	ArrayBuilder arrayClass;
	ReadFileToArray txtFile;
	string word;
	Hangman game;
	string userName;
	Player player; 
	 

	//command line argument handling
	//cout << "--------Command Line Arguments--------" << endl;
	//cout << "Number of Arguments " << argc << endl;

	//Checks for the information command line argument
	if ((argc > 1) && (string)argv[1] == "-i")
	{
		cout << "\n\nArray Assignment";
		cout << "\nVersion " + versionNumber;
		cout << "\nCreated by Johnson, Pelton, Simmons, and Thompson\n\n";
	}

	if (argc <= 13)
	{
		//transferring argv[] to array from ArrayBuilder class
		cout << "Transferring Arguments to New List . . ." << endl;

		for (unsigned short int i = 0; i < (argc - 1); i++) {
			string temp = string(argv[i + 1]);
			
			//ignores the -i command
			if (temp != "-i")
			{
				arrayClass.SetArrayBuilderValue(temp, i);
			}
		}
		cout << "Transfer Complete" << endl;
	}


	//commands and options, until exit (-e) is selected
	do
	{
		//commands main menu
		cout << "\n--------Commands:--------\n";
		cout << "Information:     -i" << endl;
		cout << "Options:         -o" << endl;
		cout << "Exit:            -e" << endl;

		cin >> input;
		if (input == "-i")
		{
			//information command
			cout << "\n--------Information:--------\n";                                                /*updated description*/
			cout << "Program Name:       Array Builder\n";
			cout << "Authors:            Johnson, Pelton, Simmons, Thompson\n";
			cout << "Description:        Initially creates an array from command line arguments.\n";
			cout << "                    Offers the user options to manipulate, update, or view the array.\n";
			cout << "                    Offers the user an option to play Hangman with a selected word.\n";
			cout << "Version:            " + versionNumber << endl;
		}
		else if (input == "-o")
		{
			do
			{
				//options command; options sub-menu
				cout << "\n--------Options:--------\n";
				cout << "1 - Update List with Console\n";
				cout << "2 - Update List with Text File\n";
				cout << "3 - Display a Word\n";
				cout << "4 - Update One Word\n";
				cout << "5 - Print List\n";
				cout << "6 - Guess the Letters (Hangman!)\n";
				cout << "7 - View Leaderboard\n";
				cout << "8 - Return to Commands\n";

				cin >> input;
				//testing if input is an integer
				try
				{
					choice = stoi(input);
					//doesn't catch #aaaa
				}
				catch (...)
				{
					choice = 0;
				}

				//case switch with program options
				switch (choice)
				{
				case 1:
					//enter new words for entire list with console
					for (unsigned short int i = 0; i < 12; i++)
					{
						cout << "\nInput word for #" << i + 1 << "\n";
						cin >> input;
						arrayClass.SetArrayBuilderValue(input, i);
					}
					cout << "List Updated\n";

					break;

				case 2:
					//overwrite list with txt file
					cout << "\nOverwriting List with Text File . . .\n";

					for (unsigned short int i = 0; i < 12; i++)
					{
						string temp = txtFile.outputLineOfFile(i);
						arrayClass.SetArrayBuilderValue(temp, i);
					}
					cout << "\nOverwrite Complete\n";

					break;

				case 3:
					//displays single word
					cout << "\nWhich word would you like to display? Input a number 1 to 12:\n";
					cin >> input;

					//checks if input is an integer
					try
					{
						option = stoi(input);
						//doesn't catch #aaaa
					}
					catch (...)
					{
						cout << "\nIncorrect input. Default option selected: 1\n";
						option = 1;
					}

					//checks if option is between 1 and 12
					if ((option >= 1) && (option <= 12))
					{
						cout << arrayClass.GetArrayBuilderValue(option - 1) << endl;
					}
					else
					{
						cout << "\nIncorrect input. Default option selected: 1\n";
						cout << arrayClass.GetArrayBuilderValue(0) << endl;
					}
					option = -1;
					break;

				case 4:
					//update one word
					cout << "\nWhich word to update? Input a number 1 to 12:\n";
					cin >> input;

					//checks if input is an integer
					try
					{
						option = stoi(input);
						//doesn't catch #aaaa
					}
					catch (...)
					{
						cout << "\nIncorrect input. Default option selected: 1\n";
						option = 1;
					}

					//checks if option is between 1 and 12
					if ((option >= 1) && (option <= 12))
					{
						//continue
					}
					else
					{
						cout << "\nIncorrect input. Default option selected: 1\n";
						option = 1;
					}

					cout << "\nEnter a word:\n";
					cin >> input;
					arrayClass.SetArrayBuilderValue(input, option - 1);
					cout << "\nList Updated\n";

					break;

				case 5:
					//prints list
					cout << "\nPrinting List:\n" << endl;
					arrayClass.printArrayBuilder();
					break;

				case 6:
					//Hangman
					cout << "Please enter your name: ";
					cin >> userName;
					player.SetPlayerName(userName);
					cout << "Welcome " << player.GetPlayerName() << "! ";

					//player continuously plays game until exit
					do
					{
						//Guess the Letters (Hangman)
						cout << "\nPlease pick a number from 1 to 12: ";
						cin >> input;

						//checks if input is an integer
						try
						{
							option = stoi(input);
							//doesn't catch #aaaa
						}
						catch (...)
						{
							cout << "\nIncorrect input. Default option selected: 1\n";
							option = 1;
						}

						//Selects word to play Hangman with
						if ((option >= 1) && (option <= 12))
						{
							word = arrayClass.GetArrayBuilderValue(option - 1);
						}
						else
						{
							cout << "\nIncorrect input. Default option selected: 1\n";
							word = arrayClass.GetArrayBuilderValue(0);
						}
						//Resets option value
						option = -1;

						cout << "\nHangman!\n";
						cout << player.GetPlayerName()<< ", " << "input a single letter as a guess when prompted, and try not to get too many wrong guesses!\n\n";
						game.SetHangmanWord(word);

						do
						{
							if (game.GetBadGuesses() > 3 && game.GetHintGiven() == false)
							{
								cout << "\nNeed a hint? Y/N" << endl;
								cin >> input;

								bool hintYN = false;
								do
								{
									if (input == "Y" || input == "y")
									{
										game.Hint();
										cout << "\nHere's a free letter " << player.GetPlayerName() << "! \nYou only get one, so guess wisely...\n\n" << endl;
										game.DisplayWordSpaces();
										hintYN = true;
									}
									else if (input == "N" || input == "n")
									{
										cout << "\nOkay, no hint yet!" << endl;
										hintYN = true;
									}
									else
									{
										cout << "\nIncorrect Input" << endl;
										cout << "\nNeed a hint? Y/N" << endl;
										cin >> input;
									}
								} while (!hintYN);
							}

							cout << "\nGuess a letter!" << endl;
							cin >> input;
							//Only grabs first letter of input
							game.Guess(input[0]);
						} while (!game.YouWin() && game.YouLose());

						if (game.GetWin())
						{
							cout << "\n\n\nWINNER! Good job " << userName << "!\n\n" << endl;
							cout << "Points Earned: " << game.GetPoints() << endl;
							player.SetPoints(game.GetPoints());
							cout << "Total Points Earned: " << player.GetPoints() << endl;
							game.GameClear();
							cout << "Would you like to play another round " << player.GetPlayerName() << "? (Y/N): ";
							cin >> input;
							if (input == "Y" || input == "y")
							{
								
							}
							else if (input == "N" || input == "n")
							{
								exitHangman = true;
							}
							
							else
							{
								cout << "\nIncorrect Input" << endl;
								cout << "\nWould you like to play another round " << player.GetPlayerName() << "? (Y/N): ";
								cin >> input;
							}
						}
						else
						{
							cout << "\nSorry " << userName << "! The word was: " << game.GetHangmanWord() << endl;
							cout << "Better luck next time!" << endl;
							cout << "Points Earned: " << game.GetPoints() << endl;
							player.SetPoints(game.GetPoints());
							cout << "Total Points Earned: " << player.GetPoints() << endl;
							game.GameClear();
							cout << "Would you like to play another round " << player.GetPlayerName() << "? (Y/N): ";
							cin >> input;
							if (input == "Y" || input == "y")
							{
								cout << "Okay, let's play again!" << endl << endl;
							}
							else if (input == "N" || input == "n")
							{
								cout << "Thanks for playing " << player.GetPlayerName() << "!" << endl << endl;
								exitHangman = true;
							}
							
							else
							{
								cout << "\nIncorrect Input" << endl;
								cout << "\nWould you like to play another round " << player.GetPlayerName() << "? (Y/N): ";
								cin >> input;
							}
						}
					} while (!exitHangman);
					exitHangman = false;
					cout << "Thanks for playing " << player.GetPlayerName() << "!" << endl << endl;
					player.UpdateLeaderboard();
					player.ResetPlayer();
					break;
				case 7:
					PrintLeaderboard();
					break;
				case 8:
					//exits program
					cout << "\nExiting Options . . ." << endl;
					optionMenu = false;
					break;

				default:
					cout << "\nInvalid Input." << endl;
					break;
				}
			} while (optionMenu);
		}
		else if (input == "-e")
		{
			//exit command
			cout << "\nExiting Program . . ." << endl;
			mainMenu = false;
		}
		else
		{
			cout << "Invalid input." << endl << endl;
		}
	} while (mainMenu);


	return 0;
}