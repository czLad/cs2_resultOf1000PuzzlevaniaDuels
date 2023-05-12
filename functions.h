//
// Created by myatz on 3/18/2023.
//

#ifndef CH5PROGRAMMINGPROJECT6_FUNCTIONS_H
#define CH5PROGRAMMINGPROJECT6_FUNCTIONS_H
#include <iostream>
#include <fstream>

void resultOf1000PuzzlevaniaDuels();
std::string startDuel();
void aaronSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive);
void bobSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive);
void charlieSTurn(bool &aaronAlive, bool &bobAlive, bool &charlieAlive);
int numberOfContestantsAlive(bool &aaronAlive,bool &bobAlive,bool &charlieAlive);
std::string findWinner(bool &aaronAlive,bool &bobAlive,bool &charlieAlive);
void shoot(bool &targetAlive, double accuracy);

void output(std::string message);
#endif //CH5PROGRAMMINGPROJECT6_FUNCTIONS_H
