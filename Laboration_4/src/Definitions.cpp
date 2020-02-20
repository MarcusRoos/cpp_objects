#include "Prototypes.h"
#include "ArraySort.h"
#include "RandomGenerator.h"
#include <iostream>

using std::cout;
using std::endl;

void assignmentFunction() {
    ArraySort arraySort;
    const int five=5000, ten=10000, fifteen=15000, twenty=20000,
    twentyfive=25000, thirty=30000, thirtyfive=35000, fourty=40000;

    const size_t MAX_SIZE = fourty;
    ArraySort a1(MAX_SIZE);
    arraySort.setmaxSize(MAX_SIZE);

    for (int i=0; i < MAX_SIZE; i++) {
        a1.addValue((RNG(MAX_SIZE)));
        cout << "Num" << i << ": "<< RNG(MAX_SIZE) << endl;
    }
    //for (int k=0; k<MAX_SIZE; k++)

    cout << "DT019G Laboration 4!" << endl;
}
