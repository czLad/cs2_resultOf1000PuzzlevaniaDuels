//
// Created by myatz on 3/18/2023.
//

#include "test.h"
#include "functions.h"
void shootDriver()
{
    bool targetAlive = true;
    double accuracy = 1.0;
    shoot(targetAlive, accuracy);
    if(targetAlive)
    {
        output("Miss\n");
    }
    else
    {
        output("Hit\n");
    }
}
void findWinnerDriver()
{
    std::string winner;
    bool aaronAlive = false, bobAlive = true, charlieAlive = false;
    winner = findWinner(aaronAlive, bobAlive, charlieAlive);
    output(winner);
}
void numberOfContestantsAliveDriver()
{
    int contestants;
    bool aaronAlive = true, bobAlive = true, charlieAlive = false;
    contestants = numberOfContestantsAlive(aaronAlive, bobAlive, charlieAlive);
    output(std::to_string(contestants));
}
void charlieSTurnDriver()
{
    bool aaronAlive = true, bobAlive = true, charlieAlive = true;
    charlieSTurn(aaronAlive, bobAlive, charlieAlive);
    if(bobAlive)
    {
        output("Missed Bob\n");
    }
    else
    {
        output("Bob Hit\n");
    }
    if(aaronAlive)
    {
        output("Missed Aaron\n");
    }
    else
    {
        output("Aaron Hit\n");
    }
    if(!charlieAlive)
    {
        output("Charlie is dead\n");
    }
}
void startDuelDriver()
{
    std::string winner;
    winner = startDuel();
    output(winner);
}
