/* File Name: Group2_Players.cpp
*    Authors: Johnson, Pelton, Simmons, Thompson
*	    Date: 02/19/2022
*    Version: 0.5.2
*/

#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class Player
{
    private:
        string username;
        unsigned short int points;
        multimap<string, int> leaderboard;

    public:

        //constructor
        Player()
        {
            username = "Player";
            points = 0;
        }

        //set and get username
        void SetPlayerName(string name)
        {
            username = name;
        }

        string GetPlayerName() {
            return username;
        }

        //set and get points
        void SetPoints(int value)
        {
            points += value;
        }

        unsigned short int GetPoints()
        {
            return points;
        }


        //-----LEADERBOARD METHODS-----
        void UpdateLeaderboard()
        {
            leaderboard.insert(make_pair(username, points));
        }
        
        void ResetPlayer()
        {
            username = "Player";
            points = 0;
        }

        void PrintLeaderboard()
        {
            short unsigned int num = -1;
            short unsigned int i = 1;

            multimap<string, int>::iterator LeaderboardIterator = leaderboard.begin();

            cout << "--------Leaderboard--------" << endl;

            while (LeaderboardIterator != leaderboard.end())
            {
                cout << i << " - " << LeaderboardIterator->first << ": ";
                cout << LeaderboardIterator->second << " Points" << endl;
                i++;
                LeaderboardIterator++;

                if (i == 10)
                {
                    break;
                }

            }
        }
};