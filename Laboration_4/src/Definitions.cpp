#include <iostream>
#include "ArraySort.h"
#include "Prototypes.h"
#include "RandomGenerator.h"

using std::cout;
using std::endl;

void assignmentFunction() {
    cout << "DT019G Laboration 4!" << endl;
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
    twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;

    ArraySort a1(five);
    for(int i=0; i < five; i++) {
        int x = RNG(five);
        a1.addValue(x);
    }
    cout << endl << "TEST:" << a1.getSize() << endl;
    for(size_t i=0; i<a1.getSize(); i++)
        cout << endl << "TEST:" << a1.getValue(i) << endl;

    cout << endl << "NY:" << a1.getValue(0) << endl;
    cout << endl << "FEMTUS:" << a1.getValue(4999) << endl;

    //a1.bubbleSort1(a1.getValue(5), five);

    cout << "TEST: " << sum(a1);
}

