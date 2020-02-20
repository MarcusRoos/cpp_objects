//
// Created by Marcus Roos on 2020-02-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "RandomGenerator.h"

static std::random_device random;
static std::mt19937 rng(random());

int RNG(int maxsize)
{
    static std::uniform_int_distribution<int> uid(0,maxsize-1); // random dice
    return uid(rng); // use rng as a generator
}