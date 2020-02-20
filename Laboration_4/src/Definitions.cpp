#include <iostream>
#include "ArraySort.h"
#include "Prototypes.h"
#include "RandomGenerator.h"
#include <chrono>

using std::cout;
using std::endl;

void assignmentFunction(int a) {

    ArraySort a1(a);
    for(int i=0; i < a; i++) {
        int x = RNG(a);
        a1.addValue(x);
    }
    std::cout << "Measuring ten times." << std::endl;

    double average = 0;
    auto timeStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        std::cout << std::fixed << std::setprecision(6);
        auto timeEnd = std::chrono::high_resolution_clock::now();
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                timeEnd - timeStart).count();
        double seconds = 1.0 * duration / 1000;
        average += seconds;
        std::cout << "Duration = "
                  << seconds
                  << " [s]" << ", test number " << i + 1 << "/10"
                  << std::endl;
    }
    double time = average / 10;
    std::cout << "\n" << "Average time = " << time << "[s]\n";


    cout << "SIZE: " << a1.getSize();
   cout << " TIME: " << a1.getValue(5);


}

