//
// Created by myatz on 3/18/2023.
//

#include "functions.h"
void resultOf1000PuzzlevaniaDuels()
{
    int aaronWins = 0, bobWins = 0, charlieWins = 0;
    std::string winner, winnerName;
    std::ofstream fout;
    std::ifstream fin;

    fout.open("duelResults.txt");
    if(fout.fail())
        exit(1);
    for(int i = 0; i < 1000; i++)
    {
        winner = startDuel();
        fout << winner << "\n";
    }
    fout.close();
    fin.open("duelResults.txt");
    if(fin.fail())
        exit(2);
    while(fin >> winnerName)
    {
        if(winnerName == "AaronWins")
        {
            aaronWins ++;
        }
        else if(winnerName == "BobWins")
        {
            bobWins ++;
        }
        else
        {
            charlieWins ++;
        }
    }
    output(std::to_string(aaronWins) + " out of 1000 duels, Aaron Wins\n");
    output(std::to_string(bobWins) + " out of 1000 duels, Bob Wins\n");
    output(std::to_string(charlieWins) + " out of 1000 duels, Charlie Wins\n");
}
std::string startDuel()
{
    std::string winner;
    int contestants = 3, round = 0;
    bool aaronAlive = true, bobAlive = true, charlieAlive = true;
    while(contestants > 1)
    {
        round ++;
        if(round == 1)
        {
            bobSTurn(aaronAlive, bobAlive, charlieAlive);
            charlieSTurn(aaronAlive, bobAlive, charlieAlive);
            contestants = numberOfContestantsAlive(aaronAlive, bobAlive, charlieAlive);
        }
        else
        {
            aaronSTurn(aaronAlive, bobAlive, charlieAlive);
            bobSTurn(aaronAlive, bobAlive, charlieAlive);
            charlieSTurn(aaronAlive, bobAlive, charlieAlive);
            contestants = numberOfContestantsAlive(aaronAlive, bobAlive, charlieAlive);
        }
    }
    winner = findWinner(aaronAlive, bobAlive, charlieAlive);
    return winner;
}
void aaronSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive) /**if the contestant is alive, the strategic shoot
 * is carried out, if not, the contestant's turn is skipped.
 */
{
    if(aaronAlive)
    {
        double aaronSAccuracy = 1.0 / 3.0;
        if(charlieAlive)
        {
            shoot(charlieAlive, aaronSAccuracy);
        }
        else
        {
            shoot(bobAlive, aaronSAccuracy);
        }
    }
}
void bobSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive)
{
    if (bobAlive)
    {
        double bobSAccuracy = 1.0 / 2.0;
        if (charlieAlive)
        {
            shoot(charlieAlive, bobSAccuracy);
        }
        else
        {
            shoot(aaronAlive, bobSAccuracy);
        }
    }
}
void charlieSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive)
{
    if(charlieAlive)
    {
        double charlieSAccuracy = 1.0;
        if(bobAlive)
        {
            shoot(bobAlive, charlieSAccuracy);
        }
        else
        {
            shoot(aaronAlive, charlieSAccuracy);
        }
    }
}
int numberOfContestantsAlive(bool &aaronAlive,bool &bobAlive,bool &charlieAlive)
{
    int numberOfContestants = 0;
    if(aaronAlive && bobAlive && charlieAlive)
    {
        numberOfContestants = 3;
    }
    else if(aaronAlive && bobAlive)
    {
        numberOfContestants = 2;
    }
    else if(aaronAlive && charlieAlive)
    {
        numberOfContestants = 2;
    }
    else if(bobAlive && charlieAlive)
    {
        numberOfContestants = 2;
    }
    else if(aaronAlive || bobAlive || charlieAlive)
    {
        numberOfContestants = 1;
    }
    return numberOfContestants;
}
std::string findWinner(bool &aaronAlive,bool &bobAlive,bool &charlieAlive)
{
    if(aaronAlive)
    {
        return "AaronWins";
    }
    if(bobAlive)
    {
        return "BobWins";
    }
    if(charlieAlive)
    {
        return "CharlieWins";
    }
}
void shoot(bool &targetAlive, double accuracy)
{
    if((rand() % 2) < accuracy)
    {
        targetAlive = false;
    }
}

void output(std::string message)
{
    std::cout << message;
}