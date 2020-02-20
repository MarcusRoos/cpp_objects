//
// Created by Marcus Roos on 2020-02-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "FillArray.h"
#include "ArraySort.h"
#include "RandomGenerator.h"


using std::cout;
using std::endl;

    void FillFive() {
        const int five=5000;
        ArraySort a1(five);
        a1.setmaxSize(five);
        for (size_t i = 0; i < five; i++) {
            a1.addValue((RNG(five)));
        }
    }

    void FillTen() {
        const int ten=10000;
        ArraySort a1(ten);
        a1.setmaxSize(ten);
        for (size_t i = 0; i < ten; i++) {
            a1.addValue((RNG(ten)));
        }
    }

void FillFifteen() {
    const int fifteen=15000;
    ArraySort a1(fifteen);
    a1.setmaxSize(fifteen);
    for (size_t i = 0; i < fifteen; i++) {
        a1.addValue((RNG(fifteen)));
    }
}

void FillTwenty() {
    const int twenty=20000;
    ArraySort a1(twenty);
    a1.setmaxSize(twenty);
    for (size_t i = 0; i < twenty; i++) {
        a1.addValue((RNG(twenty)));
    }
}

void FillTwentyFive() {
    const int twentyfive=25000;
    ArraySort a1(twentyfive);
    a1.setmaxSize(twentyfive);
    for (size_t i = 0; i < twentyfive; i++) {
        a1.addValue((RNG(twentyfive)));
    }
}

void FillThirty() {
    const int thirty=30000;
    ArraySort a1(thirty);
    a1.setmaxSize(thirty);
    for (size_t i = 0; i < thirty; i++) {
        a1.addValue((RNG(thirty)));
    }
}

void FillThirtyFive() {
    const int thirtyfive=35000;
    ArraySort a1(thirtyfive);
    a1.setmaxSize(thirtyfive);
    for (size_t i = 0; i < thirtyfive; i++) {
        a1.addValue((RNG(thirtyfive)));
    }
}

void FillForty() {
    const int forty=40000;
    ArraySort a1(forty);
    a1.setmaxSize(forty);
    for (size_t i = 0; i < forty; i++) {
        a1.addValue((RNG(forty)));
    }
}
