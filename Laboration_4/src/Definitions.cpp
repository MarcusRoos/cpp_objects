#include <iostream>
#include "ArraySort.h"
#include "Prototypes.h"
#include "RandomGenerator.h"

using std::cout;
using std::endl;

void assignmentFunction(int a) {

    ArraySort a1(a);
    for(int i=0; i < a; i++) {
        int x = RNG(a);
        a1.addValue(x);
    }

   // a1.bubbleSort1(a1[4].getValue(), five);

}

