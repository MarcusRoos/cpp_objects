#include <iostream>
#include "ArraySort.h"
#include "sort.h"
#include "RandomGenerator.h"

using std::cout;
using std::endl;

void assignmentFunction() {
    cout << "DT019G Laboration 4!" << endl;
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
    twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;


    ArraySort a1(five);
    for(int i=0; i < five; i++)
        a1.addValue(RNG((five)));

}
