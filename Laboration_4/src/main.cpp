#include "Prototypes.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
            twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;
    size_t size=0;

    for (size_t k=0; k<8; k++) {
        if (k==0)
            size = five;
        if (k==1)
            size = ten;
        if (k==2)
            size = fifteen;
        if (k==3)
            size = twenty;
        if (k==4)
            size = twentyfive;
        if (k==5)
            size = thirty;
        if (k==6)
            size = thirtyfive;
        if (k==7)
            size = forty;
        assignmentFunction(size);
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
    }

    return 0;
}

int sum(ArraySort const &a)
{
    int s = 0;
    for(size_t i=0; i < a.getSize(); i++) s+= a.getValue(i);
    return s;
}