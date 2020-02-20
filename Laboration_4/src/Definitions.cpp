#include <iostream>
#include "ArraySort.h"
#include "RandomGenerator.h"
#include <chrono>
#include <ostream>
#include <fstream>

using namespace std;

void assignmentFunction(int a, int b) {
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
        if(b==0)
            a1.insertSort(a);
        if (b==1)
            a1.q1(a);
        if(b==2)
            a1.bubbleSort1(a);
        if(b==3)
            a1.selectSort(a);
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


    ofstream outFile;
    string writeFile = ("Output.txt");

    outFile.open(writeFile, ios::app);
    if(b==0) {
        a1.insertSort(a);
        outFile << "insertionsort";
    }
    if (b==1) {
        a1.q1(a);
        outFile << "quicksort";
    }
    if(b==2) {
        a1.bubbleSort1(a);
        outFile << "bubblesort";
    }
    if(b==3) {
        a1.selectSort(a);
        outFile << "selectsort";
    }

    outFile << a1.getSize();
    outFile << time << "\n";
    outFile.close();
}
/*
a1.bubbleSort1(a);
a1.selectSort(a);
a1.insertSort(a);
a1.q1(a);
 */
/*
 OUTPUT SAVED FOR NOW
         string file = "Output";
        ofstream outFile;
        string writeFile = (file+".txt");

        outFile.open(writeFile, ios::app);
                outFile << "Method";
                outFile << a;
                outFile << seconds << "\n";
            outFile.close();
*/

