#include "Prototypes.h"
#include "ArraySort.h"
#include <iostream>
#include <random>
#include <chrono>
#include <functional>

using std::cout;
using std::endl;

void assignmentFunction() {
    ArraySort arraySort;
    const int five=5000, ten=10000, fifteen=15000, twenty=20000,
    twentyfive=25000, thirty=30000, thirtyfive=35000, fourty=40000;

    const size_t MAX_SIZE = five;
    ArraySort a1(MAX_SIZE);
    arraySort.setmaxSize(MAX_SIZE);

    std::mt19937::result_type seed = time(0);
    auto real_rand = bind(std::uniform_real_distribution<double>
            (0,MAX_SIZE-1), std::mt19937(seed));

    for (int i=0; i < MAX_SIZE; i++)
    {
        cout << " Nr " << i + 1 << ": " ;
        a1.addValue(seed);
    }
    cout << "DT019G Laboration 4!" << endl;
}
