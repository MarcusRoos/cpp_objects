#include "Prototypes.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

int main() {
    assignmentFunction();

    // Example usage of <chrono>
    auto timeStart = std::chrono::high_resolution_clock::now();
    std::cout << "Tryck ENTER!!" << std::endl;
    std::string s;
    while(!getline(std::cin, s)) {}        // wait for the user to press ENTER
    auto timeEnd = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(6);

    // calculate duration by subtracting start time from end time
    size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
    double seconds = 1.0 * duration / 1000;

    std::cout << "Duration = "
         << seconds
         << " [s]" <<  std::endl;

    return 0;
}
