//
// Created by Marcus Roos on 2020-02-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "RandomGenerator.h"
/**
 * Random generator function, decided to put it in its own source file so its
 * easy to import for any further tasks. Will be called every time a random
 * generation needs to be done, requires an integer as input to determine
 * interval to generate from, will return a random generated integer.
 * **/
std::random_device random;
std::mt19937 rng(random());
int RNG(int maxsize)
{
    std::uniform_int_distribution<int> uid(0,maxsize-1); // random dice
    return uid(rng); // use rng as a generator
}