/* File Name: Group2_Players.cpp
*    Authors: Johnson, Pelton, Simmons, Thompson
*	    Date: 02/21/2022
*  Rev. Date: 02/22/2022
*    Version: 0.5.3
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
        multimap<int, string, std::greater<int> > leaderboard;

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
            leaderboard.insert(make_pair(points, username));
        }
        
        void ResetPlayer()
        {
            username = "Player";
            points = 0;
        }

        void PrintLeaderboard()
        {
            short unsigned int i = 1;

            multimap<int, string>::iterator LeaderboardIterator = leaderboard.begin();

            cout << "--------Leaderboard--------" << endl;

            while (LeaderboardIterator != leaderboard.end())
            {
                //prints Top Ten Leaderboard             
                cout << i << " - " << LeaderboardIterator->second << ": ";
                cout << LeaderboardIterator->first << " Points" << endl;
                i++;
                LeaderboardIterator++;

                if (i == 11)
                {
                    break;
                }

            }
        }
};